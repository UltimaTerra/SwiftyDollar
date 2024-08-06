//
// Copyright 2017 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "HdSt/extCompGpuComputationResource.h"
#include "Hd/tokens.h"
#include "HdSt/bufferArrayRange.h"
#include "HdSt/codeGen.h"
#include "HdSt/debugCodes.h"
#include "HdSt/glslProgram.h"

#include "Tf/hash.h"

PXR_NAMESPACE_OPEN_SCOPE

HdStExtCompGpuComputationResource::HdStExtCompGpuComputationResource(
    HdBufferSpecVector const &outputBufferSpecs,
    HdSt_ExtCompComputeShaderSharedPtr const &kernel,
    HdBufferArrayRangeSharedPtrVector const &inputs,
    HdStResourceRegistrySharedPtr const &registry)
    : _outputBufferSpecs(outputBufferSpecs),
      _kernel(kernel),
      _registry(registry),
      _shaderSourceHash(),
      _inputs(inputs),
      _computeProgram(),
      _resourceBinder()
{
}

static HdSt_CodeGen::ID _ComputeProgramHash(HdStShaderCodeSharedPtrVector const &shaders,
                                            const HdSt_ResourceBinder::MetaData *metaData)
{
  HdSt_CodeGen::ID hash = 0;
  return TfHash::Combine(hash, metaData->ComputeHash(), HdStShaderCode::ComputeHash(shaders));
}

bool HdStExtCompGpuComputationResource::_Resolve()
{
  HD_TRACE_FUNCTION();
  // Non-in-place sources should have been registered as resource registry
  // sources already and Resolved. They go to an internal buffer range that
  // was allocated in AllocateInternalRange
  HdBufferSpecVector inputBufferSpecs;
  for (HdBufferArrayRangeSharedPtr const &input : _inputs) {
    if (TF_VERIFY(input)) {
      input->GetBufferSpecs(&inputBufferSpecs);
    }
  }
  // Once we know the names and sizes of all outputs and inputs and the kernel
  // to use we can codeGen the compute shader to use.

  // We can shortcut the codegen by using a heuristic for determining that
  // the output source would be identical given a certain destination buffer
  // range.
  size_t shaderSourceHash = TfHash::Combine(
      _kernel->ComputeHash(), _outputBufferSpecs, inputBufferSpecs);

  // XXX we'll need to test for hash collisions as they could be fatal in the
  // case of shader sources. Adjust based on pref vs correctness needs.
  // The new specs and the old specs as well as the new vs old kernel
  // source should be compared for equality if that is the case.
  // if (_shaderSourceHash == shaderSourceHash) {
  //    -- if hash equal but not content equal resolve hash collision --
  //}

  // If the source hash mismatches the saved program from previous executions
  // we are going to have to recompile it here.
  // We save the kernel for future runs to not have to incur the
  // compilation cost each time.
  if (!_computeProgram || _shaderSourceHash != shaderSourceHash) {
    HdStShaderCodeSharedPtrVector shaders;
    shaders.push_back(_kernel);

    std::unique_ptr<HdSt_ResourceBinder::MetaData> metaData =
        std::make_unique<HdSt_ResourceBinder::MetaData>();

    // let resourcebinder resolve bindings and populate metadata
    // which is owned by codegen.
    _resourceBinder.ResolveComputeBindings(_outputBufferSpecs,
                                           inputBufferSpecs,
                                           shaders,
                                           metaData.get(),
                                           _registry->GetHgi()->GetCapabilities());

    HdStGLSLProgram::ID registryID = _ComputeProgramHash(shaders, metaData.get());
    {
      // ask registry to see if there's already compiled program
      HdInstance<HdStGLSLProgramSharedPtr> programInstance = _registry->RegisterGLSLProgram(
          registryID);

      if (programInstance.IsFirstInstance()) {
        TRACE_SCOPE("ExtComp Link");
        HdSt_CodeGen codeGen(shaders, std::move(metaData));
        TF_DEBUG(HDST_LOG_COMPUTE_SHADER_PROGRAM_MISSES)
            .Msg(
                "(MISS) First ext comp program instance for %s "
                "(hash = %zu)\n",
                _kernel->GetExtComputationId().GetText(),
                registryID);

        HdStGLSLProgramSharedPtr glslProgram = codeGen.CompileComputeProgram(_registry.get());
        if (!TF_VERIFY(glslProgram)) {
          return false;
        }

        if (!glslProgram->Link()) {
          std::string const &logString = glslProgram->GetProgram()->GetCompileErrors();
          TF_WARN("Failed to link compute shader: %s", logString.c_str());
          return false;
        }

        // store the program into the program registry.
        programInstance.SetValue(glslProgram);

        TF_DEBUG(HD_EXT_COMPUTATION_UPDATED)
            .Msg("Compiled and linked compute program for computation %s\n ",
                 _kernel->GetExtComputationId().GetText());
      }
      else {
        TF_DEBUG(HDST_LOG_COMPUTE_SHADER_PROGRAM_HITS)
            .Msg(
                "(HIT) Found ext comp program instance for %s "
                "(hash = %zu)\n",
                _kernel->GetExtComputationId().GetText(),
                registryID);
      }

      _computeProgram = programInstance.GetValue();
    }

    if (!TF_VERIFY(_computeProgram)) {
      return false;
    }

    _shaderSourceHash = shaderSourceHash;
  }
  return true;
}

PXR_NAMESPACE_CLOSE_SCOPE

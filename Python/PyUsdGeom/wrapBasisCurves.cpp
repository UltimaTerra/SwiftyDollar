//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "Usd/schemaBase.h"
#include "UsdGeom/basisCurves.h"

#include "Sdf/primSpec.h"

#include "Tf/pyContainerConversions.h"
#include "Tf/pyResultConversions.h"
#include "Tf/pyUtils.h"
#include "Tf/wrapTypeHelpers.h"
#include "Usd/pyConversions.h"

#include <boost/python.hpp>

#include <string>

using namespace boost::python;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

#define WRAP_CUSTOM template<class Cls> static void _CustomWrapCode(Cls &_class)

// fwd decl.
WRAP_CUSTOM;

static UsdAttribute _CreateTypeAttr(UsdGeomBasisCurves &self,
                                    object defaultVal,
                                    bool writeSparsely)
{
  return self.CreateTypeAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token),
                             writeSparsely);
}

static UsdAttribute _CreateBasisAttr(UsdGeomBasisCurves &self,
                                     object defaultVal,
                                     bool writeSparsely)
{
  return self.CreateBasisAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token),
                              writeSparsely);
}

static UsdAttribute _CreateWrapAttr(UsdGeomBasisCurves &self,
                                    object defaultVal,
                                    bool writeSparsely)
{
  return self.CreateWrapAttr(UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token),
                             writeSparsely);
}

static std::string _Repr(const UsdGeomBasisCurves &self)
{
  std::string primRepr = TfPyRepr(self.GetPrim());
  return TfStringPrintf("UsdGeom.BasisCurves(%s)", primRepr.c_str());
}

}  // anonymous namespace

void wrapUsdGeomBasisCurves()
{
  typedef UsdGeomBasisCurves This;

  class_<This, bases<UsdGeomCurves>> cls("BasisCurves");

  cls.def(init<UsdPrim>(arg("prim")))
      .def(init<UsdSchemaBase const &>(arg("schemaObj")))
      .def(TfTypePythonClass())

      .def("Get", &This::Get, (arg("stage"), arg("path")))
      .staticmethod("Get")

      .def("Define", &This::Define, (arg("stage"), arg("path")))
      .staticmethod("Define")

      .def("GetSchemaAttributeNames",
           &This::GetSchemaAttributeNames,
           arg("includeInherited") = true,
           return_value_policy<TfPySequenceToList>())
      .staticmethod("GetSchemaAttributeNames")

      .def("_GetStaticTfType",
           (TfType const &(*)())TfType::Find<This>,
           return_value_policy<return_by_value>())
      .staticmethod("_GetStaticTfType")

      .def(!self)

      .def("GetTypeAttr", &This::GetTypeAttr)
      .def("CreateTypeAttr",
           &_CreateTypeAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetBasisAttr", &This::GetBasisAttr)
      .def("CreateBasisAttr",
           &_CreateBasisAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("GetWrapAttr", &This::GetWrapAttr)
      .def("CreateWrapAttr",
           &_CreateWrapAttr,
           (arg("defaultValue") = object(), arg("writeSparsely") = false))

      .def("__repr__", ::_Repr);

  _CustomWrapCode(cls);
}

// ===================================================================== //
// Feel free to add custom code below this line, it will be preserved by
// the code generator.  The entry point for your custom code should look
// minimally like the following:
//
// WRAP_CUSTOM {
//     _class
//         .def("MyCustomMethod", ...)
//     ;
// }
//
// Of course any other ancillary or support code may be provided.
//
// Just remember to wrap code in the appropriate delimiters:
// 'namespace {', '}'.
//
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

namespace {

static TfToken _ComputeInterpolationForSize(const UsdGeomBasisCurves &curvesSchema,
                                            size_t n,
                                            const UsdTimeCode &timeCode)
{
  return curvesSchema.ComputeInterpolationForSize(n, timeCode, NULL);
}

WRAP_CUSTOM
{
  typedef UsdGeomBasisCurves This;

  _class.def("ComputeInterpolationForSize", _ComputeInterpolationForSize)
      .def("ComputeUniformDataSize", &This::ComputeUniformDataSize)
      .def("ComputeVaryingDataSize", &This::ComputeVaryingDataSize)
      .def("ComputeVertexDataSize", &This::ComputeVertexDataSize)
      .def("ComputeSegmentCounts", &This::ComputeSegmentCounts);
}

}  // anonymous namespace

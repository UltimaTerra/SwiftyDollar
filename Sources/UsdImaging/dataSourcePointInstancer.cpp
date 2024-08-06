//
// Copyright 2020 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "UsdImaging/dataSourcePointInstancer.h"

#include "UsdImaging/dataSourceAttribute.h"
#include "UsdImaging/dataSourcePrimvars.h"
#include "UsdImaging/dataSourceRelationship.h"
#include "UsdImaging/primvarUtils.h"

#include "Hd/retainedDataSource.h"
#include "Hd/tokens.h"

#include "Hd/instancerTopologySchema.h"
#include "Hd/mapContainerDataSource.h"
#include "Hd/overlayContainerDataSource.h"
#include "Hd/primvarSchema.h"
#include "Hd/primvarsSchema.h"

PXR_NAMESPACE_OPEN_SCOPE

namespace {

bool _IsConstantOrUniformPrimvar(HdPrimvarSchema schema)
{
  if (HdTokenDataSourceHandle const ds = schema.GetInterpolation()) {
    const TfToken interpolation = ds->GetTypedValue(0.0f);
    return interpolation == HdPrimvarSchemaTokens->constant ||
           interpolation == HdPrimvarSchemaTokens->uniform;
  }
  return false;
}

// Usd does not have "instance" as interpolation for primvars but that is
// what is needed for hydra. The USD spec also treats both constant and uniform
// as constant.
//
// The following data source is for locator primvars:FOO and forces the
// interpolation to be instanced unless it is uniform or constant.
//
class _PrimvarDataSource : public HdContainerDataSource {
 public:
  HD_DECLARE_DATASOURCE(_PrimvarDataSource);

  TfTokenVector GetNames() override
  {
    return _inputPrimvarDs->GetNames();
  }

  HdDataSourceBaseHandle Get(const TfToken &name) override
  {
    if (name == HdPrimvarSchemaTokens->interpolation) {
      if (_IsConstantOrUniformPrimvar(_inputPrimvarDs)) {
        static HdDataSourceBaseHandle const ds = HdRetainedTypedSampledDataSource<TfToken>::New(
            HdPrimvarSchemaTokens->constant);
        return ds;
      }
      else {
        static HdDataSourceBaseHandle const ds = HdRetainedTypedSampledDataSource<TfToken>::New(
            HdPrimvarSchemaTokens->instance);
        return ds;
      }
    }

    return _inputPrimvarDs->Get(name);
  }

 private:
  _PrimvarDataSource(HdContainerDataSourceHandle const &inputPrimvarDs)
      : _inputPrimvarDs(inputPrimvarDs)
  {
  }

  HdContainerDataSourceHandle const _inputPrimvarDs;
};

HdDataSourceBaseHandle _GetPrimvarDataSource(HdDataSourceBaseHandle const &ds)
{
  if (HdContainerDataSourceHandle const containerDs = HdContainerDataSource::Cast(ds)) {
    return _PrimvarDataSource::New(containerDs);
  }
  else {
    return nullptr;
  }
}

};  // namespace

// ----------------------------------------------------------------------------

UsdImagingDataSourcePointInstancerMask::UsdImagingDataSourcePointInstancerMask(
    const SdfPath &sceneIndexPath,
    const UsdGeomPointInstancer &usdPI,
    const UsdImagingDataSourceStageGlobals &stageGlobals)
    : _usdPI(usdPI), _stageGlobals(stageGlobals)
{
  if (UsdAttribute attr = usdPI.GetInvisibleIdsAttr()) {
    if (attr.ValueMightBeTimeVarying()) {
      static const HdDataSourceLocator locator =
          HdInstancerTopologySchema::GetDefaultLocator().Append(
              HdInstancerTopologySchemaTokens->mask);
      _stageGlobals.FlagAsTimeVarying(sceneIndexPath, locator);
    }
  }
}

VtValue UsdImagingDataSourcePointInstancerMask::GetValue(
    const HdSampledDataSource::Time shutterOffset)
{
  return VtValue(GetTypedValue(shutterOffset));
}

VtBoolArray UsdImagingDataSourcePointInstancerMask::GetTypedValue(
    HdSampledDataSource::Time shutterOffset)
{
  // XXX: Add PI visibility here: if the PI is invisible, treat it as
  // everything masked.

  const std::vector<bool> mask = _usdPI.ComputeMaskAtTime(_stageGlobals.GetTime());
  VtBoolArray result(mask.begin(), mask.end());
  return result;
}

bool UsdImagingDataSourcePointInstancerMask::GetContributingSampleTimesForInterval(
    HdSampledDataSource::Time startTime,
    HdSampledDataSource::Time endTime,
    std::vector<HdSampledDataSource::Time> *outSampleTimes)
{
  return false;
}

// ----------------------------------------------------------------------------

UsdImagingDataSourcePointInstancerTopology::UsdImagingDataSourcePointInstancerTopology(
    const SdfPath &sceneIndexPath,
    UsdGeomPointInstancer usdPI,
    const UsdImagingDataSourceStageGlobals &stageGlobals)
    : _sceneIndexPath(sceneIndexPath), _usdPI(usdPI), _stageGlobals(stageGlobals)
{
}

TfTokenVector UsdImagingDataSourcePointInstancerTopology::GetNames()
{
  return {
      HdInstancerTopologySchemaTokens->prototypes,
      HdInstancerTopologySchemaTokens->instanceIndices,
      HdInstancerTopologySchemaTokens->mask,
  };
}

static UsdImagingDataSourceCustomPrimvars::Mappings _Merge(
    const UsdImagingDataSourceCustomPrimvars::Mappings &a,
    const UsdImagingDataSourceCustomPrimvars::Mappings &b)
{
  UsdImagingDataSourceCustomPrimvars::Mappings result = a;
  for (const auto &mapping : b) {
    result.push_back(mapping);
  }
  return result;
}

const UsdImagingDataSourceCustomPrimvars::Mappings &_GetCustomPrimvarMappings(
    const UsdPrim &usdPrim)
{
  static const UsdImagingDataSourceCustomPrimvars::Mappings baseMappings = {
      {HdInstancerTokens->instanceTranslations,
       UsdGeomTokens->positions,
       HdPrimvarSchemaTokens->instance},
      {HdInstancerTokens->instanceScales, UsdGeomTokens->scales, HdPrimvarSchemaTokens->instance},
      {HdTokens->velocities, UsdGeomTokens->velocities, HdPrimvarSchemaTokens->instance},
      {HdTokens->accelerations, UsdGeomTokens->accelerations, HdPrimvarSchemaTokens->instance},
      {HdTokens->angularVelocities,
       UsdGeomTokens->angularVelocities,
       HdPrimvarSchemaTokens->instance}};

  TfToken usdOrientationsToken;
  UsdGeomPointInstancer instancer(usdPrim);
  if (instancer.UsesOrientationsf(&usdOrientationsToken)) {
    static const UsdImagingDataSourceCustomPrimvars::Mappings mappingsOrientationsf = _Merge(
        baseMappings,
        {{HdInstancerTokens->instanceRotations,
          UsdGeomTokens->orientationsf,
          HdPrimvarSchemaTokens->instance}});
    return mappingsOrientationsf;
  }
  else {
    static const UsdImagingDataSourceCustomPrimvars::Mappings mappingsOrientations = _Merge(
        baseMappings,
        {{HdInstancerTokens->instanceRotations,
          UsdGeomTokens->orientations,
          HdPrimvarSchemaTokens->instance}});
    return mappingsOrientations;
  }
}

HdDataSourceBaseHandle UsdImagingDataSourcePointInstancerTopology::Get(const TfToken &name)
{
  if (name == HdInstancerTopologySchemaTokens->prototypes) {
    return UsdImagingDataSourceRelationship::New(_usdPI.GetPrototypesRel(), _stageGlobals);
  }
  else if (name == HdInstancerTopologySchemaTokens->instanceIndices) {
    UsdAttribute attr = _usdPI.GetProtoIndicesAttr();
    if (!attr) {
      return nullptr;
    }

    if (attr.ValueMightBeTimeVarying()) {
      static const HdDataSourceLocator locator =
          HdInstancerTopologySchema::GetDefaultLocator().Append(
              HdInstancerTopologySchemaTokens->instanceIndices);
      _stageGlobals.FlagAsTimeVarying(_sceneIndexPath, locator);
    }

    VtIntArray protoIndices;
    attr.Get(&protoIndices, _stageGlobals.GetTime());

    // We need to flip the protoIndices: [0,1,0] -> 0: [0,2], 1: [1].
    std::vector<VtIntArray> instanceIndices;
    for (size_t i = 0; i < protoIndices.size(); ++i) {
      const int protoIndex = protoIndices[i];
      if (size_t(protoIndex) >= instanceIndices.size()) {
        instanceIndices.resize(protoIndex + 1);
      }
      instanceIndices[protoIndex].push_back(i);
    }

    std::vector<HdDataSourceBaseHandle> indicesVec;
    for (size_t i = 0; i < instanceIndices.size(); ++i) {
      indicesVec.push_back(
          HdRetainedTypedSampledDataSource<VtArray<int>>::New(instanceIndices[i]));
    }
    return HdRetainedSmallVectorDataSource::New(indicesVec.size(), indicesVec.data());
  }
  else if (name == HdInstancerTopologySchemaTokens->mask) {
    return UsdImagingDataSourcePointInstancerMask::New(_sceneIndexPath, _usdPI, _stageGlobals);
  }

  return nullptr;
}

// ----------------------------------------------------------------------------

UsdImagingDataSourcePointInstancerPrim::UsdImagingDataSourcePointInstancerPrim(
    const SdfPath &sceneIndexPath,
    UsdPrim usdPrim,
    const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourcePrim(sceneIndexPath, usdPrim, stageGlobals)
{
}

TfTokenVector UsdImagingDataSourcePointInstancerPrim::GetNames()
{
  TfTokenVector result = UsdImagingDataSourcePrim::GetNames();
  result.push_back(HdInstancerTopologySchema::GetSchemaToken());
  result.push_back(HdPrimvarsSchema::GetSchemaToken());
  return result;
}

HdDataSourceBaseHandle UsdImagingDataSourcePointInstancerPrim::Get(const TfToken &name)
{
  if (name == HdInstancerTopologySchema::GetSchemaToken()) {
    return UsdImagingDataSourcePointInstancerTopology::New(
        _GetSceneIndexPath(), UsdGeomPointInstancer(_GetUsdPrim()), _GetStageGlobals());
  }
  else if (name == HdPrimvarsSchema::GetSchemaToken()) {
    // Note that we are not yet handling velocities, accelerations
    // and angularVelocities.
    return HdOverlayContainerDataSource::New(
        HdMapContainerDataSource::New(
            _GetPrimvarDataSource,
            HdContainerDataSource::Cast(UsdImagingDataSourcePrim::Get(name))),
        UsdImagingDataSourceCustomPrimvars::New(_GetSceneIndexPath(),
                                                _GetUsdPrim(),
                                                _GetCustomPrimvarMappings(_GetUsdPrim()),
                                                _GetStageGlobals()));
  }
  else {
    return UsdImagingDataSourcePrim::Get(name);
  }
}

HdDataSourceLocatorSet UsdImagingDataSourcePointInstancerPrim::Invalidate(
    UsdPrim const &prim,
    const TfToken &subprim,
    const TfTokenVector &properties,
    const UsdImagingPropertyInvalidationType invalidationType)
{
  HdDataSourceLocatorSet locators = UsdImagingDataSourcePrim::Invalidate(
      prim, subprim, properties, invalidationType);

  if (subprim.IsEmpty()) {
    for (const TfToken &propertyName : properties) {

      if (propertyName == UsdGeomTokens->prototypes) {
        locators.insert(HdInstancerTopologySchema::GetDefaultLocator());
      }
      if (propertyName == UsdGeomTokens->protoIndices) {
        static const HdDataSourceLocator locator =
            HdInstancerTopologySchema::GetDefaultLocator().Append(
                HdInstancerTopologySchemaTokens->instanceIndices);
        locators.insert(locator);
      }
      // inactiveIds are metadata - changing those will cause a resync
      // of the prim, that is prim remove and add to the stage scene index.
      // So we do not need to deal with them here.
      if (propertyName == UsdGeomTokens->invisibleIds) {
        static const HdDataSourceLocator locator =
            HdInstancerTopologySchema::GetDefaultLocator().Append(
                HdInstancerTopologySchemaTokens->mask);
        locators.insert(locator);
      }
      // Need to invalidate both orientations tokens. One will be
      // invalidated via the call to Invalidate() for custom primvars
      // and the other is explicitly invalidated here.
      if (propertyName == UsdGeomTokens->orientations ||
          propertyName == UsdGeomTokens->orientationsf)
      {
        locators.insert(
            HdPrimvarsSchema::GetDefaultLocator().Append(HdInstancerTokens->instanceRotations));
      }
    }

    locators.insert(UsdImagingDataSourceCustomPrimvars::Invalidate(
        properties, _GetCustomPrimvarMappings(prim)));
  }

  return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

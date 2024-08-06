//
// Copyright 2017 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef PXR_USD_IMAGING_USD_IMAGING_LIGHT_FILTER_ADAPTER_H
#define PXR_USD_IMAGING_USD_IMAGING_LIGHT_FILTER_ADAPTER_H

/// \file usdImaging/lightFilterAdapter.h

#include "UsdImaging/api.h"
#include "UsdImaging/primAdapter.h"
#include "pxr/pxrns.h"

PXR_NAMESPACE_OPEN_SCOPE

class UsdPrim;

/// \class UsdImagingLightFilterAdapter
///
/// Base class for all light filters.
///
class UsdImagingLightFilterAdapter : public UsdImagingPrimAdapter {
 public:
  typedef UsdImagingPrimAdapter BaseAdapter;

  UsdImagingLightFilterAdapter() : UsdImagingPrimAdapter() {}

  USDIMAGING_API
  ~UsdImagingLightFilterAdapter() override;

  USDIMAGING_API
  SdfPath Populate(UsdPrim const &prim,
                   UsdImagingIndexProxy *index,
                   UsdImagingInstancerContext const *instancerContext = NULL) override;

  USDIMAGING_API
  bool IsSupported(UsdImagingIndexProxy const *index) const override;

  // ---------------------------------------------------------------------- //
  /// \name Parallel Setup and Resolve
  // ---------------------------------------------------------------------- //

  /// Thread Safe.
  USDIMAGING_API
  void TrackVariability(UsdPrim const &prim,
                        SdfPath const &cachePath,
                        HdDirtyBits *timeVaryingBits,
                        UsdImagingInstancerContext const *instancerContext = NULL) const override;

  /// Thread Safe.
  USDIMAGING_API
  void UpdateForTime(UsdPrim const &prim,
                     SdfPath const &cachePath,
                     UsdTimeCode time,
                     HdDirtyBits requestedBits,
                     UsdImagingInstancerContext const *instancerContext = NULL) const override;

  // ---------------------------------------------------------------------- //
  /// \name Change Processing
  // ---------------------------------------------------------------------- //

  /// Returns a bit mask of attributes to be udpated, or
  /// HdChangeTracker::AllDirty if the entire prim must be resynchronized.
  USDIMAGING_API
  HdDirtyBits ProcessPropertyChange(UsdPrim const &prim,
                                    SdfPath const &cachePath,
                                    TfToken const &propertyName) override;

  USDIMAGING_API
  void MarkDirty(UsdPrim const &prim,
                 SdfPath const &cachePath,
                 HdDirtyBits dirty,
                 UsdImagingIndexProxy *index) override;

  USDIMAGING_API
  void MarkTransformDirty(UsdPrim const &prim,
                          SdfPath const &cachePath,
                          UsdImagingIndexProxy *index) override;

  USDIMAGING_API
  void MarkVisibilityDirty(UsdPrim const &prim,
                           SdfPath const &cachePath,
                           UsdImagingIndexProxy *index) override;

  // ---------------------------------------------------------------------- //
  /// \name Utilities
  // ---------------------------------------------------------------------- //

  USDIMAGING_API
  VtValue GetMaterialResource(UsdPrim const &prim,
                              SdfPath const &cachePath,
                              UsdTimeCode time) const override;

  // ---------------------------------------------------------------------- //
  /// \name Scene Index Support
  // ---------------------------------------------------------------------- //

  USDIMAGING_API
  virtual TfTokenVector GetImagingSubprims(UsdPrim const &prim) override;

  USDIMAGING_API
  TfToken GetImagingSubprimType(UsdPrim const &prim, TfToken const &subprim) override;

  USDIMAGING_API
  HdContainerDataSourceHandle GetImagingSubprimData(
      UsdPrim const &prim,
      TfToken const &subprim,
      const UsdImagingDataSourceStageGlobals &stageGlobals) override;

  USDIMAGING_API
  HdDataSourceLocatorSet InvalidateImagingSubprim(
      UsdPrim const &prim,
      TfToken const &subprim,
      TfTokenVector const &properties,
      UsdImagingPropertyInvalidationType invalidationType) override;

 protected:
  USDIMAGING_API
  void _RemovePrim(SdfPath const &cachePath, UsdImagingIndexProxy *index) override;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_USD_IMAGING_USD_IMAGING_LIGHT_FILTER_ADAPTER_H

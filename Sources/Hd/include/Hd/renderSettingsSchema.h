//
// Copyright 2023 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdSchemaDefs.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#ifndef PXR_IMAGING_HD_RENDER_SETTINGS_SCHEMA_H
#define PXR_IMAGING_HD_RENDER_SETTINGS_SCHEMA_H

/// \file

#include "Hd/api.h"
#include "Hd/schemaTypeDefs.h"

#include "Hd/schema.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

// --(BEGIN CUSTOM CODE: Declares)--
// --(END CUSTOM CODE: Declares)--

#define HD_RENDER_SETTINGS_SCHEMA_TOKENS \
  (renderSettings)(namespacedSettings)( \
      active)(renderProducts)(includedPurposes)(materialBindingPurposes)(renderingColorSpace)(shutterInterval)

TF_DECLARE_PUBLIC_TOKENS(HdRenderSettingsSchemaTokens, HD_API, HD_RENDER_SETTINGS_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdRenderSettingsSchema : public HdSchema {
 public:
  /// \name Schema retrieval
  /// @{

  HdRenderSettingsSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  /// Retrieves a container data source with the schema's default name token
  /// "renderSettings" from the parent container and constructs a
  /// HdRenderSettingsSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdRenderSettingsSchema GetFromParent(
      const HdContainerDataSourceHandle &fromParentContainer);

  /// @}

  // --(BEGIN CUSTOM CODE: Schema Methods)--

  /// This locator is to pass along dirtying of the currentFrame locator
  /// on the Scene Globals Scene Index through the render Settings prim.
  HD_API
  static const HdDataSourceLocator &GetFrameLocator();

  // --(END CUSTOM CODE: Schema Methods)--

  /// \name Member accessor
  /// @{

  HD_API
  HdContainerDataSourceHandle GetNamespacedSettings() const;

  HD_API
  HdBoolDataSourceHandle GetActive() const;

  HD_API
  HdRenderProductVectorSchema GetRenderProducts() const;

  HD_API
  HdTokenArrayDataSourceHandle GetIncludedPurposes() const;

  HD_API
  HdTokenArrayDataSourceHandle GetMaterialBindingPurposes() const;

  HD_API
  HdTokenDataSourceHandle GetRenderingColorSpace() const;

  /// Frame-relative time interval representing the sampling window for data
  /// relevant to motion blur. Renderers can use this interval when querying
  /// time-sampled data (e.g., xforms, points, velocities, ...) to simulate
  /// motion blur effects. Note: This closely relates to the (frame-
  /// relative) shutter interval of a camera specified via shutter open and
  /// close times and is expected to span the union of the shutter intervals
  /// of cameras used in generating the render artifacts.
  HD_API
  HdVec2dDataSourceHandle GetShutterInterval() const;

  /// @}

  /// \name Schema location
  /// @{

  /// Returns a token where the container representing this schema is found in
  /// a container by default.
  HD_API
  static const TfToken &GetSchemaToken();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the container representing this schema is found by default.
  HD_API
  static const HdDataSourceLocator &GetDefaultLocator();

  /// @}

  /// \name Data source locators for members
  ///
  /// The following methods return an HdDataSourceLocator (relative to the
  /// prim-level data source) where the data source for a member can be found.
  ///
  /// This is often useful for checking intersection against the
  /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
  /// @{

  /// Prim-level relative data source locator to locate namespacedSettings.
  HD_API
  static const HdDataSourceLocator &GetNamespacedSettingsLocator();

  /// Prim-level relative data source locator to locate active.
  HD_API
  static const HdDataSourceLocator &GetActiveLocator();

  /// Prim-level relative data source locator to locate renderProducts.
  HD_API
  static const HdDataSourceLocator &GetRenderProductsLocator();

  /// Prim-level relative data source locator to locate includedPurposes.
  HD_API
  static const HdDataSourceLocator &GetIncludedPurposesLocator();

  /// Prim-level relative data source locator to locate materialBindingPurposes.
  HD_API
  static const HdDataSourceLocator &GetMaterialBindingPurposesLocator();

  /// Prim-level relative data source locator to locate renderingColorSpace.
  HD_API
  static const HdDataSourceLocator &GetRenderingColorSpaceLocator();

  /// Prim-level relative data source locator to locate shutterInterval.
  HD_API
  static const HdDataSourceLocator &GetShutterIntervalLocator();
  /// @}

  /// \name Schema construction
  /// @{

  /// \deprecated Use Builder instead.
  ///
  /// Builds a container data source which includes the provided child data
  /// sources. Parameters with nullptr values are excluded. This is a
  /// low-level interface. For cases in which it's desired to define
  /// the container with a sparse set of child fields, the Builder class
  /// is often more convenient and readable.
  HD_API
  static HdContainerDataSourceHandle BuildRetained(
      const HdContainerDataSourceHandle &namespacedSettings,
      const HdBoolDataSourceHandle &active,
      const HdVectorDataSourceHandle &renderProducts,
      const HdTokenArrayDataSourceHandle &includedPurposes,
      const HdTokenArrayDataSourceHandle &materialBindingPurposes,
      const HdTokenDataSourceHandle &renderingColorSpace,
      const HdVec2dDataSourceHandle &shutterInterval);

  /// \class HdRenderSettingsSchema::Builder
  ///
  /// Utility class for setting sparse sets of child data source fields to be
  /// filled as arguments into BuildRetained. Because all setter methods
  /// return a reference to the instance, this can be used in the "builder
  /// pattern" form.
  class Builder {
   public:
    HD_API
    Builder &SetNamespacedSettings(const HdContainerDataSourceHandle &namespacedSettings);
    HD_API
    Builder &SetActive(const HdBoolDataSourceHandle &active);
    HD_API
    Builder &SetRenderProducts(const HdVectorDataSourceHandle &renderProducts);
    HD_API
    Builder &SetIncludedPurposes(const HdTokenArrayDataSourceHandle &includedPurposes);
    HD_API
    Builder &SetMaterialBindingPurposes(
        const HdTokenArrayDataSourceHandle &materialBindingPurposes);
    HD_API
    Builder &SetRenderingColorSpace(const HdTokenDataSourceHandle &renderingColorSpace);
    HD_API
    Builder &SetShutterInterval(const HdVec2dDataSourceHandle &shutterInterval);

    /// Returns a container data source containing the members set thus far.
    HD_API
    HdContainerDataSourceHandle Build();

   private:
    HdContainerDataSourceHandle _namespacedSettings;
    HdBoolDataSourceHandle _active;
    HdVectorDataSourceHandle _renderProducts;
    HdTokenArrayDataSourceHandle _includedPurposes;
    HdTokenArrayDataSourceHandle _materialBindingPurposes;
    HdTokenDataSourceHandle _renderingColorSpace;
    HdVec2dDataSourceHandle _shutterInterval;
  };

  /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif

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

#ifndef PXR_IMAGING_HD_PRIM_ORIGIN_SCHEMA_H
#define PXR_IMAGING_HD_PRIM_ORIGIN_SCHEMA_H

/// \file

#include "Hd/api.h"

#include "Hd/schema.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

// --(BEGIN CUSTOM CODE: Declares)--
// --(END CUSTOM CODE: Declares)--

#define HD_PRIM_ORIGIN_SCHEMA_TOKENS (primOrigin)(scenePath)

TF_DECLARE_PUBLIC_TOKENS(HdPrimOriginSchemaTokens, HD_API, HD_PRIM_ORIGIN_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdPrimOriginSchema : public HdSchema {
 public:
  /// \name Schema retrieval
  /// @{

  HdPrimOriginSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  /// Retrieves a container data source with the schema's default name token
  /// "primOrigin" from the parent container and constructs a
  /// HdPrimOriginSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdPrimOriginSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

  /// @}

  // --(BEGIN CUSTOM CODE: Schema Methods)--
  /// Wraps an SdfPath so that it is not affected by the
  /// prefixing scene index.
  class OriginPath {
   public:
    OriginPath(const SdfPath &path) : _path(path) {}

    const SdfPath &GetPath() const
    {
      return _path;
    }

    bool operator==(const OriginPath &other) const
    {
      return _path == other._path;
    }

   private:
    HD_API
    friend std::ostream &operator<<(std::ostream &stream, OriginPath const &p);

    SdfPath _path;
  };

  using OriginPathDataSource = HdTypedSampledDataSource<OriginPath>;

  /// Extracts SdfPath from container that was added via
  /// OriginPathDataSource.
  HD_API SdfPath GetOriginPath(const TfToken &name) const;

  // --(END CUSTOM CODE: Schema Methods)--

  /// \name Member accessor
  /// @{

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

  /// Additional prim-level relative data source locator to locate
  /// scenePath.
  HD_API
  static const HdDataSourceLocator &GetScenePathLocator();
  /// @}

  /// \name Schema construction
  /// @{

  /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif

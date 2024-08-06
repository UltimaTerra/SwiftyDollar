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

#ifndef PXR_IMAGING_HD_MESH_SCHEMA_H
#define PXR_IMAGING_HD_MESH_SCHEMA_H

/// \file

#include "Hd/api.h"
#include "Hd/meshTopologySchema.h"
#include "Hd/subdivisionTagsSchema.h"

#include "Hd/schema.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

// --(BEGIN CUSTOM CODE: Declares)--
// --(END CUSTOM CODE: Declares)--

#define HD_MESH_SCHEMA_TOKENS (mesh)(topology)(subdivisionScheme)(subdivisionTags)(doubleSided)

TF_DECLARE_PUBLIC_TOKENS(HdMeshSchemaTokens, HD_API, HD_MESH_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdMeshSchema : public HdSchema {
 public:
  /// \name Schema retrieval
  /// @{

  HdMeshSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  /// Retrieves a container data source with the schema's default name token
  /// "mesh" from the parent container and constructs a
  /// HdMeshSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdMeshSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

  /// @}

  // --(BEGIN CUSTOM CODE: Schema Methods)--
  // --(END CUSTOM CODE: Schema Methods)--

  /// \name Member accessor
  /// @{

  HD_API
  HdMeshTopologySchema GetTopology() const;

  HD_API
  HdTokenDataSourceHandle GetSubdivisionScheme() const;

  HD_API
  HdSubdivisionTagsSchema GetSubdivisionTags() const;

  HD_API
  HdBoolDataSourceHandle GetDoubleSided() const;

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

  /// Prim-level relative data source locator to locate topology.
  HD_API
  static const HdDataSourceLocator &GetTopologyLocator();

  /// Prim-level relative data source locator to locate subdivisionScheme.
  HD_API
  static const HdDataSourceLocator &GetSubdivisionSchemeLocator();

  /// Prim-level relative data source locator to locate subdivisionTags.
  HD_API
  static const HdDataSourceLocator &GetSubdivisionTagsLocator();

  /// Prim-level relative data source locator to locate doubleSided.
  HD_API
  static const HdDataSourceLocator &GetDoubleSidedLocator();
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
      const HdContainerDataSourceHandle &topology,
      const HdTokenDataSourceHandle &subdivisionScheme,
      const HdContainerDataSourceHandle &subdivisionTags,
      const HdBoolDataSourceHandle &doubleSided);

  /// \class HdMeshSchema::Builder
  ///
  /// Utility class for setting sparse sets of child data source fields to be
  /// filled as arguments into BuildRetained. Because all setter methods
  /// return a reference to the instance, this can be used in the "builder
  /// pattern" form.
  class Builder {
   public:
    HD_API
    Builder &SetTopology(const HdContainerDataSourceHandle &topology);
    HD_API
    Builder &SetSubdivisionScheme(const HdTokenDataSourceHandle &subdivisionScheme);
    HD_API
    Builder &SetSubdivisionTags(const HdContainerDataSourceHandle &subdivisionTags);
    HD_API
    Builder &SetDoubleSided(const HdBoolDataSourceHandle &doubleSided);

    /// Returns a container data source containing the members set thus far.
    HD_API
    HdContainerDataSourceHandle Build();

   private:
    HdContainerDataSourceHandle _topology;
    HdTokenDataSourceHandle _subdivisionScheme;
    HdContainerDataSourceHandle _subdivisionTags;
    HdBoolDataSourceHandle _doubleSided;
  };

  /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif

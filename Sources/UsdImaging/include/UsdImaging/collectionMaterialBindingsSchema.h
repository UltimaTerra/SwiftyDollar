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

#ifndef PXR_USD_IMAGING_USD_IMAGING_COLLECTION_MATERIAL_BINDINGS_SCHEMA_H
#define PXR_USD_IMAGING_USD_IMAGING_COLLECTION_MATERIAL_BINDINGS_SCHEMA_H

/// \file

#include "UsdImaging/api.h"

#include "Hd/schema.h"

// --(BEGIN CUSTOM CODE: Includes)--

#include "Hd/vectorSchema.h"

// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

// --(BEGIN CUSTOM CODE: Declares)--

using UsdImagingCollectionMaterialBindingVectorSchema =
    HdSchemaBasedVectorSchema<class UsdImagingCollectionMaterialBindingSchema>;

// --(END CUSTOM CODE: Declares)--

#define USD_IMAGING_COLLECTION_MATERIAL_BINDINGS_SCHEMA_TOKENS \
  (collectionMaterialBindings)((allPurpose, ""))

TF_DECLARE_PUBLIC_TOKENS(UsdImagingCollectionMaterialBindingsSchemaTokens,
                         USDIMAGING_API,
                         USD_IMAGING_COLLECTION_MATERIAL_BINDINGS_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class UsdImagingCollectionMaterialBindingsSchema : public HdSchema {
 public:
  /// \name Schema retrieval
  /// @{

  UsdImagingCollectionMaterialBindingsSchema(HdContainerDataSourceHandle container)
      : HdSchema(container)
  {
  }

  /// Retrieves a container data source with the schema's default name token
  /// "collectionMaterialBindings" from the parent container and constructs a
  /// UsdImagingCollectionMaterialBindingsSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  USDIMAGING_API
  static UsdImagingCollectionMaterialBindingsSchema GetFromParent(
      const HdContainerDataSourceHandle &fromParentContainer);

  /// @}

  // --(BEGIN CUSTOM CODE: Schema Methods)--

  /// Returns the purposes for which bindings may be available.
  /// \note This API is preferable to schema.GetContainer()->GetNames().
  USDIMAGING_API
  TfTokenVector GetPurposes();

  /// Returns the bindings for 'allPurpose'.
  UsdImagingCollectionMaterialBindingVectorSchema GetCollectionMaterialBindings();

  /// Returns the bindings for the requested purpose.
  UsdImagingCollectionMaterialBindingVectorSchema GetCollectionMaterialBindings(
      const TfToken &purpose);

  // --(END CUSTOM CODE: Schema Methods)--

  /// \name Member accessor
  /// @{

  /// @}

  /// \name Schema location
  /// @{

  /// Returns a token where the container representing this schema is found in
  /// a container by default.
  USDIMAGING_API
  static const TfToken &GetSchemaToken();

  /// Returns an HdDataSourceLocator (relative to the prim-level data source)
  /// where the container representing this schema is found by default.
  USDIMAGING_API
  static const HdDataSourceLocator &GetDefaultLocator();

  /// @}

  /// \name Schema construction
  /// @{

  /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif

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

#ifndef PXR_IMAGING_HD_NURBS_PATCH_TRIM_CURVE_SCHEMA_H
#define PXR_IMAGING_HD_NURBS_PATCH_TRIM_CURVE_SCHEMA_H

/// \file

#include "Hd/api.h"

#include "Hd/schema.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

// --(BEGIN CUSTOM CODE: Declares)--
// --(END CUSTOM CODE: Declares)--

#define HD_NURBS_PATCH_TRIM_CURVE_SCHEMA_TOKENS \
  (trimCurve)(counts)(orders)(vertexCounts)(knots)(ranges)(points)

TF_DECLARE_PUBLIC_TOKENS(HdNurbsPatchTrimCurveSchemaTokens,
                         HD_API,
                         HD_NURBS_PATCH_TRIM_CURVE_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdNurbsPatchTrimCurveSchema : public HdSchema {
 public:
  /// \name Schema retrieval
  /// @{

  HdNurbsPatchTrimCurveSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

  /// Retrieves a container data source with the schema's default name token
  /// "trimCurve" from the parent container and constructs a
  /// HdNurbsPatchTrimCurveSchema instance.
  /// Because the requested container data source may not exist, the result
  /// should be checked with IsDefined() or a bool comparison before use.
  HD_API
  static HdNurbsPatchTrimCurveSchema GetFromParent(
      const HdContainerDataSourceHandle &fromParentContainer);

  /// @}

  // --(BEGIN CUSTOM CODE: Schema Methods)--
  // --(END CUSTOM CODE: Schema Methods)--

  /// \name Member accessor
  /// @{

  HD_API
  HdIntArrayDataSourceHandle GetCounts() const;

  HD_API
  HdIntArrayDataSourceHandle GetOrders() const;

  HD_API
  HdIntArrayDataSourceHandle GetVertexCounts() const;

  HD_API
  HdDoubleArrayDataSourceHandle GetKnots() const;

  HD_API
  HdVec2dArrayDataSourceHandle GetRanges() const;

  HD_API
  HdVec3dArrayDataSourceHandle GetPoints() const;

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
  static HdContainerDataSourceHandle BuildRetained(const HdIntArrayDataSourceHandle &counts,
                                                   const HdIntArrayDataSourceHandle &orders,
                                                   const HdIntArrayDataSourceHandle &vertexCounts,
                                                   const HdDoubleArrayDataSourceHandle &knots,
                                                   const HdVec2dArrayDataSourceHandle &ranges,
                                                   const HdVec3dArrayDataSourceHandle &points);

  /// \class HdNurbsPatchTrimCurveSchema::Builder
  ///
  /// Utility class for setting sparse sets of child data source fields to be
  /// filled as arguments into BuildRetained. Because all setter methods
  /// return a reference to the instance, this can be used in the "builder
  /// pattern" form.
  class Builder {
   public:
    HD_API
    Builder &SetCounts(const HdIntArrayDataSourceHandle &counts);
    HD_API
    Builder &SetOrders(const HdIntArrayDataSourceHandle &orders);
    HD_API
    Builder &SetVertexCounts(const HdIntArrayDataSourceHandle &vertexCounts);
    HD_API
    Builder &SetKnots(const HdDoubleArrayDataSourceHandle &knots);
    HD_API
    Builder &SetRanges(const HdVec2dArrayDataSourceHandle &ranges);
    HD_API
    Builder &SetPoints(const HdVec3dArrayDataSourceHandle &points);

    /// Returns a container data source containing the members set thus far.
    HD_API
    HdContainerDataSourceHandle Build();

   private:
    HdIntArrayDataSourceHandle _counts;
    HdIntArrayDataSourceHandle _orders;
    HdIntArrayDataSourceHandle _vertexCounts;
    HdDoubleArrayDataSourceHandle _knots;
    HdVec2dArrayDataSourceHandle _ranges;
    HdVec3dArrayDataSourceHandle _points;
  };

  /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif

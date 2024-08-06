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

#include "Hd/selectionSchema.h"

#include "Hd/retainedDataSource.h"

#include "Trace/traceImpl.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdSelectionSchemaTokens, HD_SELECTION_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdBoolDataSourceHandle HdSelectionSchema::GetFullySelected() const
{
  return _GetTypedDataSource<HdBoolDataSource>(HdSelectionSchemaTokens->fullySelected);
}

HdInstanceIndicesVectorSchema HdSelectionSchema::GetNestedInstanceIndices() const
{
  return HdInstanceIndicesVectorSchema(
      _GetTypedDataSource<HdVectorDataSource>(HdSelectionSchemaTokens->nestedInstanceIndices));
}

/*static*/
HdContainerDataSourceHandle HdSelectionSchema::BuildRetained(
    const HdBoolDataSourceHandle &fullySelected,
    const HdVectorDataSourceHandle &nestedInstanceIndices)
{
  TfToken _names[2];
  HdDataSourceBaseHandle _values[2];

  size_t _count = 0;

  if (fullySelected) {
    _names[_count] = HdSelectionSchemaTokens->fullySelected;
    _values[_count++] = fullySelected;
  }

  if (nestedInstanceIndices) {
    _names[_count] = HdSelectionSchemaTokens->nestedInstanceIndices;
    _values[_count++] = nestedInstanceIndices;
  }
  return HdRetainedContainerDataSource::New(_count, _names, _values);
}

HdSelectionSchema::Builder &HdSelectionSchema::Builder::SetFullySelected(
    const HdBoolDataSourceHandle &fullySelected)
{
  _fullySelected = fullySelected;
  return *this;
}

HdSelectionSchema::Builder &HdSelectionSchema::Builder::SetNestedInstanceIndices(
    const HdVectorDataSourceHandle &nestedInstanceIndices)
{
  _nestedInstanceIndices = nestedInstanceIndices;
  return *this;
}

HdContainerDataSourceHandle HdSelectionSchema::Builder::Build()
{
  return HdSelectionSchema::BuildRetained(_fullySelected, _nestedInstanceIndices);
}

PXR_NAMESPACE_CLOSE_SCOPE

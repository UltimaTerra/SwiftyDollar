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

#include "UsdImaging/modelSchema.h"

#include "Hd/retainedDataSource.h"

#include "Trace/traceImpl.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(UsdImagingModelSchemaTokens, USD_IMAGING_MODEL_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdPathDataSourceHandle UsdImagingModelSchema::GetModelPath() const
{
  return _GetTypedDataSource<HdPathDataSource>(UsdImagingModelSchemaTokens->modelPath);
}

HdAssetPathDataSourceHandle UsdImagingModelSchema::GetAssetIdentifier() const
{
  return _GetTypedDataSource<HdAssetPathDataSource>(UsdImagingModelSchemaTokens->assetIdentifier);
}

HdStringDataSourceHandle UsdImagingModelSchema::GetAssetName() const
{
  return _GetTypedDataSource<HdStringDataSource>(UsdImagingModelSchemaTokens->assetName);
}

HdStringDataSourceHandle UsdImagingModelSchema::GetAssetVersion() const
{
  return _GetTypedDataSource<HdStringDataSource>(UsdImagingModelSchemaTokens->assetVersion);
}

/*static*/
HdContainerDataSourceHandle UsdImagingModelSchema::BuildRetained(
    const HdPathDataSourceHandle &modelPath,
    const HdAssetPathDataSourceHandle &assetIdentifier,
    const HdStringDataSourceHandle &assetName,
    const HdStringDataSourceHandle &assetVersion)
{
  TfToken _names[4];
  HdDataSourceBaseHandle _values[4];

  size_t _count = 0;

  if (modelPath) {
    _names[_count] = UsdImagingModelSchemaTokens->modelPath;
    _values[_count++] = modelPath;
  }

  if (assetIdentifier) {
    _names[_count] = UsdImagingModelSchemaTokens->assetIdentifier;
    _values[_count++] = assetIdentifier;
  }

  if (assetName) {
    _names[_count] = UsdImagingModelSchemaTokens->assetName;
    _values[_count++] = assetName;
  }

  if (assetVersion) {
    _names[_count] = UsdImagingModelSchemaTokens->assetVersion;
    _values[_count++] = assetVersion;
  }
  return HdRetainedContainerDataSource::New(_count, _names, _values);
}

UsdImagingModelSchema::Builder &UsdImagingModelSchema::Builder::SetModelPath(
    const HdPathDataSourceHandle &modelPath)
{
  _modelPath = modelPath;
  return *this;
}

UsdImagingModelSchema::Builder &UsdImagingModelSchema::Builder::SetAssetIdentifier(
    const HdAssetPathDataSourceHandle &assetIdentifier)
{
  _assetIdentifier = assetIdentifier;
  return *this;
}

UsdImagingModelSchema::Builder &UsdImagingModelSchema::Builder::SetAssetName(
    const HdStringDataSourceHandle &assetName)
{
  _assetName = assetName;
  return *this;
}

UsdImagingModelSchema::Builder &UsdImagingModelSchema::Builder::SetAssetVersion(
    const HdStringDataSourceHandle &assetVersion)
{
  _assetVersion = assetVersion;
  return *this;
}

HdContainerDataSourceHandle UsdImagingModelSchema::Builder::Build()
{
  return UsdImagingModelSchema::BuildRetained(
      _modelPath, _assetIdentifier, _assetName, _assetVersion);
}

/*static*/
UsdImagingModelSchema UsdImagingModelSchema::GetFromParent(
    const HdContainerDataSourceHandle &fromParentContainer)
{
  return UsdImagingModelSchema(fromParentContainer ?
                                   HdContainerDataSource::Cast(fromParentContainer->Get(
                                       UsdImagingModelSchemaTokens->model)) :
                                   nullptr);
}

/*static*/
const TfToken &UsdImagingModelSchema::GetSchemaToken()
{
  return UsdImagingModelSchemaTokens->model;
}

/*static*/
const HdDataSourceLocator &UsdImagingModelSchema::GetDefaultLocator()
{
  static const HdDataSourceLocator locator(GetSchemaToken());
  return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE

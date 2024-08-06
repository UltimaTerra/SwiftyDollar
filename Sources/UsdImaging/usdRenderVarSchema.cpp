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

#include "UsdImaging/usdRenderVarSchema.h"

#include "Hd/retainedDataSource.h"

#include "Trace/traceImpl.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(UsdImagingUsdRenderVarSchemaTokens,
                        USD_IMAGING_USD_RENDER_VAR_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdTokenDataSourceHandle UsdImagingUsdRenderVarSchema::GetDataType() const
{
  return _GetTypedDataSource<HdTokenDataSource>(UsdImagingUsdRenderVarSchemaTokens->dataType);
}

HdStringDataSourceHandle UsdImagingUsdRenderVarSchema::GetSourceName() const
{
  return _GetTypedDataSource<HdStringDataSource>(UsdImagingUsdRenderVarSchemaTokens->sourceName);
}

HdTokenDataSourceHandle UsdImagingUsdRenderVarSchema::GetSourceType() const
{
  return _GetTypedDataSource<HdTokenDataSource>(UsdImagingUsdRenderVarSchemaTokens->sourceType);
}

HdContainerDataSourceHandle UsdImagingUsdRenderVarSchema::GetNamespacedSettings() const
{
  return _GetTypedDataSource<HdContainerDataSource>(
      UsdImagingUsdRenderVarSchemaTokens->namespacedSettings);
}

/*static*/
HdContainerDataSourceHandle UsdImagingUsdRenderVarSchema::BuildRetained(
    const HdTokenDataSourceHandle &dataType,
    const HdStringDataSourceHandle &sourceName,
    const HdTokenDataSourceHandle &sourceType,
    const HdContainerDataSourceHandle &namespacedSettings)
{
  TfToken _names[4];
  HdDataSourceBaseHandle _values[4];

  size_t _count = 0;

  if (dataType) {
    _names[_count] = UsdImagingUsdRenderVarSchemaTokens->dataType;
    _values[_count++] = dataType;
  }

  if (sourceName) {
    _names[_count] = UsdImagingUsdRenderVarSchemaTokens->sourceName;
    _values[_count++] = sourceName;
  }

  if (sourceType) {
    _names[_count] = UsdImagingUsdRenderVarSchemaTokens->sourceType;
    _values[_count++] = sourceType;
  }

  if (namespacedSettings) {
    _names[_count] = UsdImagingUsdRenderVarSchemaTokens->namespacedSettings;
    _values[_count++] = namespacedSettings;
  }
  return HdRetainedContainerDataSource::New(_count, _names, _values);
}

UsdImagingUsdRenderVarSchema::Builder &UsdImagingUsdRenderVarSchema::Builder::SetDataType(
    const HdTokenDataSourceHandle &dataType)
{
  _dataType = dataType;
  return *this;
}

UsdImagingUsdRenderVarSchema::Builder &UsdImagingUsdRenderVarSchema::Builder::SetSourceName(
    const HdStringDataSourceHandle &sourceName)
{
  _sourceName = sourceName;
  return *this;
}

UsdImagingUsdRenderVarSchema::Builder &UsdImagingUsdRenderVarSchema::Builder::SetSourceType(
    const HdTokenDataSourceHandle &sourceType)
{
  _sourceType = sourceType;
  return *this;
}

UsdImagingUsdRenderVarSchema::Builder &UsdImagingUsdRenderVarSchema::Builder::
    SetNamespacedSettings(const HdContainerDataSourceHandle &namespacedSettings)
{
  _namespacedSettings = namespacedSettings;
  return *this;
}

HdContainerDataSourceHandle UsdImagingUsdRenderVarSchema::Builder::Build()
{
  return UsdImagingUsdRenderVarSchema::BuildRetained(
      _dataType, _sourceName, _sourceType, _namespacedSettings);
}

/*static*/
UsdImagingUsdRenderVarSchema UsdImagingUsdRenderVarSchema::GetFromParent(
    const HdContainerDataSourceHandle &fromParentContainer)
{
  return UsdImagingUsdRenderVarSchema(
      fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                UsdImagingUsdRenderVarSchemaTokens->__usdRenderVar)) :
                            nullptr);
}

/*static*/
const TfToken &UsdImagingUsdRenderVarSchema::GetSchemaToken()
{
  return UsdImagingUsdRenderVarSchemaTokens->__usdRenderVar;
}

/*static*/
const HdDataSourceLocator &UsdImagingUsdRenderVarSchema::GetDefaultLocator()
{
  static const HdDataSourceLocator locator(GetSchemaToken());
  return locator;
}

/* static */
const HdDataSourceLocator &UsdImagingUsdRenderVarSchema::GetNamespacedSettingsLocator()
{
  static const HdDataSourceLocator locator = GetDefaultLocator().Append(
      UsdImagingUsdRenderVarSchemaTokens->namespacedSettings);
  return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE

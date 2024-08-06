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

#include "Hd/sphereSchema.h"

#include "Hd/retainedDataSource.h"

#include "Trace/traceImpl.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdSphereSchemaTokens, HD_SPHERE_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdDoubleDataSourceHandle HdSphereSchema::GetRadius() const
{
  return _GetTypedDataSource<HdDoubleDataSource>(HdSphereSchemaTokens->radius);
}

/*static*/
HdContainerDataSourceHandle HdSphereSchema::BuildRetained(const HdDoubleDataSourceHandle &radius)
{
  TfToken _names[1];
  HdDataSourceBaseHandle _values[1];

  size_t _count = 0;

  if (radius) {
    _names[_count] = HdSphereSchemaTokens->radius;
    _values[_count++] = radius;
  }
  return HdRetainedContainerDataSource::New(_count, _names, _values);
}

HdSphereSchema::Builder &HdSphereSchema::Builder::SetRadius(const HdDoubleDataSourceHandle &radius)
{
  _radius = radius;
  return *this;
}

HdContainerDataSourceHandle HdSphereSchema::Builder::Build()
{
  return HdSphereSchema::BuildRetained(_radius);
}

/*static*/
HdSphereSchema HdSphereSchema::GetFromParent(
    const HdContainerDataSourceHandle &fromParentContainer)
{
  return HdSphereSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                  HdSphereSchemaTokens->sphere)) :
                                              nullptr);
}

/*static*/
const TfToken &HdSphereSchema::GetSchemaToken()
{
  return HdSphereSchemaTokens->sphere;
}

/*static*/
const HdDataSourceLocator &HdSphereSchema::GetDefaultLocator()
{
  static const HdDataSourceLocator locator(GetSchemaToken());
  return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// vec.template.cpp file to make changes.

#include "Gf/vec4d.h"

#include "Gf/math.h"
#include "Gf/ostreamHelpers.h"
#include "Tf/type.h"
#include "pxr/pxrns.h"

// Include headers for other vec types to support wrapping conversions and
// operators.
#include "Gf/vec4f.h"
#include "Gf/vec4h.h"
#include "Gf/vec4i.h"

#include <ostream>
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType)
{
  TfType::Define<GfVec4d>();
}

std::ostream &operator<<(std::ostream &out, GfVec4d const &v)
{
  return out << '(' << Gf_OstreamHelperP(v[0]) << ", " << Gf_OstreamHelperP(v[1]) << ", "
             << Gf_OstreamHelperP(v[2]) << ", " << Gf_OstreamHelperP(v[3]) << ')';
}

bool GfVec4d::operator==(GfVec4f const &other) const
{
  return _data[0] == other[0] && _data[1] == other[1] && _data[2] == other[2] &&
         _data[3] == other[3];
}
bool GfVec4d::operator==(GfVec4h const &other) const
{
  return _data[0] == other[0] && _data[1] == other[1] && _data[2] == other[2] &&
         _data[3] == other[3];
}
bool GfVec4d::operator==(GfVec4i const &other) const
{
  return _data[0] == other[0] && _data[1] == other[1] && _data[2] == other[2] &&
         _data[3] == other[3];
}

PXR_NAMESPACE_CLOSE_SCOPE

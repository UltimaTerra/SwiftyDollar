//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// range.template.cpp file to make changes.

#include "Gf/range1f.h"
#include "Gf/range1d.h"

#include "Gf/math.h"
#include "Gf/ostreamHelpers.h"
#include "Tf/type.h"

#include <cfloat>
#include <ostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType)
{
  TfType::Define<GfRange1f>();
}

std::ostream &operator<<(std::ostream &out, GfRange1f const &r)
{
  return out << '[' << Gf_OstreamHelperP(r.GetMin()) << "..." << Gf_OstreamHelperP(r.GetMax())
             << ']';
}

GfRange1f::GfRange1f(class GfRange1d const &other)
    : _min(float(other.GetMin())), _max(float(other.GetMax()))
{
}

double GfRange1f::GetDistanceSquared(float p) const
{
  double dist = 0.0;

  if (p < _min) {
    // p is left of box
    dist += GfSqr(_min - p);
  }
  else if (p > _max) {
    // p is right of box
    dist += GfSqr(p - _max);
  }

  return dist;
}

PXR_NAMESPACE_CLOSE_SCOPE

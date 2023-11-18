//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// range.template.h file to make changes.

#ifndef PXR_BASE_GF_RANGE2D_H
#define PXR_BASE_GF_RANGE2D_H

/// \file gf/range2d.h
/// \ingroup group_gf_BasicGeometry

#include <pxr/pxrns.h>

#include "Gf/api.h"
#include "Gf/traits.h"
#include "Gf/vec2d.h"
#include "Gf/vec2f.h"
#include "Tf/hash.h"

#include <cfloat>
#include <cstddef>
#include <iosfwd>

PXR_NAMESPACE_OPEN_SCOPE

class GfRange2d;
class GfRange2f;

template <> struct GfIsGfRange<class GfRange2d> {
  static const bool value = true;
};

/// \class GfRange2d
/// \ingroup group_gf_BasicGeometry
///
/// Basic type: 2-dimensional floating point range.
///
/// This class represents a 2-dimensional range (or interval) All
/// operations are component-wise and conform to interval mathematics. An
/// empty range is one where max < min.
/// The default empty is [FLT_MAX,-FLT_MAX]
class GfRange2d {
public:
  /// Helper typedef.
  typedef GfVec2d MinMaxType;

  static const size_t dimension = GfVec2d::dimension;
  typedef GfVec2d::ScalarType ScalarType;

  /// Sets the range to an empty interval
  // TODO check whether this can be deprecated.
  void inline SetEmpty() {
    _min[0] = _min[1] = FLT_MAX;
    _max[0] = _max[1] = -FLT_MAX;
  }

  /// The default constructor creates an empty range.
  GfRange2d() { SetEmpty(); }

  /// This constructor initializes the minimum and maximum points.
  GfRange2d(const GfVec2d &min, const GfVec2d &max) : _min(min), _max(max) {}

  /// Implicitly convert from GfRange2f.
  GF_API
  GfRange2d(class GfRange2f const &other);

  /// Returns the minimum value of the range.
  const GfVec2d &GetMin() const { return _min; }

  /// Returns the maximum value of the range.
  const GfVec2d &GetMax() const { return _max; }

  /// Returns the size of the range.
  GfVec2d GetSize() const { return _max - _min; }

  /// Returns the midpoint of the range, that is, 0.5*(min+max).
  /// Note: this returns zero in the case of default-constructed ranges,
  /// or ranges set via SetEmpty().
  GfVec2d GetMidpoint() const {
    return static_cast<ScalarType>(0.5) * _min +
           static_cast<ScalarType>(0.5) * _max;
  }

  /// Sets the minimum value of the range.
  void SetMin(const GfVec2d &min) { _min = min; }

  /// Sets the maximum value of the range.
  void SetMax(const GfVec2d &max) { _max = max; }

  /// Returns whether the range is empty (max < min).
  bool IsEmpty() const { return _min[0] > _max[0] || _min[1] > _max[1]; }

  /// Modifies the range if necessary to surround the given value.
  /// \deprecated Use UnionWith() instead.
  void ExtendBy(const GfVec2d &point) { UnionWith(point); }

  /// Modifies the range if necessary to surround the given range.
  /// \deprecated Use UnionWith() instead.
  void ExtendBy(const GfRange2d &range) { UnionWith(range); }

  /// Returns true if the \p point is located inside the range. As with all
  /// operations of this type, the range is assumed to include its extrema.
  bool Contains(const GfVec2d &point) const {
    return (point[0] >= _min[0] && point[0] <= _max[0] && point[1] >= _min[1] &&
            point[1] <= _max[1]);
  }

  /// Returns true if the \p range is located entirely inside the range. As
  /// with all operations of this type, the ranges are assumed to include
  /// their extrema.
  bool Contains(const GfRange2d &range) const {
    return Contains(range._min) && Contains(range._max);
  }

  /// Returns true if the \p point is located inside the range. As with all
  /// operations of this type, the range is assumed to include its extrema.
  /// \deprecated Use Contains() instead.
  bool IsInside(const GfVec2d &point) const { return Contains(point); }

  /// Returns true if the \p range is located entirely inside the range. As
  /// with all operations of this type, the ranges are assumed to include
  /// their extrema.
  /// \deprecated Use Contains() instead.
  bool IsInside(const GfRange2d &range) const { return Contains(range); }

  /// Returns true if the \p range is located entirely outside the range. As
  /// with all operations of this type, the ranges are assumed to include
  /// their extrema.
  bool IsOutside(const GfRange2d &range) const {
    return ((range._max[0] < _min[0] || range._min[0] > _max[0]) ||
            (range._max[1] < _min[1] || range._min[1] > _max[1]));
  }

  /// Returns the smallest \c GfRange2d which contains both \p a and \p b.
  static GfRange2d GetUnion(const GfRange2d &a, const GfRange2d &b) {
    GfRange2d res = a;
    _FindMin(res._min, b._min);
    _FindMax(res._max, b._max);
    return res;
  }

  /// Extend \p this to include \p b.
  const GfRange2d &UnionWith(const GfRange2d &b) {
    _FindMin(_min, b._min);
    _FindMax(_max, b._max);
    return *this;
  }

  /// Extend \p this to include \p b.
  const GfRange2d &UnionWith(const GfVec2d &b) {
    _FindMin(_min, b);
    _FindMax(_max, b);
    return *this;
  }

  /// Returns the smallest \c GfRange2d which contains both \p a and \p b
  /// \deprecated Use GetUnion() instead.
  static GfRange2d Union(const GfRange2d &a, const GfRange2d &b) {
    return GetUnion(a, b);
  }

  /// Extend \p this to include \p b.
  /// \deprecated Use UnionWith() instead.
  const GfRange2d &Union(const GfRange2d &b) { return UnionWith(b); }

  /// Extend \p this to include \p b.
  /// \deprecated Use UnionWith() instead.
  const GfRange2d &Union(const GfVec2d &b) { return UnionWith(b); }

  /// Returns a \c GfRange2d that describes the intersection of \p a and \p b.
  static GfRange2d GetIntersection(const GfRange2d &a, const GfRange2d &b) {
    GfRange2d res = a;
    _FindMax(res._min, b._min);
    _FindMin(res._max, b._max);
    return res;
  }

  /// Returns a \c GfRange2d that describes the intersection of \p a and \p b.
  /// \deprecated Use GetIntersection() instead.
  static GfRange2d Intersection(const GfRange2d &a, const GfRange2d &b) {
    return GetIntersection(a, b);
  }

  /// Modifies this range to hold its intersection with \p b and returns the
  /// result
  const GfRange2d &IntersectWith(const GfRange2d &b) {
    _FindMax(_min, b._min);
    _FindMin(_max, b._max);
    return *this;
  }

  /// Modifies this range to hold its intersection with \p b and returns the
  /// result.
  /// \deprecated Use IntersectWith() instead.
  const GfRange2d &Intersection(const GfRange2d &b) { return IntersectWith(b); }

  /// unary sum.
  GfRange2d &operator+=(const GfRange2d &b) {
    _min += b._min;
    _max += b._max;
    return *this;
  }

  /// unary difference.
  GfRange2d &operator-=(const GfRange2d &b) {
    _min -= b._max;
    _max -= b._min;
    return *this;
  }

  /// unary multiply.
  GfRange2d &operator*=(double m) {
    if (m > 0) {
      _min *= m;
      _max *= m;
    } else {
      GfVec2d tmp = _min;
      _min = _max * m;
      _max = tmp * m;
    }
    return *this;
  }

  /// unary division.
  GfRange2d &operator/=(double m) { return *this *= (1.0 / m); }

  /// binary sum.
  GfRange2d operator+(const GfRange2d &b) const {
    return GfRange2d(_min + b._min, _max + b._max);
  }

  /// binary difference.
  GfRange2d operator-(const GfRange2d &b) const {
    return GfRange2d(_min - b._max, _max - b._min);
  }

  /// scalar multiply.
  friend GfRange2d operator*(double m, const GfRange2d &r) {
    return (m > 0 ? GfRange2d(r._min * m, r._max * m)
                  : GfRange2d(r._max * m, r._min * m));
  }

  /// scalar multiply.
  friend GfRange2d operator*(const GfRange2d &r, double m) {
    return (m > 0 ? GfRange2d(r._min * m, r._max * m)
                  : GfRange2d(r._max * m, r._min * m));
  }

  /// scalar divide.
  friend GfRange2d operator/(const GfRange2d &r, double m) {
    return r * (1.0 / m);
  }

  /// hash.
  friend inline size_t hash_value(const GfRange2d &r) {
    return TfHash::Combine(r._min, r._max);
  }

  /// The min and max points must match exactly for equality.
  bool operator==(const GfRange2d &b) const {
    return (_min == b._min && _max == b._max);
  }

  bool operator!=(const GfRange2d &b) const { return !(*this == b); }

  /// Compare this range to a GfRange2f.
  ///
  /// The values must match exactly and it does exactly what you might
  /// expect when comparing float and double values.
  GF_API inline bool operator==(const GfRange2f &other) const;
  GF_API inline bool operator!=(const GfRange2f &other) const;

  /// Compute the squared distance from a point to the range.
  GF_API
  double GetDistanceSquared(const GfVec2d &p) const;

  /// Returns the ith corner of the range, in the following order:
  /// SW, SE, NW, NE.
  GF_API
  GfVec2d GetCorner(size_t i) const;

  /// Returns the ith quadrant of the range, in the following order:
  /// SW, SE, NW, NE.
  GF_API
  GfRange2d GetQuadrant(size_t i) const;

  /// The unit square.
  GF_API
  static const GfRange2d UnitSquare;

private:
  /// Minimum and maximum points.
  GfVec2d _min, _max;

  /// Extends minimum point if necessary to contain given point.
  static void _FindMin(GfVec2d &dest, const GfVec2d &point) {
    if (point[0] < dest[0])
      dest[0] = point[0];
    if (point[1] < dest[1])
      dest[1] = point[1];
  }

  /// Extends maximum point if necessary to contain given point.
  static void _FindMax(GfVec2d &dest, const GfVec2d &point) {
    if (point[0] > dest[0])
      dest[0] = point[0];
    if (point[1] > dest[1])
      dest[1] = point[1];
  }
};

/// Output a GfRange2d.
/// \ingroup group_gf_DebuggingOutput
GF_API std::ostream &operator<<(std::ostream &, GfRange2d const &);

PXR_NAMESPACE_CLOSE_SCOPE
#include "Gf/range2f.h"
PXR_NAMESPACE_OPEN_SCOPE

inline bool GfRange2d::operator==(const GfRange2f &other) const {
  return _min == GfVec2d(other.GetMin()) && _max == GfVec2d(other.GetMax());
}

inline bool GfRange2d::operator!=(const GfRange2f &other) const {
  return !(*this == other);
}

PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_BASE_GF_RANGE2D_H

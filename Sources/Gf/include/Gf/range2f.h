//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// range.template.h file to make changes.

#ifndef PXR_BASE_GF_RANGE2F_H
#define PXR_BASE_GF_RANGE2F_H

/// \file gf/range2f.h
/// \ingroup group_gf_BasicGeometry

#include "pxr/pxrns.h"

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

template<> struct GfIsGfRange<class GfRange2f> {
  static const bool value = true;
};

/// \class GfRange2f
/// \ingroup group_gf_BasicGeometry
///
/// Basic type: 2-dimensional floating point range.
///
/// This class represents a 2-dimensional range (or interval) All
/// operations are component-wise and conform to interval mathematics. An
/// empty range is one where max < min.
/// The default empty is [FLT_MAX,-FLT_MAX]
class GfRange2f {
 public:
  /// Helper typedef.
  typedef GfVec2f MinMaxType;

  static const size_t dimension = GfVec2f::dimension;
  typedef GfVec2f::ScalarType ScalarType;

  /// Sets the range to an empty interval
  // TODO check whether this can be deprecated.
  void inline SetEmpty()
  {
    _min[0] = _min[1] = FLT_MAX;
    _max[0] = _max[1] = -FLT_MAX;
  }

  /// The default constructor creates an empty range.
  GfRange2f()
  {
    SetEmpty();
  }

  /// This constructor initializes the minimum and maximum points.
  GfRange2f(const GfVec2f &min, const GfVec2f &max) : _min(min), _max(max) {}

  /// Construct from GfRange2d.
  GF_API
  explicit GfRange2f(class GfRange2d const &other);

  /// Returns the minimum value of the range.
  const GfVec2f &GetMin() const
  {
    return _min;
  }

  /// Returns the maximum value of the range.
  const GfVec2f &GetMax() const
  {
    return _max;
  }

  /// Returns the size of the range.
  GfVec2f GetSize() const
  {
    return _max - _min;
  }

  /// Returns the midpoint of the range, that is, 0.5*(min+max).
  /// Note: this returns zero in the case of default-constructed ranges,
  /// or ranges set via SetEmpty().
  GfVec2f GetMidpoint() const
  {
    return static_cast<ScalarType>(0.5) * _min + static_cast<ScalarType>(0.5) * _max;
  }

  /// Sets the minimum value of the range.
  void SetMin(const GfVec2f &min)
  {
    _min = min;
  }

  /// Sets the maximum value of the range.
  void SetMax(const GfVec2f &max)
  {
    _max = max;
  }

  /// Returns whether the range is empty (max < min).
  bool IsEmpty() const
  {
    return _min[0] > _max[0] || _min[1] > _max[1];
  }

  /// Modifies the range if necessary to surround the given value.
  /// \deprecated Use UnionWith() instead.
  void ExtendBy(const GfVec2f &point)
  {
    UnionWith(point);
  }

  /// Modifies the range if necessary to surround the given range.
  /// \deprecated Use UnionWith() instead.
  void ExtendBy(const GfRange2f &range)
  {
    UnionWith(range);
  }

  /// Returns true if the \p point is located inside the range. As with all
  /// operations of this type, the range is assumed to include its extrema.
  bool Contains(const GfVec2f &point) const
  {
    return (point[0] >= _min[0] && point[0] <= _max[0] && point[1] >= _min[1] &&
            point[1] <= _max[1]);
  }

  /// Returns true if the \p range is located entirely inside the range. As
  /// with all operations of this type, the ranges are assumed to include
  /// their extrema.
  bool Contains(const GfRange2f &range) const
  {
    return Contains(range._min) && Contains(range._max);
  }

  /// Returns true if the \p point is located inside the range. As with all
  /// operations of this type, the range is assumed to include its extrema.
  /// \deprecated Use Contains() instead.
  bool IsInside(const GfVec2f &point) const
  {
    return Contains(point);
  }

  /// Returns true if the \p range is located entirely inside the range. As
  /// with all operations of this type, the ranges are assumed to include
  /// their extrema.
  /// \deprecated Use Contains() instead.
  bool IsInside(const GfRange2f &range) const
  {
    return Contains(range);
  }

  /// Returns true if the \p range is located entirely outside the range. As
  /// with all operations of this type, the ranges are assumed to include
  /// their extrema.
  bool IsOutside(const GfRange2f &range) const
  {
    return ((range._max[0] < _min[0] || range._min[0] > _max[0]) ||
            (range._max[1] < _min[1] || range._min[1] > _max[1]));
  }

  /// Returns the smallest \c GfRange2f which contains both \p a and \p b.
  static GfRange2f GetUnion(const GfRange2f &a, const GfRange2f &b)
  {
    GfRange2f res = a;
    _FindMin(res._min, b._min);
    _FindMax(res._max, b._max);
    return res;
  }

  /// Extend \p this to include \p b.
  const GfRange2f &UnionWith(const GfRange2f &b)
  {
    _FindMin(_min, b._min);
    _FindMax(_max, b._max);
    return *this;
  }

  /// Extend \p this to include \p b.
  const GfRange2f &UnionWith(const GfVec2f &b)
  {
    _FindMin(_min, b);
    _FindMax(_max, b);
    return *this;
  }

  /// Returns the smallest \c GfRange2f which contains both \p a and \p b
  /// \deprecated Use GetUnion() instead.
  static GfRange2f Union(const GfRange2f &a, const GfRange2f &b)
  {
    return GetUnion(a, b);
  }

  /// Extend \p this to include \p b.
  /// \deprecated Use UnionWith() instead.
  const GfRange2f &Union(const GfRange2f &b)
  {
    return UnionWith(b);
  }

  /// Extend \p this to include \p b.
  /// \deprecated Use UnionWith() instead.
  const GfRange2f &Union(const GfVec2f &b)
  {
    return UnionWith(b);
  }

  /// Returns a \c GfRange2f that describes the intersection of \p a and \p b.
  static GfRange2f GetIntersection(const GfRange2f &a, const GfRange2f &b)
  {
    GfRange2f res = a;
    _FindMax(res._min, b._min);
    _FindMin(res._max, b._max);
    return res;
  }

  /// Returns a \c GfRange2f that describes the intersection of \p a and \p b.
  /// \deprecated Use GetIntersection() instead.
  static GfRange2f Intersection(const GfRange2f &a, const GfRange2f &b)
  {
    return GetIntersection(a, b);
  }

  /// Modifies this range to hold its intersection with \p b and returns the
  /// result
  const GfRange2f &IntersectWith(const GfRange2f &b)
  {
    _FindMax(_min, b._min);
    _FindMin(_max, b._max);
    return *this;
  }

  /// Modifies this range to hold its intersection with \p b and returns the
  /// result.
  /// \deprecated Use IntersectWith() instead.
  const GfRange2f &Intersection(const GfRange2f &b)
  {
    return IntersectWith(b);
  }

  /// unary sum.
  GfRange2f &operator+=(const GfRange2f &b)
  {
    _min += b._min;
    _max += b._max;
    return *this;
  }

  /// unary difference.
  GfRange2f &operator-=(const GfRange2f &b)
  {
    _min -= b._max;
    _max -= b._min;
    return *this;
  }

  /// unary multiply.
  GfRange2f &operator*=(double m)
  {
    if (m > 0) {
      _min *= m;
      _max *= m;
    }
    else {
      GfVec2f tmp = _min;
      _min = _max * m;
      _max = tmp * m;
    }
    return *this;
  }

  /// unary division.
  GfRange2f &operator/=(double m)
  {
    return *this *= (1.0 / m);
  }

  /// binary sum.
  GfRange2f operator+(const GfRange2f &b) const
  {
    return GfRange2f(_min + b._min, _max + b._max);
  }

  /// binary difference.
  GfRange2f operator-(const GfRange2f &b) const
  {
    return GfRange2f(_min - b._max, _max - b._min);
  }

  /// scalar multiply.
  friend GfRange2f operator*(double m, const GfRange2f &r)
  {
    return (m > 0 ? GfRange2f(r._min * m, r._max * m) : GfRange2f(r._max * m, r._min * m));
  }

  /// scalar multiply.
  friend GfRange2f operator*(const GfRange2f &r, double m)
  {
    return (m > 0 ? GfRange2f(r._min * m, r._max * m) : GfRange2f(r._max * m, r._min * m));
  }

  /// scalar divide.
  friend GfRange2f operator/(const GfRange2f &r, double m)
  {
    return r * (1.0 / m);
  }

  /// hash.
  friend inline size_t hash_value(const GfRange2f &r)
  {
    return TfHash::Combine(r._min, r._max);
  }

  /// The min and max points must match exactly for equality.
  bool operator==(const GfRange2f &b) const
  {
    return (_min == b._min && _max == b._max);
  }

  bool operator!=(const GfRange2f &b) const
  {
    return !(*this == b);
  }

  /// Compare this range to a GfRange2d.
  ///
  /// The values must match exactly and it does exactly what you might
  /// expect when comparing float and double values.
  GF_API inline bool operator==(const GfRange2d &other) const;
  GF_API inline bool operator!=(const GfRange2d &other) const;

  /// Compute the squared distance from a point to the range.
  GF_API
  double GetDistanceSquared(const GfVec2f &p) const;

  /// Returns the ith corner of the range, in the following order:
  /// SW, SE, NW, NE.
  GF_API
  GfVec2f GetCorner(size_t i) const;

  /// Returns the ith quadrant of the range, in the following order:
  /// SW, SE, NW, NE.
  GF_API
  GfRange2f GetQuadrant(size_t i) const;

  /// The unit square.
  GF_API
  static const GfRange2f UnitSquare;

 private:
  /// Minimum and maximum points.
  GfVec2f _min, _max;

  /// Extends minimum point if necessary to contain given point.
  static void _FindMin(GfVec2f &dest, const GfVec2f &point)
  {
    if (point[0] < dest[0])
      dest[0] = point[0];
    if (point[1] < dest[1])
      dest[1] = point[1];
  }

  /// Extends maximum point if necessary to contain given point.
  static void _FindMax(GfVec2f &dest, const GfVec2f &point)
  {
    if (point[0] > dest[0])
      dest[0] = point[0];
    if (point[1] > dest[1])
      dest[1] = point[1];
  }
};

/// Output a GfRange2f.
/// \ingroup group_gf_DebuggingOutput
GF_API std::ostream &operator<<(std::ostream &, GfRange2f const &);

PXR_NAMESPACE_CLOSE_SCOPE
#include "Gf/range2d.h"
PXR_NAMESPACE_OPEN_SCOPE

inline bool GfRange2f::operator==(const GfRange2d &other) const
{
  return _min == GfVec2f(other.GetMin()) && _max == GfVec2f(other.GetMax());
}

inline bool GfRange2f::operator!=(const GfRange2d &other) const
{
  return !(*this == other);
}

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_BASE_GF_RANGE2F_H

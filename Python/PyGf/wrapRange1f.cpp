//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// wrapRange.template.cpp file to make changes.

#include "Gf/range1d.h"
#include "Gf/range1f.h"
#include "pxr/pxrns.h"

#include "Tf/hash.h"
#include "Tf/pyContainerConversions.h"
#include "Tf/pyUtils.h"
#include "Tf/wrapTypeHelpers.h"

#include <boost/python/class.hpp>
#include <boost/python/copy_const_reference.hpp>
#include <boost/python/operators.hpp>
#include <boost/python/return_arg.hpp>

#include <string>

using namespace boost::python;

using std::string;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

static const int _dimension = 1;

static string _Repr(GfRange1f const &self)
{
  return TF_PY_REPR_PREFIX + "Range1f(" + TfPyRepr(self.GetMin()) + ", " +
         TfPyRepr(self.GetMax()) + ")";
}

static GfRange1f __truediv__(const GfRange1f &self, double value)
{
  return self / value;
}

static GfRange1f &__itruediv__(GfRange1f &self, double value)
{
  return self /= value;
}

static size_t __hash__(GfRange1f const &r)
{
  return TfHash{}(r);
}

}  // anonymous namespace

void wrapRange1f()
{
  object getMin = make_function(&GfRange1f::GetMin, return_value_policy<return_by_value>());

  object getMax = make_function(&GfRange1f::GetMax, return_value_policy<return_by_value>());

  class_<GfRange1f> cls("Range1f", init<>());
  cls.def(init<GfRange1f>())
      .def(init<float, float>())

      .def(init<GfRange1d>())

      .def(TfTypePythonClass())

      .def_readonly("dimension", _dimension)

      .add_property("min", getMin, &GfRange1f::SetMin)
      .add_property("max", getMax, &GfRange1f::SetMax)

      .def("GetMin", getMin)
      .def("GetMax", getMax)

      .def("GetSize", &GfRange1f::GetSize)
      .def("GetMidpoint", &GfRange1f::GetMidpoint)

      .def("SetMin", &GfRange1f::SetMin)
      .def("SetMax", &GfRange1f::SetMax)

      .def("IsEmpty", &GfRange1f::IsEmpty)

      .def("SetEmpty", &GfRange1f::SetEmpty)

      .def("Contains", (bool(GfRange1f::*)(float) const) & GfRange1f::Contains)
      .def("Contains", (bool(GfRange1f::*)(const GfRange1f &) const) & GfRange1f::Contains)

      .def("GetUnion", &GfRange1f::GetUnion)
      .staticmethod("GetUnion")

      .def("UnionWith",
           (const GfRange1f &(GfRange1f::*)(float)) & GfRange1f::UnionWith,
           return_self<>())
      .def("UnionWith",
           (const GfRange1f &(GfRange1f::*)(const GfRange1f &)) & GfRange1f::UnionWith,
           return_self<>())

      .def("GetIntersection", &GfRange1f::GetIntersection)
      .staticmethod("GetIntersection")

      .def("IntersectWith",
           (const GfRange1f &(GfRange1f::*)(const GfRange1f &)) & GfRange1f::IntersectWith,
           return_self<>())

      .def("GetDistanceSquared", &GfRange1f::GetDistanceSquared)

      .def(str(self))
      .def(self += self)
      .def(self -= self)
      .def(self *= double())
      .def(self /= double())
      .def(self + self)
      .def(self - self)
      .def(double() * self)
      .def(self * double())
      .def(self / double())
      .def(self == GfRange1d())
      .def(self != GfRange1d())
      .def(self == self)
      .def(self != self)
      .def("__repr__", _Repr)
      .def("__hash__", __hash__)

      ;
  to_python_converter<std::vector<GfRange1f>, TfPySequenceToPython<std::vector<GfRange1f>>>();

  if (!PyObject_HasAttrString(cls.ptr(), "__truediv__")) {
    // __truediv__ not added by .def( self / double() ) above, which
    // happens when building with python 2, but we need it to support
    // "from __future__ import division"
    cls.def("__truediv__", __truediv__);
  }
  if (!PyObject_HasAttrString(cls.ptr(), "__itruediv__")) {
    // __itruediv__ not added by .def( self /= double() ) above, which
    // happens when building with python 2, but we need it to support
    // "from __future__ import division". This is also a workaround for a
    // bug in the current version of boost::python that incorrectly wraps
    // in-place division with __idiv__ when building with python 3.
    cls.def("__itruediv__", __itruediv__, return_self<>());
  }
}

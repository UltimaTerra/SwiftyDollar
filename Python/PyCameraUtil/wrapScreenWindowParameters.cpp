//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
///
/// \file camera/wrapScreenWindowParameters.h

#include "CameraUtil/screenWindowParameters.h"

#include <boost/python.hpp>

using namespace boost::python;

PXR_NAMESPACE_USING_DIRECTIVE

void wrapScreenWindowParameters()
{
  object getScreenWindowFunc = make_function(&CameraUtilScreenWindowParameters::GetScreenWindow,
                                             return_value_policy<copy_const_reference>());

  object getZFacingViewMatrixFunc = make_function(
      &CameraUtilScreenWindowParameters::GetZFacingViewMatrix,
      return_value_policy<copy_const_reference>());

  class_<CameraUtilScreenWindowParameters>("ScreenWindowParameters", no_init)
      .def(init<const GfCamera &>())
      .add_property("screenWindow", getScreenWindowFunc)
      .add_property("fieldOfView", &CameraUtilScreenWindowParameters::GetFieldOfView)
      .add_property("zFacingViewMatrix", getZFacingViewMatrixFunc);
}

//
// Copyright 2017 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef PXR_IMAGING_CAMERA_UTIL_API_H
#define PXR_IMAGING_CAMERA_UTIL_API_H

#include "Arch/export.h"

#if defined(PXR_STATIC)
#  define CAMERAUTIL_API
#  define CAMERAUTIL_API_TEMPLATE_CLASS(...)
#  define CAMERAUTIL_API_TEMPLATE_STRUCT(...)
#  define CAMERAUTIL_LOCAL
#else
#  if defined(CAMERAUTIL_EXPORTS)
#    define CAMERAUTIL_API ARCH_EXPORT
#    define CAMERAUTIL_API_TEMPLATE_CLASS(...) ARCH_EXPORT_TEMPLATE(class, __VA_ARGS__)
#    define CAMERAUTIL_API_TEMPLATE_STRUCT(...) ARCH_EXPORT_TEMPLATE(struct, __VA_ARGS__)
#  else
#    define CAMERAUTIL_API ARCH_IMPORT
#    define CAMERAUTIL_API_TEMPLATE_CLASS(...) ARCH_IMPORT_TEMPLATE(class, __VA_ARGS__)
#    define CAMERAUTIL_API_TEMPLATE_STRUCT(...) ARCH_IMPORT_TEMPLATE(struct, __VA_ARGS__)
#  endif
#  define CAMERAUTIL_LOCAL ARCH_HIDDEN
#endif

#endif  // PXR_IMAGING_CAMERA_UTIL_API_H

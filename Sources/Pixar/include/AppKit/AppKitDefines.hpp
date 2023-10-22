//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLDefines.hpp
//
// Copyright 2020-2023 Apple Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "../Foundation/NSDefines.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#define _APPKIT_EXPORT _NS_EXPORT
#define _APPKIT_EXTERN _NS_EXTERN
#define _APPKIT_INLINE _NS_INLINE
#define _APPKIT_PACKED _NS_PACKED

#define _APPKIT_CONST(type, name) _NS_CONST(type, name)
#define _APPKIT_ENUM(type, name) _NS_ENUM(type, name)
#define _APPKIT_OPTIONS(type, name) _NS_OPTIONS(type, name)

#define _APPKIT_VALIDATE_SIZE(ns, name) _NS_VALIDATE_SIZE(ns, name)
#define _APPKIT_VALIDATE_ENUM(ns, name) _NS_VALIDATE_ENUM(ns, name)

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

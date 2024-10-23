// Copyright 2009-present MongoDB, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// compiler.hpp
#pragma push_macro("MONGOCXX_INLINE")
#undef MONGOCXX_INLINE
#pragma push_macro("MONGOCXX_CALL")
#undef MONGOCXX_CALL

// config.hpp (generated by CMake)
#pragma push_macro("MONGOCXX_INLINE_NAMESPACE_BEGIN")
#undef MONGOCXX_INLINE_NAMESPACE_BEGIN
#pragma push_macro("MONGOCXX_INLINE_NAMESPACE_END")
#undef MONGOCXX_INLINE_NAMESPACE_END

// version.hpp (generated by CMake)
#pragma push_macro("MONGOCXX_VERSION_STRING")
#undef MONGOCXX_VERSION_STRING
#pragma push_macro("MONGOCXX_VERSION_EXTRA")
#undef MONGOCXX_VERSION_EXTRA
#pragma push_macro("MONGOCXX_VERSION_MAJOR")
#undef MONGOCXX_VERSION_MAJOR
#pragma push_macro("MONGOCXX_VERSION_MINOR")
#undef MONGOCXX_VERSION_MINOR
#pragma push_macro("MONGOCXX_VERSION_PATCH")
#undef MONGOCXX_VERSION_PATCH

// export.hpp (generated by CMake)
#pragma push_macro("MONGOCXX_ABI_EXPORT_H")
#if !defined(MONGOCXX_ABI_EXPORT_H)
#pragma push_macro("MONGOCXX_ABI_EXPORT")
#undef MONGOCXX_ABI_EXPORT
#pragma push_macro("MONGOCXX_ABI_NO_EXPORT")
#undef MONGOCXX_ABI_NO_EXPORT
#pragma push_macro("MONGOCXX_ABI_CDECL")
#undef MONGOCXX_ABI_CDECL
#pragma push_macro("MONGOCXX_ABI_EXPORT_CDECL")
#undef MONGOCXX_ABI_EXPORT_CDECL
#pragma push_macro("MONGOCXX_API")
#undef MONGOCXX_API
#pragma push_macro("MONGOCXX_PRIVATE")
#undef MONGOCXX_PRIVATE
#pragma push_macro("MONGOCXX_DEPRECATED")
#undef MONGOCXX_DEPRECATED
#pragma push_macro("MONGOCXX_DEPRECATED_EXPORT")
#undef MONGOCXX_DEPRECATED_EXPORT
#pragma push_macro("MONGOCXX_DEPRECATED_NO_EXPORT")
#undef MONGOCXX_DEPRECATED_NO_EXPORT
#endif

#include <mongocxx/config/compiler.hpp>
#include <mongocxx/config/config.hpp>
#include <mongocxx/config/export.hpp>
#include <mongocxx/config/version.hpp>

// TODO: Find a way to DRY this with BSONCXX_UNREACHABLE
#pragma push_macro("MONGOCXX_UNREACHABLE")
#undef MONGOCXX_UNREACHABLE
#define MONGOCXX_UNREACHABLE std::abort()

///
/// @file
/// The mongocxx macro guard prelude header.
///
/// @warning For internal use only!
///
/// @par Includes
/// - @ref mongocxx/v_noabi/mongocxx/config/compiler.hpp
/// - @ref mongocxx-v_noabi-mongocxx-config-config-hpp
/// - @ref mongocxx-v_noabi-mongocxx-config-export-hpp
/// - @ref mongocxx-v_noabi-mongocxx-config-version-hpp
///
/// This header uses macro pragmas to guard macros defined by the mongocxx library for internal use
/// by "pushing" their prior definition onto the stack before use by mongocxx headers.
///
/// @see
/// - @ref mongocxx/v_noabi/mongocxx/config/postlude.hpp
///

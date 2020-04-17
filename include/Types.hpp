/**
 * Common type definitions.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2019, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef TYPES_HPP_
#define TYPES_HPP_

#include "Definitions.hpp"

#ifdef EOOS_TYPE_STDLIB
#include <cstdint>
#endif

namespace local
{


    #if EOOS_CPP_STANDARD >= 2011
    typedef decltype(nullptr)  nullptr_t;
    #else
    typedef signed int nullptr_t;
    #endif // __cplusplus


    #ifndef NULL
    #if EOOS_CPP_STANDARD >= 2011
    static const nullptr_t NULL = nullptr;
    #else
    static const nullptr_t NULL = 0;
    #endif
    #endif

    // NULLPTR definition for EOOS implenemtation.
    static const nullptr_t NULLPTR = NULL;

    #if defined (EOOS_TYPE_STDLIB)
    // C++ Standard Library types
    typedef ::std::int16_t      int16;
    typedef ::std::uint16_t     uint16;
    typedef ::std::int32_t      int32;
    typedef ::std::uint32_t     uint32;
    typedef ::std::int64_t      int64;
    typedef ::std::uint64_t     uint64;
    typedef ::std::uintptr_t    intptr;
    typedef ::std::uintptr_t    uintptr;
    #elif defined(EOOS_TYPE_WIDTH_LP32)
    // LP32 or 2/4/4 (int is 16-bit, long and pointer are 32-bit)
    typedef signed   int        int16;
    typedef unsigned int        uint16;
    typedef signed   long       int32;
    typedef unsigned long       uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef signed   long       intptr;
    typedef unsigned long       uintptr;
    #elif defined(EOOS_TYPE_WIDTH_ILP32)
    // ILP32 or 4/4/4 (int, long, and pointer are 32-bit)
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef signed   int        intptr;
    typedef unsigned int        uintptr;
    #elif defined(EOOS_TYPE_WIDTH_LLP64)
    // LLP64 or 4/4/8 (int and long are 32-bit, pointer is 64-bit)
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef signed   long long  intptr;
    typedef unsigned long long  uintptr;
    #elif defined(EOOS_TYPE_WIDTH_LP64)
    // LP64 or 4/8/8 (int is 32-bit, long and pointer are 64-bit)    )
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long       int64;
    typedef unsigned long       uint64;
    typedef signed   long       intptr;
    typedef unsigned long       uintptr;
    #else
    // C++ standard
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef signed   int        intptr;
    typedef unsigned int        uintptr;
    #endif

    // Byte types for byte addressing
    typedef signed char         int8;
    typedef unsigned char       uint8;
    // Floating point types
    typedef float               float32;
    typedef double              float64;
    // Type of minimal addressable memory cell
    typedef signed char         cell;
    // Typy of the maximum size of a theoretically possible object of any types including array
    typedef EOOS_SIZE_TYPE      size_t;

}
#endif // TYPES_HPP_

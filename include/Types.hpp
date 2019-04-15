/** 
 * Common type definitions.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2019, Embedded Team, Sergey Baigudin
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
    #ifndef NULL
	
    /**
     * NULL definition since C++11.
     */
    #if __cplusplus >= 201103L
    typedef decltype(nullptr)  nullptr_t;
    static const nullptr_t NULL = nullptr;

    /**
     * NULL definition until C++11.
     */
    #else
    typedef signed int nullptr_t;
    static const nullptr_t NULL = 0;
    #endif // __cplusplus

    #endif // NULL

    #if defined (EOOS_TYPE_STDLIB)
    typedef ::std::int16_t      int16;
    typedef ::std::uint16_t     uint16;
    typedef ::std::int32_t      int32;
    typedef ::std::uint32_t     uint32;
    typedef ::std::int64_t      int64;
    typedef ::std::uint64_t     uint64;
    typedef ::std::intptr_t     intptr;
    typedef ::std::size_t       size_t;
    #elif defined(EOOS_TYPE_WIDTH_LP32)
    // LP32 or 2/4/4 (int is 16-bit, long and pointer are 32-bit)
    typedef signed   int        int16;
    typedef unsigned int        uint16;
    typedef signed   long       int32;
    typedef unsigned long       uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef unsigned int        intptr;
    typedef unsigned            size_t;
    #elif defined(EOOS_TYPE_WIDTH_ILP32)
    // ILP32 or 4/4/4 (int, long, and pointer are 32-bit)
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef unsigned int        intptr;
    typedef unsigned            size_t;
    #elif defined(EOOS_TYPE_WIDTH_LLP64)
    // ILP32 or 4/4/4 (int, long, and pointer are 32-bit)
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef unsigned long long  intptr;
    typedef unsigned            size_t;
    #elif defined(EOOS_TYPE_WIDTH_LP64)
    // LP64 or 4/8/8 (int is 32-bit, long and pointer are 64-bit)    )
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long       int64;
    typedef unsigned long long  intptr;
    typedef unsigned            size_t;
    #else
    // C++ standard
    typedef signed   short      int16;
    typedef unsigned short      uint16;
    typedef signed   int        int32;
    typedef unsigned int        uint32;
    typedef signed   long long  int64;
    typedef unsigned long long  uint64;
    typedef unsigned int        intptr;
    typedef unsigned            size_t;
    #endif

    // Byte types for byte addressing
    typedef signed char         int8;
    typedef unsigned char       uint8;
    // Floating point types
    typedef float               float32;
    typedef double              float64;
    // Type of minimal addressable memory cell
    typedef signed char         cell;

}
#endif // TYPES_HPP_

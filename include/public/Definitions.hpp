/**
 * @file      Definitions.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018-2022, Sergey Baigudin, Baigudin Software
 *
 * @brief Global definitions.
 */
#ifndef DEFINITIONS_HPP_
#define DEFINITIONS_HPP_

/**
 * @brief C++ language standard definition.
 */
#ifdef __cplusplus
    #if __cplusplus == 199711L
        #define EOOS_CPP_STANDARD 1998
    #elif __cplusplus == 201103L
        #define EOOS_CPP_STANDARD 2011
    #elif __cplusplus == 201402L
        #define EOOS_CPP_STANDARD 2014
    #elif __cplusplus == 201703L
        #define EOOS_CPP_STANDARD 2017
    #elif __cplusplus == 202002L
        #define EOOS_CPP_STANDARD 2020
    #else
        #error "C++ language standard set for compiler is not supported"
    #endif
#else
    #error "C language standard is not supported at all"
#endif

/**
 * @brief Microsoft C/C++ compiler (MSVC).
 */
#ifdef _MSC_VER
    // Resolves issue with error C2065: 'not': undeclared identifier.
    // @todo To refactor source code to use '!' instead of 'not'.
    // #include <iso646.h>
    #define not !
    
    #ifdef _WIN64
        #define EOOS_TYPE_WIDTH_LLP64
        #define EOOS_SIZE_TYPE unsigned __int64
    #else // _WIN32
        #define EOOS_TYPE_WIDTH_ILP32
        #define EOOS_SIZE_TYPE unsigned int
    #endif
    // Define Windows 10 if other is not set by using the /D compiler option.
    #ifndef WINVER
        #define WINVER 0x0A00
    #endif    
    #ifndef _WIN32_WINNT
        #define _WIN32_WINNT 0x0A00
    #endif

/**
 * @brief GNU C/C++ compiler.
 */
#elif __GNUC__

    #ifdef __LP64__
        #define EOOS_TYPE_WIDTH_LP64
        #define EOOS_SIZE_TYPE unsigned long int
    #else
        #error "Memory type is not supported"
    #endif

/**
 * @brief Undefined compiler 
 */ 
#else
    #define EOOS_TYPE_STDLIB
    #define EOOS_SIZE_TYPE std::size_t
#endif

/**
 * @brief C++ language keywords re-definition.
 */
#if EOOS_CPP_STANDARD >= 2011
    #define EOOS_KEYWORD_NOEXCEPT noexcept
#else
    #define EOOS_KEYWORD_NOEXCEPT
#endif // __cplusplus




/**
 * @brief Definitions of Data Model of a hardware system.
 *
 * Please, chose one of width in bits of the below Data Models.
 * No Data Model selected means C++ standard width in bits.
 *
 * @todo This must be removed in future, and Data Model model has to be defined based on compiler usage for HW.
 */
// C++ Standard Library types usage
//#define EOOS_TYPE_STDLIB

// LP32 or 2/4/4 (int is 16-bit, long and pointer are 32-bit)
// #define EOOS_TYPE_WIDTH_LP32

// ILP32 or 4/4/4 (int, long, and pointer are 32-bit)
// #define EOOS_TYPE_WIDTH_ILP32

// LLP64 or 4/4/8 (int and long are 32-bit, pointer is 64-bit)
// #define EOOS_TYPE_WIDTH_LLP64

// LP64 or 4/8/8 (int is 32-bit, long and pointer are 64-bit)
// #define EOOS_TYPE_WIDTH_LP64

/**
 * @brief Definition of no strict MISRA C++:2008 rules usage.
 *
 * Commonly, the definition means that a system can use heap memory.
 */
#ifndef EOOS_NO_STRICT_MISRA_RULES
    #define EOOS_NO_STRICT_MISRA_RULES
#endif

#endif // DEFINITIONS_HPP_

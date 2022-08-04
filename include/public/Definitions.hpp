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
 * @brief Enable dynamic heap memory usage.
 *
 * MISRA-C++:2008 prohibits dynamic heap memory usage in Rule 18–4–1.
 * AUTOSAR-C++14 allows dynamic heap memory allocation usage conditionally in Rules A18-5-1, A18-5-2, A18-5-3.
 *
 * @note Temporary cannot be disabled till it will be tested in an appropriate release.
 * @todo Enable and test the mode.
 */
#ifndef EOOS_ENABLE_DYNAMIC_HEAP_MEMORY
    #define EOOS_ENABLE_DYNAMIC_HEAP_MEMORY
#endif

#endif // DEFINITIONS_HPP_

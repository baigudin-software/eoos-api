/** 
 * Global definitions.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018-2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef DEFINITIONS_HPP_
#define DEFINITIONS_HPP_

/**
 * Definitions of Data Model of a hardware system.
 *
 * Please, chose one of width in bits of the below Data Models.
 * No Data Model selected means C++ standard width in bits.
 */
// C++ Standard Library types usage
// #define EOOS_TYPE_STDLIB

// LP32 or 2/4/4 (int is 16-bit, long and pointer are 32-bit)
// #define EOOS_TYPE_WIDTH_LP32

// ILP32 or 4/4/4 (int, long, and pointer are 32-bit)
// #define EOOS_TYPE_WIDTH_ILP32

// LLP64 or 4/4/8 (int and long are 32-bit, pointer is 64-bit)
// #define EOOS_TYPE_WIDTH_LLP64

// LP64 or 4/8/8 (int is 32-bit, long and pointer are 64-bit)
// #define EOOS_TYPE_WIDTH_LP64

/**
 * Definition of no strict MISRA C++:2008 rules usage.
 *
 * Commonly, the definition means that a system can use heap memory.
 */
// #define EOOS_NO_STRICT_MISRA_RULES

#endif // DEFINITIONS_HPP_

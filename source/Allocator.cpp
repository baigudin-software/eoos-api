/**
 * @file      Allocator.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018-2021, Sergey Baigudin, Baigudin Software
 */ 
#include "Allocator.hpp"

namespace eoos
{
       
void* Allocator::allocate(size_t const size)
{
    #ifdef EOOS_NO_STRICT_MISRA_RULES
    return new cell_t[size];
    #else
    static_cast<void>(size); // Avoid MISRA-C++:2008 Rule 0–1–3 and AUTOSAR C++14 Rule A0-1-4
    return NULLPTR;
    #endif
}

void Allocator::free(void* const ptr)
{
    #ifdef EOOS_NO_STRICT_MISRA_RULES
    delete[] ptr;
    #else
    static_cast<void>(ptr); // Avoid MISRA-C++:2008 Rule 0–1–3 and AUTOSAR C++14 Rule A0-1-4
    #endif
}

} // namespace eoos


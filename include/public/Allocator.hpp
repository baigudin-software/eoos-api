/**
 * @file      Allocator.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef ALLOCATOR_HPP_
#define ALLOCATOR_HPP_

#include "Types.hpp"

namespace eoos
{
 
/**
 * @class Allocator
 * @brief Memory allocator.
 */ 
class Allocator
{

public:

    /**
     * @brief Allocates memory.
     *
     * @param size Number of bytes to allocate.
     * @return Allocated memory address or a null pointer.
     */
    static void* allocate(size_t size);

    /**
     * @brief Frees an allocated memory.
     *
     * @param ptr Address of allocated memory block or a null pointer.
     */
    static void free(void* ptr);

};

} // namespace eoos
#endif // ALLOCATOR_HPP_

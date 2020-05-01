/**
 * Memory allocator.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef ALLOCATOR_HPP_
#define ALLOCATOR_HPP_

#include "Types.hpp"

namespace eoos
{
    class Allocator
    {

    public:

        /**
         * Allocates memory.
         *
         * @param size - number of bytes to allocate.
         * @return allocated memory address or a null pointer.
         */
        static void* allocate(size_t size);

        /**
         * Frees an allocated memory.
         *
         * @param ptr - address of allocated memory block or a null pointer.
         */
        static void free(void* ptr);

    };
}
#endif // ALLOCATOR_HPP_

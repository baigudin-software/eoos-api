/** 
 * Memory allocator.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef ALLOCATOR_HPP_
#define ALLOCATOR_HPP_

#include "system.System.hpp"

class Allocator
{

public:

    /**
     * Allocates memory.
     *
     * @param size number of bytes to allocate.
     * @return allocated memory address or a null pointer.
     */    
    static void* allocate(size_t size)
    {
        return ::system::System::call().getKernel().getHeap().allocate(size, NULL);
    }
  
    /**
     * Frees an allocated memory.
     *
     * @param ptr address of allocated memory block or a null pointer.
     */      
    static void free(void* ptr)
    {
        return ::system::System::call().getKernel().getHeap().free(ptr);
    }

};
#endif // ALLOCATOR_HPP_

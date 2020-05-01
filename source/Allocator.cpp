/** 
 * The operating system modules memory allocator.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018-2020, Sergey Baigudin
 */
#include "Allocator.hpp"
#include "System.hpp"

namespace eoos
{
    /**
     * Pointer to constructed the operating systenm heap memory.
     */
    static api::Heap* heap_ = NULLPTR;
    
    /**
     * Allocates memory.
     *
     * @param size number of bytes to allocate.
     * @return allocated memory address or a null pointer.
     */    
    void* Allocator::allocate(size_t const size)
    {
        if(heap_ == NULLPTR)
        {
            heap_ = &System::call().getHeap();
        }
        return heap_->allocate(size, NULLPTR);
    }
    
    /**
     * Frees an allocated memory.
     *
     * @param ptr address of allocated memory block or a null pointer.
     */      
    void Allocator::free(void* const ptr)
    {
        if(heap_ != NULLPTR)
        {
            heap_->free(ptr);
        }
    }
}   


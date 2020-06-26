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
    namespace 
    {
        api::Heap* heap_ = NULLPTR;
    }
        
    void* Allocator::allocate(size_t const size)
    {
        if(heap_ == NULLPTR)
        {
            heap_ = &System::call().getHeap();
        }
        return heap_->allocate(size, NULLPTR);
    }
    
    void Allocator::free(void* const ptr)
    {
        if(heap_ != NULLPTR)
        {
            heap_->free(ptr);
        }
    }
}   


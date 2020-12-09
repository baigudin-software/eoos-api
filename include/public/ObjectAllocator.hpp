/**
 * @brief Object memory allocator.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2020, Sergey Baigudin, Baigudin Software
 */
#ifndef OBJECT_ALLOCATOR_HPP_
#define OBJECT_ALLOCATOR_HPP_

#include "Allocator.hpp"

namespace eoos
{

/**
 * @brief Primary template implementation.
 *
 * @param A - heap memory allocator class.
 */
template <class A = Allocator>
class ObjectAllocator
{

public:

    #ifdef EOOS_NO_STRICT_MISRA_RULES

    /**
     * @brief Operator new.
     *
     * @param size - a number of bytes to allocate.
     * @return allocated memory address or a null pointer.
     */
    void* operator new(size_t const size)
    {
        return A::allocate(size);
    }

    /**
     * @brief Operator delete.
     *
     * @param ptr - an address of allocated memory block or a null pointer.
     */
    void operator delete(void* const ptr)
    {
        A::free(ptr);
    }    

    /**
     * @brief Operator new.
     *
     * @param size - unused.
     * @param ptr - a pointer to reserved memory area.
     * @return given pointer.
     */
    void* operator new(size_t, void* const ptr)
    {
        return ptr;
    }
    
    /**
     * @brief Operator delete.
     */
    void operator delete(void*, void*)
    {
    }

    #endif // EOOS_NO_STRICT_MISRA_RULES
    
protected:

    /**
     * @brief Constructor.
     */
    ObjectAllocator()
    {
    }

    /**
     * @brief Destructor.
     */
    ~ObjectAllocator()
    {
    }    

};

} // namespace eoos
#endif // OBJECT_ALLOCATOR_HPP_

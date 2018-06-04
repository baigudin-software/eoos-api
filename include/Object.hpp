/** 
 * Root class of the class hierarchy.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "api.Object.hpp"
#include "Allocator.hpp"

namespace global
{
    /** 
     * Primary template implementation.
     *
     * @param A - heap memory allocator class.
     */ 
    template <class A = Allocator>
    class Object : public api::Object
    {
      
    public:
    
        /** 
         * Constructor.
         */  
        Object() : 
            isConstructed_ (true){
        }
        
        /** 
         * Copy constructor.
         *
         * @param obj - a source object interface.
         */ 
        explicit Object(const api::Object& obj) :
            isConstructed_ ( obj.isConstructed() ){
        }    
        
        /** 
         * Destructor.
         */    
        virtual ~Object()
        {
            isConstructed_ = false;
        }
    
        #ifdef NO_STRICT_MISRA_RULES
      
        /** 
         * Operator new.
         *
         * @param size - a number of bytes to allocate.
         * @return allocated memory address or a null pointer.
         */  
        void* operator new(const size_t size)
        {
            return A::allocate(size);
        }
      
        /** 
         * Operator new.
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
         * Operator delete.
         *
         * @param ptr - an address of allocated memory block or a null pointer.
         */
        void operator delete(void* const ptr)
        {
            A::free(ptr);
        }
        
        #endif // NO_STRICT_MISRA_RULES
    
    protected:
    
        /**
         * Sets the object constructed flag.
         *
         * @param flag - a new constructed flag.
         */      
        void setConstruct(const bool flag)
        {
            if( isConstructed_ == true ) 
            {
                isConstructed_ = flag;
            }
        }
        
        /**
         * Returns the object constructed flag.
         *
         * @return reference to the constructed flag.
         */      
        bool getConstruct() const
        {
            return isConstructed_;
        }  
    
    private:
    
        /** 
         * This object constructed flag.
         */  
        bool isConstructed_;
    
    };
}
#endif // OBJECT_HPP_

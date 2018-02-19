/** 
 * Root class of the class hierarchy.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef GLOBAL_OBJECT_HPP_
#define GLOBAL_OBJECT_HPP_

#include "api.Object.hpp"
#include "global.Allocator.hpp"

namespace global
{
    /** 
     * @param A heap memory allocator class.
     */ 
    template <class A = Allocator>
    class Object : public ::api::Object
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
         * @param obj reference to source object.
         */ 
        Object(const ::api::Object& obj) :
            isConstructed_ (true){
            const bool isConstructed = obj.isConstructed();
            setConstruct( isConstructed );
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
         * @param size number of bytes to allocate.
         * @return allocated memory address or a null pointer.
         */  
        void* operator new(const size_t size)
        {
            return A::allocate(size);
        }
      
        /** 
         * Operator new.
         *
         * @param size unused.
         * @param ptr  pointer to reserved memory area
         * @return given pointer.
         */  
        void* operator new(size_t, void* const ptr)
        {
            return ptr;
        }
        
        /**
         * Operator delete.
         *
         * @param ptr address of allocated memory block or a null pointer.
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
         * @param flag constructed flag.
         */      
        void setConstruct(const bool flag)
        {
            if( isConstructed_ ) 
            {
                isConstructed_ = flag;
            }
        }
        
        /**
         * Returns the object constructed flag.
         *
         * @return reference to the constructed flag.
         */      
        const bool& getConstruct() const
        {
            return isConstructed_;
        }  
        
        /**
         * Allocates memory.
         *
         * NOTE: You need to use "this->template allocate<Type>(size);" 
         * syntax, if your class is a template and inherits this class.
         *
         * @param size number of bytes to allocate.
         * @return allocated memory address or a null pointer.
         */    
        template<typename T0>
        static T0 allocate(const size_t size)
        {
            return static_cast<T0>( A::allocate(size) );
        }    
    
        /**
         * Frees an allocated memory.
         *
         * @param ptr address of allocated memory block or a null pointer.
         */      
        static void free(void* const ptr)
        {
            A::free(ptr);
        }
    
    private:
    
        /** 
         * Object constructed flag.
         */  
        bool isConstructed_;
    
    };
}
#endif // GLOBAL_OBJECT_HPP_

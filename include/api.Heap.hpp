/**
 * Heap memory interface.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_HEAP_HPP_
#define API_HEAP_HPP_

#include "api.Object.hpp"

namespace local
{
    namespace api
    {
        class Heap : public api::Object
        {
        
        public:
    
            /** 
             * Destructor.
             */
            virtual ~Heap(){}
            
            /**
             * Allocates memory.
             *
             * @param size - required memory size in byte.
             * @param ptr  - NULL value becomes to allocate memory, and 
             *               other given values are simply returned 
             *               as memory address.
             * @return pointer to allocated memory or NULL.
             */    
            virtual void* allocate(size_t size, void* ptr) = 0;
            
            /**
             * Frees an allocated memory.
             *
             * @param ptr - pointer to allocated memory.
             */      
            virtual void free(void* ptr) = 0;
    
        };
    }
}
#endif // API_HEAP_HPP_

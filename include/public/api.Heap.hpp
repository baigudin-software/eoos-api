/**
 * Heap memory interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_HEAP_HPP_
#define API_HEAP_HPP_

#include "api.Object.hpp"

namespace eoos
{
    namespace api
    {
        class Heap : public Object
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
             * @param ptr  - NULLPTR value becomes to allocate memory, and
             *               other given values are simply returned
             *               as memory address.
             * @return pointer to allocated memory or NULLPTR.
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

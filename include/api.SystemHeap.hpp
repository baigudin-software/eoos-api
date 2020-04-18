/**
 * System heap memory interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_SYSTEM_HEAP_HPP_
#define API_SYSTEM_HEAP_HPP_

#include "api.Heap.hpp"
#include "api.Toggle.hpp"

namespace eoos
{
    namespace api
    {
        class SystemHeap : public api::Heap
        {

        public:

            /**
             * Destructor.
             */
            virtual ~SystemHeap(){}

            /**
             * Sets a context switching locker.
             *
             * The method allows disabling and enabling thread context switching
             * when memory is being allocated or freed. Thus, the best way is
             * to pass an interface of global interrupt toggling. The parameter type
             * is reference to pointer, as when referenced pointer equals to NULL,
             * no blocks are happening.
             *
             * @param toggle - reference to pointer to some controller.
             */
            virtual void setToggle(api::Toggle*& toggle) = 0;

            /**
             * Resets a context switching locker.
             */
            virtual void resetToggle() = 0;

        };
    }
}
#endif // API_SYSTEM_HEAP_HPP_

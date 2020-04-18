/**
 * Stack interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_STACK_HPP_
#define API_STACK_HPP_

#include "api.Collection.hpp"
#include "api.IllegalValue.hpp"

namespace eoos
{
    namespace api
    {
        /**
         * Primary template implementation.
         *
         * @param T - data type of default stack element.
         */
        template <typename T>
        class Stack : public api::Collection<T>, public api::IllegalValue<T>
        {

        public:

            /**
             * Stack operations.
             *
             * Stack operations:
             * - Full stacks have stack pointers that point to the last used location.
             * - Empty stacks have stack pointers that point to the first unused location.
             * - Descending stacks grow towards decreasing memory addresses.
             * - Ascending stacks grow towards increasing memory addresses.
             */
            enum Operation
            {
                /**
                 * Full Descending.
                 */
                FD = 0,

                /**
                 * Empty Descending.
                 */
                ED = 1,

                /**
                 * Full Ascending.
                 */
                FA = 2,

                /**
                 * Empty Ascending.
                 */
                EA = 3

            };

            /**
             * Destructor.
             */
            virtual ~Stack(){}

            /**
             * Tests if this object has been constructed.
             *
             * @return true if object has been constructed successfully.
             */
            virtual bool_t isConstructed() const = 0;

            /**
             * Returns an initial top of stack.
             *
             * @return a memory address to top of this stack when object was built.
             */
            virtual const T* getTos() = 0;

            /**
             * Returns an type of stack operation.
             *
             * @return the stack operation.
             */
            virtual Operation getType() const = 0;

        };
    }
}
#endif // API_STACK_HPP_

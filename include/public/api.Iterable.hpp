/**
 * Iterable interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_ITERABLE_HPP_
#define API_ITERABLE_HPP_

#include "api.Object.hpp"
#include "api.Iterator.hpp"

namespace eoos
{
    namespace api
    {
        /**
         * Primary template implementation.
         *
         * @param T - data type of element.
         */
        template <typename T>
        class Iterable : public Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Iterable(){}

            /**
             * Returns an iterator of elements.
             *
             * NOTE: The delete operator must be called for returned value when
             * the iterating of a collection has been completed.
             *
             * @return pointer to new iterator.
             */
            virtual Iterator<T>* getIterator() = 0;

        };
    }
}
#endif // API_ITERABLE_HPP_

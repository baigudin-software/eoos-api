/**
 * The root interface of some collections.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_COLLECTION_HPP_
#define API_COLLECTION_HPP_

#include "api.Object.hpp"

namespace eoos
{
    namespace api
    {
        /**
         * Primary template implementation.
         *
         * @param T - data type of collection element.
         */
        template <typename T>
        class Collection : public Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Collection(){}

            /**
             * Returns a number of elements in this container.
             *
             * @return number of elements.
             */
             virtual int32_t getLength() const = 0;

             /**
              * Tests if this collection has elements.
              *
              * @return true if this collection does not contain any elements.
              */
             virtual bool_t isEmpty() const = 0;

        };
    }
}
#endif // API_COLLECTION_HPP_

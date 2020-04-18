/**
 * Illegal value interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_ILLEGAL_VALUE_HPP_
#define API_ILLEGAL_VALUE_HPP_

#include "api.Object.hpp"

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
        class IllegalValue : public api::Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~IllegalValue(){}

            /**
             * Returns illegal element which will be returned as error value.
             *
             * @return illegal element.
             */
            virtual T& getIllegal() const = 0;

            /**
             * Sets illegal element which will be returned as error value.
             *
             * NOTE: A passed value must be copied to an internal data structure of
             * a realizing class by calling a copy constructor so that the variable
             * might be invalidated after the function called.
             *
             * @param value - an illegal value.
             */
            virtual void setIllegal(const T& value) = 0;

            /**
             * Tests if given value is an illegal.
             *
             * @param value - a testing value.
             * @return true if value is an illegal.
             */
            virtual bool_t isIllegal(const T& value) const = 0;

        };
    }
}
#endif // API_ILLEGAL_VALUE_HPP_

/**
 * Root interface of the system class hierarchy.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_OBJECT_HPP_
#define API_OBJECT_HPP_

#include "Types.hpp"

namespace eoos
{
    namespace api
    {
        class Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Object(){}

            /**
             * Tests if this object has been constructed.
             *
             * @return true if object has been constructed successfully.
             */
            virtual bool_t isConstructed() const = 0;

        };
    }
}
#endif // API_OBJECT_HPP_

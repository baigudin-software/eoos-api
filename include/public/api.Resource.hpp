/**
 * Resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_RESOURCE_HPP_
#define API_RESOURCE_HPP_

#include "api.Object.hpp"

namespace eoos
{
    namespace api
    {
        class Resource : public Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Resource(){}

            /**
             * Tests if this resource is blocked.
             *
             * @return true if this resource is blocked.
             */
            virtual bool_t isBlocked() const = 0;

        };
    }
}
#endif // API_RESOURCE_HPP_

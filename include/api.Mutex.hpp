/**
 * Mutex interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2016, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_MUTEX_HPP_
#define API_MUTEX_HPP_

#include "api.Resource.hpp"

namespace eoos
{
    namespace api
    {
        class Mutex : public api::Resource
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Mutex(){}

            /**
             * Locks this mutex.
             *
             * @return true if this mutex is locked successfully.
             */
            virtual bool_t lock() = 0;

            /**
             * Unlocks this mutex.
             */
            virtual void unlock() = 0;

        };
    }
}
#endif // API_MUTEX_HPP_

/**
 * Mutex class.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include "Object.hpp"
#include "api.Mutex.hpp"
#include "System.hpp"

namespace local
{
    class Mutex : public ::local::Object<>, public api::Mutex
    {
        typedef Mutex             Self;
        typedef ::local::Object<> Parent;

    public:

        /**
         * Constructor.
         */
        Mutex() : Parent(),
            mutex_         (NULL){
            bool const isConstructed = construct();
            setConstructed( isConstructed );
        }

        /**
         * Destructor.
         */
        virtual ~Mutex()
        {
            delete mutex_;
        }

        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */
        virtual bool isConstructed() const
        {
            return Parent::isConstructed();
        }

        /**
         * Locks the mutex.
         *
         * @return true if the mutex is lock successfully.
         */
        virtual bool lock()
        {
            if( Self::isConstructed() )
            {
                return mutex_->lock();
            }
            else
            {
                return false;
            }
        }

        /**
         * Unlocks the mutex.
         */
        virtual void unlock()
        {
            if( Self::isConstructed() )
            {
                mutex_->unlock();
            }
        }

        /**
         * Tests if this resource is blocked.
         *
         * @return true if this resource is blocked.
         */
        virtual bool isBlocked() const
        {
            if( Self::isConstructed() )
            {
                return mutex_->isBlocked();
            }
            else
            {
                return false;
            }
        }

    private:

        /**
         * Constructor.
         *
         * @return true if object has been constructed successfully.
         */
        bool construct()
        {
            bool res = Self::isConstructed();
            if( res == true )
            {
                mutex_ = System::call().createMutex();
                if(mutex_ == NULL || not mutex_->isConstructed() )
                {
                    res = false;
                }
            }
            return res;
        }

        /**
         * Copy constructor.
         *
         * @param obj - reference to source object.
         */
        Mutex(const Mutex& obj);

        /**
         * Assignment operator.
         *
         * @param obj - reference to source object.
         * @return reference to this object.
         */
        Mutex& operator=(const Mutex& obj);

        /**
         * System mutex interface.
         */
        api::Mutex* mutex_;

    };
}
#endif // SYSTEM_MUTEX_HPP_

/**
 * Mutex class.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include "Object.hpp"
#include "api.Mutex.hpp"
#include "System.hpp"

namespace eoos
{
    class Mutex : public Object<>, public api::Mutex
    {
        typedef Mutex Self;
        typedef ::eoos::Object<> Parent;

    public:

        /**
         * Constructor.
         */
        Mutex() : Parent(),
            mutex_ (NULLPTR){
            bool_t const isConstructed = construct();
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
        virtual bool_t isConstructed() const
        {
            return Parent::isConstructed();
        }

        /**
         * Locks the mutex.
         *
         * @return true if the mutex is lock successfully.
         */
        virtual bool_t lock()
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
        virtual bool_t isBlocked() const
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
        bool_t construct()
        {
            bool_t res = Self::isConstructed();
            if( res == true )
            {
                mutex_ = System::call().createMutex();
                if(mutex_ == NULLPTR || not mutex_->isConstructed() )
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

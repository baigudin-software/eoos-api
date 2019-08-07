/**
 * The operating system thread.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "Object.hpp"
#include "api.Thread.hpp"
#include "System.hpp"

namespace local
{
    class Thread : public ::local::Object<>, public api::Thread, public api::Task
    {
        typedef Thread            Self;
        typedef ::local::Object<> Parent;

    public:

        /**
         * Constructor.
         */
        Thread() : Parent(),
            thread_ (NULL){
            bool const isConstructed = construct(*this);
            setConstructed( isConstructed );
        }

        /**
         * Constructor.
         *
         * @param task - an task interface whose main method is invoked when this thread is started.
         */
        Thread(api::Task& task) : Parent(),
            thread_    (NULL){
            bool const isConstructed = construct(task);
            setConstructed( isConstructed );
        }

        /**
         * Destructor.
         */
        virtual ~Thread()
        {
            delete thread_;
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
         * The method with self context which will be executed by default.
         *
         * @return zero, or error code if an error has been occurred.
         */
        virtual int32 start()
        {
            return 0;
        }

        /**
         * Causes this thread to begin execution.
         */
        virtual void execute()
        {
            if( Self::isConstructed() )
            {
                thread_->execute();
            }
        }

        /**
         * Returns size of task stack.
         *
         * @return stack size in bytes.
         */
        virtual int32 getStackSize() const
        {
            return 0x1000;
        }

        /**
         * Waits for this thread to die.
         */
        virtual void join()
        {
            if( Self::isConstructed() )
            {
                thread_->join();
            }
        }

        /**
         * Causes this thread to sleep.
         *
         * @param millis - a time to sleep in milliseconds.
         * @param nanos  - an additional nanoseconds to sleep.
         */
        virtual void sleep(int64 const millis, int32 const nanos = 0)
        {
            if( Self::isConstructed() )
            {
                thread_->sleep(millis, nanos);
            }
        }

        /**
         * Blocks this thread on given resource and yields the task.
         *
         * @param res - a resource.
         */
        virtual void block(api::Resource& res)
        {
            if( Self::isConstructed() )
            {
                return thread_->block(res);
            }
        }

        /**
         * Returns the identifier of this thread.
         *
         * @return the thread identifier.
         */
        virtual int64 getId() const
        {
            if( Self::isConstructed() )
            {
                return thread_->getId();
            }
            else
            {
                return -1;
            }
        }

        /**
         * Returns a status of this thread.
         *
         * @return this thread status.
         */
        virtual api::Thread::Status getStatus() const
        {
            if( Self::isConstructed() )
            {
                return thread_->getStatus();
            }
            else
            {
                return DEAD;
            }
        }

        /**
         * Returns this thread priority.
         *
         * @return priority value.
         */
        virtual int32 getPriority() const
        {
            if( Self::isConstructed() )
            {
                return thread_->getPriority();
            }
            else
            {
                return -1;
            }
        }

        /**
         * Sets this thread priority.
         *
         * @param priority - number of priority in range [MIN_PRIORITY, MAX_PRIORITY], or LOCK_PRIORITY.
         */
        virtual void setPriority(int32 const priority)
        {
            if( Self::isConstructed() )
            {
                thread_->setPriority(priority);
            }
        }

        /**
         * Returns currently executing thread.
         *
         * @return executing thread.
         */
        static api::Thread& getCurrent()
        {
            return System::call().getScheduler().getCurrentThread();
        }

        /**
         * Causes current thread to sleep.
         *
         * @param millis - a time to sleep in milliseconds.
         * @param nanos  - an additional nanoseconds to sleep.
         */
        static void sleepCurrent(int64 const millis, int32 const nanos = 0)
        {
            getCurrent().sleep(millis, nanos);
        }

        /**
         * Yields to next thread.
         */
        static void yield()
        {
            return System::call().getScheduler().yield();
        }

        /**
         * Returns the toggle interface for controlling global thread switching.
         *
         * @return toggle interface.
         */
        static api::Toggle& toggle()
        {
            return System::call().getScheduler().toggle();
        }

    private:

        /**
         * Constructor.
         *
         * @param task - an task interface whose main method is invoked when this thread is started.
         * @return true if object has been constructed successfully.
         */
        bool construct(api::Task& task)
        {
            bool res = Self::isConstructed();
            if( res == true )
            {
                thread_ = System::call().getScheduler().createThread(task);
                if(thread_ == NULL || not thread_->isConstructed() )
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
        Thread(const Thread& obj);

        /**
         * Assignment operator.
         *
         * @param obj - reference to source object.
         * @return reference to this object.
         */
        Thread& operator=(const Thread& obj);

        /**
         * A system scheduler thread.
         */
        api::Thread* thread_;

    };
}
#endif // THREAD_HPP_

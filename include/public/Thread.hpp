/**
 * @brief The operating system thread.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "Object.hpp"
#include "api.Thread.hpp"
#include "System.hpp"

namespace eoos
{
    
class Thread : public Object<>, public api::Thread, public api::Task
{
    typedef Thread Self;
    typedef ::eoos::Object<> Parent;

public:

    /**
     * @brief Constructor.
     */
    Thread() : Parent(),
        thread_ (NULLPTR){
        bool_t const isConstructed = construct(*this);
        setConstructed( isConstructed );
    }

    /**
     * @brief Constructor.
     *
     * @param task - a task interface whose start function is invoked when this thread is started.
     */
    Thread(api::Task& task) : Parent(),
        thread_    (NULLPTR){
        bool_t const isConstructed = construct(task);
        setConstructed( isConstructed );
    }

    /**
     * @brief Destructor.
     */
    virtual ~Thread()
    {
        delete thread_;
    }

    /**
     * @brief Tests if this object has been constructed.
     *
     * @return true if object has been constructed successfully.
     */
    virtual bool_t isConstructed() const
    {
        return Parent::isConstructed();
    }

    /**
     * @brief The method with self context which will be executed by default.
     *
     * @return zero, or error code if an error has been occurred.
     */
    virtual int32_t start()
    {
        return 0;
    }

    /**
     * @brief Causes this thread to begin execution.
     */
    virtual void execute()
    {
        if( Self::isConstructed() )
        {
            thread_->execute();
        }
    }

    /**
     * @brief Returns size of task stack.
     *
     * @return stack size in bytes.
     */
    virtual int32_t getStackSize() const
    {
        return 0x1000;
    }

    /**
     * @brief Waits for this thread to die.
     */
    virtual void join()
    {
        if( Self::isConstructed() )
        {
            thread_->join();
        }
    }

    /**
     * @brief Causes this thread to sleep.
     *
     * @param millis - a time to sleep in milliseconds.
     * @param nanos  - an additional nanoseconds to sleep.
     */
    virtual void sleep(int64_t const millis, int32_t const nanos = 0)
    {
        if( Self::isConstructed() )
        {
            thread_->sleep(millis, nanos);
        }
    }

    /**
     * @brief Blocks this thread on given resource and yields the task.
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
     * @brief Returns the identifier of this thread.
     *
     * @return the thread identifier.
     */
    virtual int64_t getId() const
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
     * @brief Returns a status of this thread.
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
     * @brief Returns this thread priority.
     *
     * @return priority value.
     */
    virtual int32_t getPriority() const
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
     * @brief Sets this thread priority.
     *
     * @param priority - number of priority in range [MIN_PRIORITY, MAX_PRIORITY], or LOCK_PRIORITY.
     */
    virtual void setPriority(int32_t const priority)
    {
        if( Self::isConstructed() )
        {
            thread_->setPriority(priority);
        }
    }

    /**
     * @brief Returns currently executing thread.
     *
     * @return executing thread.
     */
    static api::Thread& getCurrent()
    {
        return System::call().getScheduler().getCurrentThread();
    }

    /**
     * @brief Causes current thread to sleep.
     *
     * @param millis - a time to sleep in milliseconds.
     * @param nanos  - an additional nanoseconds to sleep.
     */
    static void sleepCurrent(int64_t const millis, int32_t const nanos = 0)
    {
        getCurrent().sleep(millis, nanos);
    }

    /**
     * @brief Yields to next thread.
     */
    static void yield()
    {
        return System::call().getScheduler().yield();
    }

    /**
     * @brief Returns the toggle interface for controlling global thread switching.
     *
     * @return toggle interface.
     */
    static api::Toggle& toggle()
    {
        return System::call().getScheduler().toggle();
    }

private:

    /**
     * @brief Constructor.
     *
     * @param task - an task interface whose main method is invoked when this thread is started.
     * @return true if object has been constructed successfully.
     */
    bool_t construct(api::Task& task)
    {
        bool_t res = Self::isConstructed();
        if( res == true )
        {
            thread_ = System::call().getScheduler().createThread(task);
            if(thread_ == NULLPTR || not thread_->isConstructed() )
            {
                res = false;
            }
        }
        return res;
    }

    /**
     * @brief Copy constructor.
     *
     * @param obj - reference to source object.
     */
    Thread(const Thread& obj);

    /**
     * @brief Assignment operator.
     *
     * @param obj - reference to source object.
     * @return reference to this object.
     */
    Thread& operator=(const Thread& obj);

    /**
     * @brief A system scheduler thread.
     */
    api::Thread* thread_;

};

} // namespace eoos
#endif // THREAD_HPP_

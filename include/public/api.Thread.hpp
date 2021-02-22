/**
 * @brief Thread interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_THREAD_HPP_
#define API_THREAD_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
        
class Thread : public Object
{

public:

    /**
     * @brief Maximum thead priority.
     */
    static const int32_t MAX_PRIORITY  = 10;

    /**
     * @brief Minimum thead priority.
     */
    static const int32_t MIN_PRIORITY  = 1;

    /**
     * @brief Normal thead priority.
     */
    static const int32_t NORM_PRIORITY = 5;

    /**
     * @brief Thead locked on executing priority.
     */
    static const int32_t LOCK_PRIORITY  = 0;

    /**
     * @brief Thread available statuses.
     *
     * Thread status state machine:
     * (NEW)->(RUNNABLE)<->(RUNNING)->(DEAD)
     *           |<-(SLEEPING)<-|
     *           |<-(BLOCKED) <-|
     */
    enum Status
    {
        NEW      = 0, //< Thread is constructed
        RUNNABLE = 1, //< Thread is set with execute()
        RUNNING  = 2, //< Thread is run
        BLOCKED  = 4, //< Thread is blocked on a resource
        SLEEPING = 5, //< Thread is sleeping on a resource
        DEAD     = 6  //< Thread is dead because it finished execution
    };
    
    /**
     * @brief Maximum thead priority.
     */
    static const int32_t WRONG_ID = -1;    

    /**
     * @brief Destructor.
     */
    virtual ~Thread() = 0;

    /**
     * @brief Causes this thread to begin execution.
     */
    virtual void execute() = 0;

    /**
     * @brief Waits for this thread to die.
     */
    virtual void join() = 0;

    /**
     * @brief Returns the identifier of this thread.
     *
     * @return the thread identifier, or -1 if an error has been occurred.
     */
    virtual int64_t getId() const = 0;

    /**
     * @brief Returns this thread priority.
     *
     * @return priority value, or -1 if an error has been occurred.
     */
    virtual int32_t getPriority() const = 0;

    /**
     * @brief Sets this thread priority.
     *
     * @param priority - number of priority in range [MIN_PRIORITY, MAX_PRIORITY], or LOCK_PRIORITY.
     */
    virtual void setPriority(int32_t priority) = 0;

    /**
     * @brief Returns a status of this thread.
     *
     * @return this thread status.
     */
    virtual Status getStatus() const = 0;
    
    /**
     * @brief Returns an error of this thread task execution.
     *
     * @return an execution error.
     */
    virtual int32_t getExecutionError() const = 0;

};

inline Thread::~Thread() {}
        
} // namespace api
} // namespace eoos
#endif // API_THREAD_HPP_

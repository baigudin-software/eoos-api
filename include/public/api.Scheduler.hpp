/**
 * @brief Threads scheduler interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SCHEDULER_HPP_
#define API_SCHEDULER_HPP_

#include "api.Object.hpp"
#include "api.Thread.hpp"
#include "api.Task.hpp"
#include "api.Toggle.hpp"

namespace eoos
{
namespace api
{
        
class Scheduler : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Scheduler() = 0;

    /**
     * @brief Creates a new thread.
     *
     * @param task - an user task which main method will be invoked when created thread is started.
     * @return a new thread.
     */
    virtual Thread* createThread(Task& task) = 0;

    /**
     * @brief Returns currently executing thread.
     *
     * @return executing thread.
     */
    virtual Thread& getCurrentThread() const = 0;
    
    /**
     * @brief Causes current thread to sleep.
     *
     * @param millis - a time to sleep in milliseconds.
     * @param nanos  - an additional nanoseconds to sleep.
     */
    virtual void sleepCurrentThread(int64_t millis, int32_t nanos = 0) = 0;    

    /**
     * @brief Yields to next thread.
     */
    virtual void yield() = 0;

    /**
     * @brief Returns the toggle interface for controlling global thread switching.
     *
     * @return Toggle interface to disable and enable thread switching.
     */
    virtual Toggle& toggle() = 0;

};

inline Scheduler::~Scheduler() {}

} // namespace api
} // namespace eoos
#endif // API_SCHEDULER_HPP_

/**
 * @file      api.Scheduler.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
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
    
/**
 * @class Scheduler
 * @brief Threads scheduler interface.
 */
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
     * @param task An user task which main method will be invoked when created thread is started.
     * @return A new thread.
     */
    virtual Thread* createThread(Task& task) = 0;
    
    /**
     * @brief Causes current thread to sleep.
     *
     * @param millis A time to sleep in milliseconds.
     * @param nanos  An additional nanoseconds to sleep.
     */
    virtual void sleep(int64_t millis, int32_t nanos = 0) = 0;    

    /**
     * @brief Yields to next thread.
     */
    virtual void yield() = 0;

};

inline Scheduler::~Scheduler() {}

} // namespace api
} // namespace eoos
#endif // API_SCHEDULER_HPP_

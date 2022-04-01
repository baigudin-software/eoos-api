/**
 * @file      api.SysThread.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYSTHREAD_HPP_
#define API_SYSTHREAD_HPP_

#include "api.Thread.hpp"
#include "api.SysResource.hpp"

namespace eoos
{
namespace api
{

/**
 * @class SysThread
 * @brief System thread interface.
 */        
class SysThread : public Thread
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SysThread() = 0;

    /**
     * @brief Causes this thread to sleep.
     *
     * @param millis A time to sleep in milliseconds.
     * @param nanos  An additional nanoseconds to sleep.
     */
    virtual void sleep(int64_t millis, int32_t nanos = 0) = 0;

    /**
     * @brief Blocks this thread on given resource and yields the task.
     *
     * @param res A resource.
     */
    virtual void block(SysResource& res) = 0;

};

inline SysThread::~SysThread() {}
        
} // namespace api
} // namespace eoos
#endif // API_SYSTHREAD_HPP_

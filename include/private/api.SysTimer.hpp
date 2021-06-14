/**
 * @file      api.SysTimer.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYS_TIMER_HPP_
#define API_SYS_TIMER_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class SysTimer
 * @brief Hardware system timer resource interface.
 */
class SysTimer : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SysTimer() = 0;

    /**
     * @brief Gets this timer counter.
     *
     * @return Timer counter register value.
     */
    virtual int64_t getCount() const = 0;

    /**
     * @brief Gets this timer period.
     *
     * @return Timer period register value.
     */
    virtual int64_t getPeriod() const = 0;

    /**
     * @brief Sets this timer counter.
     *
     * @param count Timer counter register value.
     */
    virtual void setCount(int64_t count) = 0;

    /**
     * @brief Sets this timer period.
     *
     * @param us Timer period in microseconds, zero value sets a period to maximum value.
     */
    virtual void setPeriod(int64_t us=0) = 0;

    /**
     * @brief Starts this timer count.
     */
    virtual void start() = 0;

    /**
     * @brief Stops this timer count.
     */
    virtual void stop() = 0;

    /**
     * @brief Returns this timer index.
     *
     * @return Index of this timer, or -1 if an error has been occurred.
     */
    virtual int32_t getIndex() const = 0;

};

inline SysTimer::~SysTimer() {}

} // namespace api
} // namespace eoos
#endif // API_SYS_TIMER_HPP_

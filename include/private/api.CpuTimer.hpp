/**
 * @file      api.CpuTimer.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_CPU_TIMER_HPP_
#define API_CPU_TIMER_HPP_

#include "api.SysTimer.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class CpuTimer
 * @brief A central processing unit timer resource interface.
 */
class CpuTimer : public SysTimer
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~CpuTimer() = 0;

    /**
     * @brief Returns number of timer digits.
     *
     * @return Timer digits.
     */
    virtual int32_t getDigit() const = 0;

    /**
     * @brief Returns this timer internal clock in Hz.
     *
     * @return Timer internal clock.
     */
    virtual int64_t getInternalClock() const = 0;

    /**
     * @brief Returns an available interrupt source for this timer.
     *
     * @return Available interrupt source, or -1 if an error has been occurred.
     */
    virtual int32_t getInterrupSource() const = 0;

};

inline CpuTimer::~CpuTimer() {}

} // namespace api
} // namespace eoos
#endif // API_CPU_TIMER_HPP_

/**
 * A central processing unit timer resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2018, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_CPU_TIMER_HPP_
#define API_CPU_TIMER_HPP_

#include "api.Timer.hpp"

namespace eoos
{
    namespace api
    {
        class CpuTimer : public api::Timer
        {

        public:

            /**
             * Destructor.
             */
            virtual ~CpuTimer(){}

            /**
             * Returns number of timer digits.
             *
             * @return timer digits.
             */
            virtual int32_t getDigit() const = 0;

            /**
             * Returns this timer internal clock in Hz.
             *
             * @return timer internal clock.
             */
            virtual int64_t getInternalClock() const = 0;

            /**
             * Returns an available interrupt source for this timer.
             *
             * @return available interrupt source, or -1 if an error has been occurred.
             */
            virtual int32_t getInterrupSource() const = 0;

        };
    }
}
#endif // API_CPU_TIMER_HPP_

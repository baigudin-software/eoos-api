/**
 * A central processing unit phase-locked loop controller resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_CPU_PLL_HPP_
#define API_CPU_PLL_HPP_

#include "api.Object.hpp"

namespace eoos
{
    namespace api
    {
        class CpuPll : public api::Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~CpuPll(){}

            /**
             * Returns source clock of CPU oscillator in Hz.
             *
             * @return frequency value in Hz.
             */
            virtual int64_t getSourceClock() = 0;

            /**
             * Returns source clock of CPU in Hz.
             *
             * @return frequency value in Hz.
             */
            virtual int64_t getCpuClock() = 0;

        };
    }
}
#endif // API_CPU_PLL_HPP_

/**
 * The configuration of a target processor.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef CONFIGURATION_HPP_
#define CONFIGURATION_HPP_

#include "Types.hpp"

namespace eoos
{
    struct Configuration
    {

    public:

        /**
         * Stack size in bytes for the first user thread to be created.
         */
        int32_t stackSize;

        #ifdef EOOS_NO_STRICT_MISRA_RULES

        /**
         * Start address of heap memory.
         */
        int32_t heapAddr;

        /**
         * Size of heap memory in bytes.
         */
        size_t heapSize;

        #endif // EOOS_NO_STRICT_MISRA_RULES

        /**
         * Source clock of CPU oscillator in Hz.
         */
        int64_t sourceClock;

        /**
         * CPU clock in Hz.
         */
        int64_t cpuClock;

        /**
         * Constructor.
         */
        Configuration();

        /**
         * Destructor.
         */
       ~Configuration()
        {
        }

    };
}
#endif // CONFIGURATION_HPP_

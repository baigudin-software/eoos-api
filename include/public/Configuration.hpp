/**
 * @file      Configuration.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef CONFIGURATION_HPP_
#define CONFIGURATION_HPP_

#include "Types.hpp"

namespace eoos
{

/**
 * @struct Configuration
 * @brief The configuration of a target processor.
 */
struct Configuration
{

    /**
     * @brief Stack size in bytes for the first user thread to be created.
     */
    int32_t stackSize;

    #ifdef EOOS_NO_STRICT_MISRA_RULES

    /**
     * @brief Start address of heap memory.
     */
    int32_t heapAddr;

    /**
     * @brief Size of heap memory in bytes.
     */
    size_t heapSize;

    #endif // EOOS_NO_STRICT_MISRA_RULES

    /**
     * @brief Source clock of CPU oscillator in Hz.
     */
    int64_t sourceClock;

    /**
     * @brief CPU clock in Hz.
     */
    int64_t cpuClock;

};

} // namespace eoos
#endif // CONFIGURATION_HPP_

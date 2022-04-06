/**
 * @file      api.CpuInterrupt.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_CPUINTERRUPT_HPP_
#define API_CPUINTERRUPT_HPP_

#include "api.Interrupt.hpp"
#include "api.Task.hpp"
#include "api.CpuRegisters.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class CpuInterrupt
 * @brief A central processing unit interrupt resource interface.
 */
class CpuInterrupt : public Interrupt
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~CpuInterrupt() = 0;

    /**
     * @brief Sets interrupt source handler.
     *
     * @param handler Pointer to user class which implements an interrupt handler interface.
     * @param source  Available interrupt source.
     * @return True if handler is set successfully.
     */
    virtual bool_t setHandler(Task& handler, int32_t source) = 0;

    /**
     * @brief Removes this interrupt source handler.
     */
    virtual void removeHandler() = 0;

    /**
     * @brief Sets new registers context for storing.
     *
     * Function sets a new register context for storing the CPU registers to it.
     * This function may be called in an user interrupt handler, it means
     * given conxet will be restored by the context restore procedure.
     *
     * @param reg A new registers context.
     */
    virtual void setContext(CpuRegisters& reg) = 0;

    /**
     * @brief Restores registers context for storing to the default.
     *
     * Function restores default registers for storing the CPU registers to it.
     * This function may be called in an user interrupt handler, it means
     * the default conxet will be restored with the context restore procedure.
     */
    virtual void restoreContext() = 0;

};

inline CpuInterrupt::~CpuInterrupt() {}

} // namespace api
} // namespace eoos
#endif // API_CPUINTERRUPT_HPP_

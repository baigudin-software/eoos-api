/**
 * @file      api.Cpu.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_CPU_HPP_
#define API_CPU_HPP_

#include "api.Object.hpp"
#include "api.Task.hpp"
#include "api.CpuPll.hpp"
#include "api.CpuInterrupt.hpp"
#include "api.CpuTimer.hpp"

namespace eoos
{
namespace api
{

/**
 * @class Cpu
 * @brief A target CPU interface.
 */    
class Cpu : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Cpu() = 0;

    /**
     * @brief Returns a name of a target Central Processing Unit.
     *
     * The function should return a certain name of target CPU,
     * or a complex name of CPUs family. In addition, the function
     * might return NULLPTR pointer if a target CPU name were undefined,
     * but basically the case is an exception.
     *
     * @return A CPU name, or NULLPTR if an error has been occurred.
     */
    virtual const char_t* getName() const = 0;

    /**
     * @brief Returns an ID of CPU core executing this program code.
     *
     * @return A CPU ID, or -1 if an error has been occurred.
     */
    virtual int32_t getCoreId() const = 0;

    /**
     * @brief Creates a new HW PLL resource.
     *
     * @return A new PLL resource, or NULLPTR if an error has been occurred.
     */
    virtual CpuPll* createPll() = 0;

    /**
     * @brief Creates a new HW interrupt resource.
     *
     * @param handler User class which implements an interrupt handler interface.
     * @param source  Available interrupt source number.
     * @return A new interrupt resource, or NULLPTR if an error has been occurred.
     */
    virtual CpuInterrupt* createInterrupt(Task& handler, int32_t source) = 0;

    /**
     * @brief Creates a new HW timer resource.
     *
     * @param index An available timer index.
     * @return A new timer resource, or NULLPTR if an error has been occurred.
     */
    virtual CpuTimer* createTimer(int32_t index) = 0;

};

inline Cpu::~Cpu() {}

} // namespace api
} // namespace eoos
#endif // API_CPU_HPP_

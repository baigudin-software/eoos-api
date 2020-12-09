/**
 * @brief A target CPU interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018-2020, Sergey Baigudin, Baigudin Software
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
     * @return a CPU name, or NULLPTR if an error has been occurred.
     */
    virtual const char_t* getName() const = 0;

    /**
     * @brief Returns an ID of CPU core executing this program code.
     *
     * @return a CPU ID, or -1 if an error has been occurred.
     */
    virtual int32_t getCoreId() const = 0;

    /**
     * @brief Creates a new HW PLL resource.
     *
     * @return a new PLL resource, or NULLPTR if an error has been occurred.
     */
    virtual CpuPll* createPll() = 0;

    /**
     * @brief Creates a new HW interrupt resource.
     *
     * @param handler - user class which implements an interrupt handler interface.
     * @param source  - available interrupt source number.
     * @return a new interrupt resource, or NULLPTR if an error has been occurred.
     */
    virtual CpuInterrupt* createInterrupt(Task& handler, int32_t source) = 0;

    /**
     * @brief Creates a new HW timer resource.
     *
     * @param index - an available timer index.
     * @return a new timer resource, or NULLPTR if an error has been occurred.
     */
    virtual CpuTimer* createTimer(int32_t index) = 0;

};

inline Cpu::~Cpu() {}

} // namespace api
} // namespace eoos
#endif // API_CPU_HPP_

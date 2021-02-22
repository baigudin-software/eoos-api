/**
 * @brief A central processing unit registers resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_CPU_REGISTERS_HPP_
#define API_CPU_REGISTERS_HPP_

#include "api.Object.hpp"
#include "api.SysStack.hpp"

namespace eoos
{
namespace api
{
    
class CpuRegisters : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~CpuRegisters() = 0;

    /**
     * @brief Initializes the CPU registers.
     *
     * The method is mostly used for restoring from an interrupt service routine.
     *
     * @param stack    - a routine stack.
     * @param entry    - a routine entry address.
     * @param argument - a routine argument.
     */
    virtual void setInitialization(SysStack<int64_t>& stack, void* entry, int32_t argument) = 0;

    /**
     * @brief Returns a pointer to the first register of CPU registers context.
     *
     * @return memory address of registers order, or NULLPTR if an error has been occurred.
     */
    virtual void* getRegisters() = 0;

};

inline CpuRegisters::~CpuRegisters() {}

} // namespace api
} // namespace eoos
#endif // API_CPU_REGISTERS_HPP_

/**
 * @file      api.CpuRegisters.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_CPUREGISTERS_HPP_
#define API_CPUREGISTERS_HPP_

#include "api.Object.hpp"
#include "api.SysStack.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class CpuRegisters
 * @brief A central processing unit registers resource interface.
 */
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
     * The function is mostly used for restoring from an interrupt service routine.
     *
     * @param stack    A routine stack.
     * @param entry    A routine entry address.
     * @param argument A routine argument.
     */
    virtual void setInitialization(SysStack<int64_t>& stack, void* entry, int32_t argument) = 0;

    /**
     * @brief Returns a pointer to the first register of CPU registers context.
     *
     * @return Memory address of registers order, or NULLPTR if an error has been occurred.
     */
    virtual void* getRegisters() = 0;

};

inline CpuRegisters::~CpuRegisters() {}

} // namespace api
} // namespace eoos
#endif // API_CPUREGISTERS_HPP_

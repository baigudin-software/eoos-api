/**
 * System class of the operating system.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#include "System.hpp"

namespace eoos
{
namespace sys
{
    
    /**
     * Calls the operating system kernel.
     *
     * @return the operating system syscall interface.
     */
    extern api::System& syscall();
    
} // namespace sys

api::System& System::call()
{
    static api::System& system = sys::syscall();
    return system;
}

} // namespace eoos

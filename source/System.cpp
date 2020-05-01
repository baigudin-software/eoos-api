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
    }

    /**
     * The operating system syscall interface.
     */
    static api::System* system_ = NULLPTR;

    /**
     * Returns the operating system syscall interface.
     *
     * @return the operating system syscall interface.
     */
    api::System& System::call()
    {
        if(system_ == NULLPTR)
        {
            system_ = &sys::syscall();
        }
        return *system_;
    }
}

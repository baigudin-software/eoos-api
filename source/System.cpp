/**
 * System class of the operating system.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#include "System.hpp"

namespace eoos
{
    namespace system
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
    static api::System* system_ = NULL;

    /**
     * Returns the operating system syscall interface.
     *
     * @return the operating system syscall interface.
     */
    api::System& System::call()
    {
        if(system_ == NULL)
        {
            system_ = &system::syscall();
        }
        return *system_;
    }
}

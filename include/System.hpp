/**
 * System class of the operating system.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "api.System.hpp"

namespace eoos
{
  class System
  {

  public:

      /**
       * Returns the operating system syscall interface.
       *
       * @return the operating system syscall interface.
       */
      static api::System& call();

  };
}
#endif // SYSTEM_HPP_

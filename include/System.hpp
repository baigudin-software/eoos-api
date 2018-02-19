/** 
 * System class of the operating system.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef GLOBAL_SYSTEM_HPP_
#define GLOBAL_SYSTEM_HPP_

#include "system.System.hpp"

namespace global
{
  class System
  {
    
  public:
  
      /** 
       * Returns the operating system syscall interface.
       *
       * @return the operating system syscall interface.
       */      
      static ::api::System& call()
      {
          return ::system::System::call();
      }
    
  };
}
#endif // GLOBAL_SYSTEM_HPP_

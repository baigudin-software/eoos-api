/** 
 * Processor board initialization.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef GLOBAL_BOARD_HPP_
#define GLOBAL_BOARD_HPP_

#include "api.Constant.hpp"
#include "Configuration.hpp"

namespace global
{
    class Board : ::api::Constant
    {
    
    public:
    
        /**
         * Initializes a processor board.
         *
         * @param config the operating system configuration.
         * @return true if no errors have been occurred.
         */   
        static bool initialize(const ::Configuration config);
        
        /**
         * Deinitializes a processor board.
         */
        static void deinitialize();
      
    };
}
#endif // GLOBAL_BOARD_HPP_ 

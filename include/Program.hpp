/** 
 * Entry point to an operating system main program.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef PROGRAM_HPP_
#define PROGRAM_HPP_

#include "api.Constant.hpp"

namespace global
{
    class Program : public api::Constant
    {

    public:
  
        /**
         * Starts executing an operating system main program.
         *
         * @return zero, or error code if an error has been occurred.
         */
        static int32 start();

    };
}
#endif // PROGRAM_HPP_

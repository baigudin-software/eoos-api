/** 
 * Entry point to an operating system main program.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef PROGRAM_HPP_
#define PROGRAM_HPP_

#include "Types.hpp"

namespace global
{
    class Program
    {

    public:
  
        /**
         * Starts executing an operating system main program.
         *
         * @return zero, or error code if an error has been occurred.
         */
        static int32 start();

        /**
         * Starts executing an operating system main program.
         *
         * @param arg - application arguments.
         * @return zero, or error code if an error has been occurred.
         */
        static int32 start(void* args);

    };
}
#endif // PROGRAM_HPP_

/** 
 * The operating system error codes.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef ERROR_HPP_
#define ERROR_HPP_

namespace global
{
    enum Error
    {
        /**
         * No errors have been occurred.
         */  
        ERROR_OK = 0,

        /**
         * Error of the operating system kernel syscall calling.
         */
        ERROR_SYSCALL_CALLED,
       
        /**
         * Error of a no strinct MISRA C++ function calling.
         */
        ERROR_NO_MISRA_FUNCTION_CALLED,

        /**
         * Error of a user program occurred.
         */            
        ERROR_USER_TERMINATION,
        
        /**
         * An undefined error has been occurred.
         */  
        ERROR_UNDEFINED,
        
        /**
         * An undefined error has been occurred.
         */  
        ERROR_LAST = 128          
        
    };
}
#endif /* ERROR_H_ */

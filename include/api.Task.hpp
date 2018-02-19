/**
 * Task interface.
 * 
 * The interface of a task that is being executed in self context.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_TASK_HPP_
#define API_TASK_HPP_

#include "api.Object.hpp"

namespace global
{
    namespace api
    {
        class Task : public api::Object
        {
        
        public:
    
            /** 
            * Destructor.
            */
            virtual ~Task(){}
            
            /**
            * Starts executing an operating system prorgam in itsself context.
            *
            * @return zero, or error code if an error has been occurred.         
            */  
            virtual int32 start() = 0;
            
            /**
            * Returns size of stack.
            *
            * The method returns size of stack in bytes which should be allocated for the task.
            *
            * @return stack size in bytes.
            */  
            virtual int32 getStackSize() const = 0;
    
        };
    }
}
#endif // API_TASK_HPP_

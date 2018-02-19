/**
 * The opearating system syscall interface.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_SYSTEM_HPP_
#define API_SYSTEM_HPP_

#include "api.Object.hpp"
#include "api.Kernel.hpp"

namespace api
{
    class System : public ::api::Object    
    {
      
    public:
  
        /**
         * Destructor.
         */
        virtual ~System(){}
          
        /**
         * Returns the operating system heap memory.
         *
         * @return the heap memory.
         */
        virtual ::api::Heap& getHeap() const = 0;
           
        /**
         * Returns running time of the operating system in nanoseconds.
         *
         * @return time in nanoseconds.
         */
        virtual int64 getTime() const = 0;
        
        /**
         * Terminates the operating system execution.
         */
        virtual void terminate() const = 0;

    };
}
#endif // API_SYSTEM_HPP_

/**
 * A kernel interface of the operating system.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_KERNEL_HPP_
#define API_KERNEL_HPP_

#include "api.Object.hpp"
#include "api.Runtime.hpp"
#include "api.Value.hpp"
#include "api.Scheduler.hpp"
#include "api.Mutex.hpp"
#include "api.Semaphore.hpp"
#include "api.Interrupt.hpp"
#include "api.Task.hpp"
#include "api.Toggle.hpp"
#include "api.Heap.hpp"

namespace api
{
    class Kernel : public ::api::Object
    {
    
    public:
    
        /** 
         * Destructor.
         */
        virtual ~Kernel(){}
        
        /** 
         * Returns a default size of stack in bytes.
         *
         * @return a size of stack in bytes.
         */ 
        virtual int32 getStackSize() const = 0;
          
        /**
         * Returns the kernel heap memory.
         *
         * @return the kernel heap memory.
         */
        virtual ::api::Heap& getHeap() const = 0;
        
        /** 
         * Returns the kernel runtime environment.
         *
         * @return the kernel runtime environment.
         */      
        virtual ::api::Runtime& getRuntime() const = 0;        
        
        /** 
         * Returns a value of the kernel running time in nanoseconds.
         *
         * @return the running time in nanoseconds.
         */      
        virtual ::api::Value<int64>& getExecutionTime() const = 0;
        
        /** 
         * Returns the kernel scheduler.
         *
         * @return the kernel scheduler.
         */      
        virtual ::api::Scheduler& getScheduler() const = 0;        
        
        /** 
         * Returns a global interrupt controller.
         *
         * @return a global interrupt controller.
         */      
        virtual ::api::Toggle& getGlobalInterrupt() const = 0;

        /** 
         * Creates a new mutex resource.
         *
         * @return a new mutex resource, or NULL if an error has been occurred.
         */      
        virtual ::api::Mutex* createMutex() = 0;
        
        /** 
         * Creates a new unfair semaphore resource.
         *
         * @param permits the initial number of permits available.   
         * @return a new semaphore resource, or NULL if an error has been occurred.
         */      
        virtual ::api::Semaphore* createSemaphore(int32 permits) = 0;
        
        /** 
         * Creates a new semaphore resource.
         *
         * @param permits the initial number of permits available.      
         * @param isFair  true if this semaphore will guarantee FIFO granting of permits under contention.
         * @return a new semaphore resource, or NULL if an error has been occurred.         
         */      
        virtual ::api::Semaphore* createSemaphore(int32 permits, bool isFair) = 0;
        
        /**
         * Creates a new interrupt resource.
         *
         * @param handler user class which implements an interrupt handler interface.
         * @param source  available interrupt source number.
         * @return a new interrupt resource, or NULL if an error has been occurred.
         */  
        virtual ::api::Interrupt* createInterrupt(::api::Task& handler, int32 source) = 0;

    };
}
#endif // API_KERNEL_HPP_

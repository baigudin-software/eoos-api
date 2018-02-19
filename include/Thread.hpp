/**
 * The operating system thread.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef THREAD_HPP_
#define THREAD_HPP_

#include "Object.hpp"
#include "api.Thread.hpp"
#include "System.hpp"

namespace global
{
    class Thread : public Object<>, public api::Thread, public api::Task
    {
        typedef Object<> Parent;
      
    public:
    
        /** 
         * Constructor.
         */
        Thread() : Parent(),
            isConstructed_ (getConstruct()),
            thread_        (NULL){
            setConstruct( construct(*this) );
        }        
    
        /** 
         * Constructor.
         *
         * @param task an task interface whose main method is invoked when this thread is started.
         */
        Thread(api::Task& task) : Parent(),
            isConstructed_ (getConstruct()),
            thread_        (NULL){
            setConstruct( construct(task) );
        }
        
        /** 
         * Destructor.
         */
        virtual ~Thread()
        {
            delete thread_;
        }
        
        /**
         * The method with self context which will be executed by default.
         */  
        virtual void main() = 0;    
        
        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */    
        virtual bool isConstructed() const
        {
            return isConstructed_;
        } 
        
        /**
         * Returns size of task stack.
         *
         * @return stack size in bytes.
         */  
        virtual int32 getStackSize() const
        {
            return 0x1000;
        }
        
        /**
         * Causes this thread to begin execution.
         */
        virtual void start()
        {
            if( isConstructed_ )
            {
                thread_->start();    
            }
        }
        
        /**
         * Waits for this thread to die.
         */  
        virtual void join()
        {
            if( isConstructed_ )
            {
                thread_->join();
            }
        }
      
        /**
         * Causes this thread to sleep.
         *
         * @param millis a time to sleep in milliseconds.
         * @param nanos  an additional nanoseconds to sleep.
         */  
        virtual void sleep(const int64 millis, const int32 nanos=0)
        {
            if( isConstructed_ )
            {
                thread_->sleep(millis, nanos);    
            }
        }        
        
        /**
         * Blocks this thread on given resource and yields the task.
         *
         * @param res a resource.
         */  
        virtual void block(api::Resource& res)
        {
            if( isConstructed_ )
            {
                return thread_->block(res);    
            }
        }
        
        /**
         * Returns the identifier of this thread.
         *
         * @return the thread identifier.
         */
        virtual int64 getId() const
        {
            if( isConstructed_ ) 
            {
                return thread_->getId();
            }
            else
            {
                return -1;             
            }
        }
    
        /**
         * Returns a status of this thread.
         *
         * @return this thread status.
         */  
        virtual api::Thread::Status getStatus() const
        {
            if( isConstructed_ ) 
            {
                return thread_->getStatus();    
            }
            else
            {
                return DEAD;             
            }
        }                
      
        /**
         * Returns this thread priority.
         *
         * @return priority value.
         */  
        virtual int32 getPriority() const
        {
            if( isConstructed_ ) 
            {
                return thread_->getPriority();    
            }
            else
            {
                return -1;             
            }
        }        
      
        /**
         * Sets this thread priority.
         *
         * @param priority number of priority in range [MIN_PRIORITY, MAX_PRIORITY], or LOCK_PRIORITY.
         */  
        virtual void setPriority(const int32 priority)
        {
            if( isConstructed_ )
            {
                thread_->setPriority(priority);
            }
        }
      
        /**
         * Returns currently executing thread.
         *
         * @return executing thread.
         */
        static api::Thread& getCurrent()
        {
            return System::call().getKernel().getScheduler().getCurrentThread();
        }        
        
        /**
         * Causes current thread to sleep.
         *
         * @param millis a time to sleep in milliseconds.
         * @param nanos  an additional nanoseconds to sleep.
         */  
        static void sleepCurrent(const int64 millis, const int32 nanos=0)
        {
            getCurrent().sleep(millis, nanos);
        }        
        
        /**
         * Yields to next thread.
         */
        static void yield()
        {
            return System::call().getKernel().getScheduler().yield();     
        }
        
        /** 
         * Returns the toggle interface for controlling global thread switching.
         *
         * @return toggle interface.
         */ 
        static api::Toggle& toggle()
        {
            return System::call().getKernel().getScheduler().toggle();    
        }
            
    private:
        
        /**
         * Constructor.
         *
         * @param task an task interface whose main method is invoked when this thread is started.     
         * @return true if object has been constructed successfully.   
         */
        bool construct(api::Task& task)
        {
            if( not isConstructed_ ) 
            {
                return false; 
            }
            thread_ = System::call().getKernel().getScheduler().createThread(task);
            return thread_ == NULL || not thread_->isConstructed() ? false : true; 
        }        
                
        /**
         * Copy constructor.
         *
         * @param obj reference to source object.
         */
        Thread(const Thread& obj);
        
        /**
         * Assignment operator.
         *
         * @param obj reference to source object.
         * @return reference to this object.     
         */
        Thread& operator =(const Thread& obj);
        
        /** 
         * The root object constructed flag.
         */  
        const bool& isConstructed_;
        
        /** 
         * A kernel scheduler thread.
         */          
        api::Thread* thread_;
    
    };
}
#endif // THREAD_HPP_

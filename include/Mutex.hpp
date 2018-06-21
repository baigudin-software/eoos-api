/** 
 * Mutex class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include "Object.hpp"
#include "api.Mutex.hpp"
#include "System.hpp"

namespace global
{
    class Mutex : public Object<>, public api::Mutex
    {
        typedef Object<> Parent;
    
    public:
    
        /** 
         * Constructor.
         */    
        Mutex() : Parent(),
            isConstructed_ (getConstruct()),
            mutex_         (NULL){
            setConstruct( construct() ); 
        }    
        
        /** 
         * Destructor.
         */      
        virtual ~Mutex()
        {
            delete mutex_;
        }
            
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
         * Locks the mutex.
         *
         * @return true if the mutex is lock successfully.
         */      
        virtual bool lock()
        {
            if( isConstructed_ ) 
            {
                return mutex_->lock();            
            }
            else
            {
                return false;
            }
        }
        
        /**
         * Unlocks the mutex.
         */      
        virtual void unlock()
        {
            if( isConstructed_ ) 
            {
                mutex_->unlock();            
            }
        }
        
        /** 
         * Tests if this resource is blocked.
         *
         * @return true if this resource is blocked.
         */ 
        virtual bool isBlocked()
        {
            if( isConstructed_ ) 
            {
                return mutex_->isBlocked();            
            }
            else
            {
                return false;
            }
        }
    
    private:
      
        /**
         * Constructor.
         *
         * @return true if object has been constructed successfully.   
         */
        bool construct()
        {
            if( not isConstructed_ ) 
            {
                return false;
            }
            mutex_ = System::call().getKernel().createMutex();
            return mutex_ != NULL ? mutex_->isConstructed() : false;        
        }
    
        /**
         * Copy constructor.
         *
         * @param obj - reference to source object.
         */
        Mutex(const Mutex& obj);
      
        /**
         * Assignment operator.
         *
         * @param obj - reference to source object.
         * @return reference to this object.     
         */
        Mutex& operator =(const Mutex& obj);
        
        /** 
         * The root object constructed flag.
         */  
        const bool& isConstructed_;    
      
        /**
         * System mutex interface.
         */    
        api::Mutex* mutex_;
    
    };
}
#endif // SYSTEM_MUTEX_HPP_

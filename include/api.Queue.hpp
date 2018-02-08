/** 
 * Queue interface.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_QUEUE_HPP_
#define API_QUEUE_HPP_

#include "api.Collection.hpp"
#include "api.IllegalValue.hpp"

namespace api
{
    /** 
     * @param Type data type of queue element.
     */
    template <typename Type>
    class Queue : public ::api::Collection<Type>, public ::api::IllegalValue<Type>
    {
      
    public:
    
        /**
         * Destructor.
         */
        virtual ~Queue(){}
        
        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */    
        virtual bool isConstructed() const = 0;        
        
        /**
         * Inserts new element to this container.
         *
         * @param element inserting element.
         * @return true if element is added.
         */      
        virtual bool add(Type element) = 0;
        
        /**
         * Removes the head element of this container.
         *
         * @return true if an element is removed successfully.
         */
        virtual bool remove() = 0;
        
        /**
         * Examines the head element of this container.
         *
         * @return the head element.
         */
        virtual Type peek() const = 0;
      
    };
}
#endif // API_QUEUE_HPP_

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

namespace global
{
    namespace api
    {
        /** 
         * @param T data type of queue element.
         */
        template <typename T>
        class Queue : public api::Collection<T>, public api::IllegalValue<T>
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
             * NOTE: A passed element must be copied to an internal data structure of 
             * a realizing class by calling a copy constructor so that the element 
             * might be invalidated after the function called.         
             *
             * @param element inserting element.
             * @return true if element is added.
             */      
            virtual bool add(const T& element) = 0;
            
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
            virtual const T& peek() const = 0;
        
        };
    }
}
#endif // API_QUEUE_HPP_

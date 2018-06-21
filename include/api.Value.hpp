/**
 * Interface of setting and getting a value.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_VALUE_HPP_
#define API_VALUE_HPP_

#include "api.IllegalValue.hpp"

namespace global
{
    namespace api
    {
        /** 
         * Primary template implementation.        
         *
         * @param T - data type of list element.
         */ 
        template <typename T>    
        class Value : public api::IllegalValue<T>    
        {
    
        public:
      
            /** 
             * Destructor.
             */
            virtual ~Value(){}
            
            /**
             * Sets a value.
             *
             * NOTE: A passed value must be copied to an internal data structure of 
             * a realizing class by calling a copy constructor so that the variable 
             * might be invalidated after the function called.                  
             *
             * @param value - a value for setting.
             */    
            virtual void setValue(const T& value) = 0;
              
            /**
             * Returns set value.
             *
             * @return the set value.
             */      
            virtual const T& getValue() const = 0;
    
        };
    }
}
#endif // API_VALUE_HPP_

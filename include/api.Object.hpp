/**
 * Root interface of the system class hierarchy.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2016, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_OBJECT_HPP_
#define API_OBJECT_HPP_

#include "api.Constant.hpp"

namespace global
{
    namespace api
    {  
        class Object : public api::Constant
        {
    
        public:
        
            /** 
            * Destructor.
            */
            virtual ~Object(){}
            
            /**
            * Tests if this object has been constructed.
            *
            * @return true if object has been constructed successfully.
            */    
            virtual bool isConstructed() const = 0;
        
        };
    }
}
#endif // API_OBJECT_HPP_

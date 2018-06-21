/** 
 * A target CPU interface.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_CPU_HPP_
#define API_CPU_HPP_

#include "api.Object.hpp"

namespace global
{
    namespace api
    {
        class Cpu : public api::Object
        {
    
        public:
            
            /** 
             * Destructor.
             */                               
            virtual ~Cpu(){}
            
            /**
             * Returns a name of a target Central Processing Unit. 
             *
             * The function should return a certain name of target CPU, 
             * or a complex name of CPUs family. In addition, the function 
             * might return NULL pointer if a target CPU name were undefined, 
             * but basically the case is an exception.
             *
             * @return a CPU name, or NULL if an error has been occurred.
             */      
            virtual const char* getName() const = 0;
        
        };
    }
}
#endif // API_CPU_HPP_

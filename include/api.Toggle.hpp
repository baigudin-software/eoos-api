/** 
 * Toggle interface of some controllers.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_TOGGLE_HPP_
#define API_TOGGLE_HPP_

#include "api.Object.hpp"

namespace global
{
    namespace api
    {
        class Toggle : public api::Object
        {
      
        public:
          
            /** 
             * Destructor.
             */                               
            virtual ~Toggle(){}
            
            /** 
             * Disables a controller.
             *
             * @return an enable source bit value of a controller before method was called.
             */ 
            virtual bool disable() = 0;
            
            /** 
             * Enables a controller.
             *
             * The true passed argument directly turns a controller on, 
             * and the false does nothing, a controller stays in the current state.
             * 
             * @param status - returned status by disable method, or true for directly turning a controller on.
             */    
            virtual void enable(bool status = true) = 0;
    
        };
    }
}
#endif // API_TOGGLE_HPP_

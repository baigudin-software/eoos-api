/** 
 * Global constants.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_CONSTANT_HPP_
#define API_CONSTANT_HPP_

#include "Types.hpp"

namespace global
{
    namespace api
    {
        struct Constant
        {
            #if __cplusplus >= 201103L  
            typedef decltype(nullptr)  nullptr_t;            
            #else  // __cplusplus < 201103L 
            typedef signed int nullptr_t;
            #endif // __cplusplus
            
        public:
            
            #if __cplusplus >= 201103L  
            
            /**
             * NULL definition since C++11.
             */
            static const nullptr_t NULL = nullptr;
            
            #else // __cplusplus < 201103L  
                
            /**
             * NULL definition until C++11.
             */        
            static const nullptr_t NULL = 0;
            
            #endif // __cplusplus
    
        };

    }
}
#endif // API_CONSTANT_HPP_   

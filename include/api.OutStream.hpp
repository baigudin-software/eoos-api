/**
 * Output stream interface.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/ 
 */
#ifndef API_OUT_STREAM_HPP_
#define API_OUT_STREAM_HPP_

#include "api.Object.hpp"
#include "api.String.hpp"

namespace global
{
    namespace api
    {
        /**
        * @param T data type of string characters.     
        */    
        template <typename T>     
        class OutStream : public api::Object
        {
        
        public:
        
            /** 
            * Destructor.
            */
            virtual ~OutStream(){}
            
            /** 
            * Writes to an output stream.
            *
            * @param source a source character string to be output.
            * @return this interface.
            */    
            virtual api::OutStream<T>& operator <<(const T* source) = 0;
    
        };
    }
}
#endif // API_OUT_STREAM_HPP_

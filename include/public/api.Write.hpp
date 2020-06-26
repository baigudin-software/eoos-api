/**
 * Stream read interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_WRITE_HPP_
#define API_WRITE_HPP_

#include "api.Object.hpp"

namespace eoos
{
    namespace api
    {
        class Write : public Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Write(){}
        
            /**
             * Writes data to a stream.
             *
             * @param data - Pointer to data.
             * @param size - Size of data in Bytes.
             * @return number of bytes written.
             */
            virtual size_t write(const void* data, size_t size) = 0;
            
        };

    }
}
#endif // API_WRITE_HPP_

/**
 * @file      api.OutStream.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_OUTSTREAM_HPP_
#define API_OUTSTREAM_HPP_

#include "api.Object.hpp"
#include "api.String.hpp"

namespace eoos
{
namespace api
{
        
/**
 * @class OutStream<T>
 * @brief Output stream interface.
 *
 * @tparam T Data type to output.
 */
template <typename T>
class OutStream : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~OutStream() = 0;

    /**
     * @brief Writes to an output stream.
     *
     * @param source A source character string to be output.
     * @return This interface.
     */
    virtual OutStream<T>& operator<<(T const* source) = 0;

    /**
     * @brief Flushs buffered data to a storage device.
     *
     * @return This interface.
     */    
    virtual OutStream<T>& flush() = 0;

};

template <typename T> ///< SCA MISRA-C++:2008 Defected Rule 7-3-1
inline OutStream<T>::~OutStream() {}
        
} // namespace api
} // namespace eoos
#endif // API_OUT_STREAM_HPP_

/**
 * @brief Output stream interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_OUT_STREAM_HPP_
#define API_OUT_STREAM_HPP_

#include "api.Object.hpp"
#include "api.String.hpp"

namespace eoos
{
namespace api
{
        
/**
 * @brief Primary template implementation.
 *
 * @tparam T - data type of string characters.
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
     * @param source - a source character string to be output.
     * @return this interface.
     */
    virtual OutStream<T>& operator<<(const T* source) = 0;

};

template <typename T>
inline OutStream<T>::~OutStream() {}
        
} // namespace api
} // namespace eoos
#endif // API_OUT_STREAM_HPP_
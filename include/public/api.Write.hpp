/**
 * @file      api.Write.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2020-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_WRITE_HPP_
#define API_WRITE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class Write
 * @brief Stream write interface.
 */
class Write : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Write() = 0;

    /**
     * @brief Writes data to a stream.
     *
     * @param data Pointer to data.
     * @param size Size of data in Bytes.
     * @return Number of bytes written.
     */
    virtual size_t write(void const* data, size_t size) = 0;
    
};

inline Write::~Write() {}

} // namespace api
} // namespace eoos
#endif // API_WRITE_HPP_

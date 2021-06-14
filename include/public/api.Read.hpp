/**
 * @file      api.Read.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2020-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_READ_HPP_
#define API_READ_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class Read
 * @brief Stream read interface.
 */        
class Read : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Read() = 0;

    /**
     * @brief Reads data from a stream.
     *
     * @param data Pointer to data.
     * @param size Size of data in Bytes.
     * @return Number of read bytes.
     */
    virtual size_t read(void* data, size_t size) const = 0;
    
};

inline Read::~Read() {}

} // namespace api
} // namespace eoos
#endif // API_READ_HPP_

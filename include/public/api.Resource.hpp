/**
 * @file      api.Resource.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2023, Sergey Baigudin, Baigudin Software
 */
#ifndef API_RESOURCE_HPP_
#define API_RESOURCE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class Resource
 * @brief Resource interface.
 */    
class Resource : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Resource() = 0;
    
    /**
     * @brief Returns resource identifier.
     *
     * @return A resource identifier, or -1 if the resource has no identifier.
     */
    virtual int32_t getId() const = 0;

};

inline Resource::~Resource() {}

} // namespace api
} // namespace eoos
#endif // API_RESOURCE_HPP_

/**
 * @file      api.SysResource.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYSRESOURCE_HPP_
#define API_SYSRESOURCE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class SysResource
 * @brief System resource interface.
 */    
class SysResource : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SysResource() = 0;

    /**
     * @brief Tests if this resource is blocked.
     *
     * @return True if this resource is blocked.
     */
    virtual bool_t isBlocked() const = 0;

};

inline SysResource::~SysResource() {}

} // namespace api
} // namespace eoos
#endif // API_SYSRESOURCE_HPP_

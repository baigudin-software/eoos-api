/**
 * @brief System resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYS_RESOURCE_HPP_
#define API_SYS_RESOURCE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
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
     * @return true if this resource is blocked.
     */
    virtual bool_t isBlocked() const = 0;

};

inline SysResource::~SysResource() {}

} // namespace api
} // namespace eoos
#endif // API_SYS_RESOURCE_HPP_

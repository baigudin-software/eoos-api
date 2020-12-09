/**
 * @brief Resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_RESOURCE_HPP_
#define API_RESOURCE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
class Resource : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Resource() = 0;

    /**
     * @brief Tests if this resource is blocked.
     *
     * @return true if this resource is blocked.
     */
    virtual bool_t isBlocked() const = 0;

};

inline Resource::~Resource() {}

} // namespace api
} // namespace eoos
#endif // API_RESOURCE_HPP_

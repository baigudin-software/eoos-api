/**
 * @brief Mutex interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYS_MUTEX_HPP_
#define API_SYS_MUTEX_HPP_

#include "api.Mutex.hpp"
#include "api.SysResource.hpp"

namespace eoos
{
namespace api
{
    
class SysMutex : public Mutex, public SysResource
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SysMutex() = 0;

};

inline SysMutex::~SysMutex() {}

} // namespace api
} // namespace eoos
#endif // API_SYS_MUTEX_HPP_

/**
 * @file      api.SysMutex.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2021-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYSMUTEX_HPP_
#define API_SYSMUTEX_HPP_

#include "api.Mutex.hpp"
#include "api.SysResource.hpp"

namespace eoos
{
namespace api
{

/**
 * @class SysMutex
 * @brief System mutex interface.
 */    
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
#endif // API_SYSMUTEX_HPP_

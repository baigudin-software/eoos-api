/**
 * @file      api.SysInterrupt.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYSINTERRUPT_HPP_
#define API_SYSINTERRUPT_HPP_

#include "api.Toggle.hpp"

namespace eoos
{
namespace api
{

/**
 * @class SysInterrupt
 * @brief Hardware system interrupt interface.
 */    
class SysInterrupt : public Toggle
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SysInterrupt() = 0;

    /**
     * @brief Jumps to interrupt hardware vector.
     */
    virtual void jump() = 0;

    /**
     * @brief Clears an interrupt status of this source.
     */
    virtual void clear() = 0;

    /**
     * @brief Sets an interrupt status of this source.
     */
    virtual void set() = 0;

};

inline SysInterrupt::~SysInterrupt() {}

} // namespace api
} // namespace eoos
#endif // API_SYSINTERRUPT_HPP_

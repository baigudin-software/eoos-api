/**
 * @brief Hardware interrupt interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_INTERRUPT_HPP_
#define API_INTERRUPT_HPP_

#include "api.Toggle.hpp"

namespace eoos
{
namespace api
{
    
class Interrupt : public Toggle
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Interrupt() = 0;

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

inline Interrupt::~Interrupt() {}

} // namespace api
} // namespace eoos
#endif // API_INTERRUPT_HPP_

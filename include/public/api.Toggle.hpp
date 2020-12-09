/**
 * @brief Toggle interface of some controllers.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_TOGGLE_HPP_
#define API_TOGGLE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
        
class Toggle : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Toggle() = 0;

    /**
     * @brief Disables a controller.
     *
     * @return an enable source bit value of a controller before method was called.
     */
    virtual bool_t disable() = 0;

    /**
     * @brief Enables a controller.
     *
     * The true passed argument directly turns a controller on,
     * and the false does nothing, a controller stays in the current state.
     *
     * @param status - returned status by disable method, or true for directly turning a controller on.
     */
    virtual void enable(bool_t status = true) = 0;

};

inline Toggle::~Toggle() {}

} // namespace api
} // namespace eoos
#endif // API_TOGGLE_HPP_

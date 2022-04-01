/**
 * @file      api.Toggle.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_TOGGLE_HPP_
#define API_TOGGLE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class Toggle
 * @brief Toggle interface of some controllers.
 */
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
     * @return An enable source bit value of a controller before method was called.
     */
    virtual bool_t disable() = 0;

    /**
     * @brief Enables a controller.
     *
     * The true passed argument directly turns a controller on,
     * and the false does nothing, a controller stays in the current state.
     *
     * @param status Returned status by disable method, or true for directly turning a controller on.
     */
    virtual void enable(bool_t status = true) = 0;

};

inline Toggle::~Toggle() {}

} // namespace api
} // namespace eoos
#endif // API_TOGGLE_HPP_

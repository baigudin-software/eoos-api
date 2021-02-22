/**
 * @brief Interface of setting and getting a value.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_VALUE_HPP_
#define API_VALUE_HPP_

#include "api.IllegalValue.hpp"

namespace eoos
{
namespace api
{
        
/**
 * @brief Primary template implementation.
 *
 * @tparam T - data type of list element.
 */
template <typename T>
class Value : public IllegalValue<T>
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Value() = 0;

    /**
     * @brief Sets a value.
     *
     * NOTE: A passed value must be copied to an internal data structure of
     * a realizing class by calling a copy constructor so that the variable
     * might be invalidated after the function called.
     *
     * @param value - a value for setting.
     */
    virtual void setValue(const T& value) = 0;

    /**
     * @brief Returns set value.
     *
     * @return the set value.
     */
    virtual T& getValue() const = 0;

};

template <typename T>
inline Value<T>::~Value() {}

} // namespace api
} // namespace eoos
#endif // API_VALUE_HPP_

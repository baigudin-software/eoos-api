/**
 * @file      api.Iterator.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_ITERATOR_HPP_
#define API_ITERATOR_HPP_

#include "api.IllegalValue.hpp"

namespace eoos
{
namespace api
{
        
/**
 * @class Iterator<T>
 * @brief Iterator interface.
 *
 * @tparam T Data type of iterator element.
 */
template <typename T>
class Iterator : public IllegalValue<T>
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Iterator() = 0;

    /**
     * @brief Returns next element and advances the cursor position.
     *
     * @return Reference to element.
     */
    virtual T& getNext() const = 0;

    /**
     * @brief Tests if this iteration may return a next element.
     *
     * @return True if next element is had.
     */
    virtual bool_t hasNext() const = 0;

    /**
     * @brief Removes the last element returned by this iterator.
     *
     * @return True if an element is removed successfully.
     */
    virtual bool_t remove() = 0;

};

template <typename T>
inline Iterator<T>::~Iterator() {}

}
}
#endif // API_ITERATOR_HPP_

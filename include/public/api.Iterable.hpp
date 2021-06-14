/**
 * @file      api.Iterable.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_ITERABLE_HPP_
#define API_ITERABLE_HPP_

#include "api.Object.hpp"
#include "api.Iterator.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class Iterable<T>
 * @brief Iterable interface.
 *
 * @tparam T Data type of element.
 */
template <typename T>
class Iterable : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Iterable() = 0;

    /**
     * @brief Returns an iterator of elements.
     *
     * @note The delete operator must be called for returned value when
     * the iterating of a collection has been completed.
     *
     * @return Pointer to new iterator.
     */
    virtual Iterator<T>* getIterator() = 0;

};

template <typename T>
inline Iterable<T>::~Iterable() {}

} // namespace api
} // namespace eoos
#endif // API_ITERABLE_HPP_

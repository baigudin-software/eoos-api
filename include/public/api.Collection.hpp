/**
 * @file      api.Collection.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_COLLECTION_HPP_
#define API_COLLECTION_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class Collection<T>
 * @brief The root interface of some collections.
 *
 * @tparam T Data type of collection element.
 */
template <typename T>
class Collection : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Collection() = 0;

    /**
     * @brief Returns a number of elements in this container.
     *
     * @return Number of elements.
     */
     virtual int32_t getLength() const = 0;

     /**
      * @brief Tests if this collection has elements.
      *
      * @return True if this collection does not contain any elements.
      */
     virtual bool_t isEmpty() const = 0;

};

template <typename T>
inline Collection<T>::~Collection() {}

} // namespace api
} // namespace eoos
#endif // API_COLLECTION_HPP_

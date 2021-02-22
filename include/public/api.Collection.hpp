/**
 * @brief The root interface of some collections.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_COLLECTION_HPP_
#define API_COLLECTION_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @brief Primary template implementation.
 *
 * @tparam T - data type of collection element.
 */
template <typename T>
class Collection : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Collection(){}

    /**
     * @brief Returns a number of elements in this container.
     *
     * @return number of elements.
     */
     virtual int32_t getLength() const = 0;

     /**
      * @brief Tests if this collection has elements.
      *
      * @return true if this collection does not contain any elements.
      */
     virtual bool_t isEmpty() const = 0;

};

} // namespace api
} // namespace eoos
#endif // API_COLLECTION_HPP_

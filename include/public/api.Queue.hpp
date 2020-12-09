/**
 * @brief Queue interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_QUEUE_HPP_
#define API_QUEUE_HPP_

#include "api.Collection.hpp"
#include "api.IllegalValue.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @brief Primary template implementation.
 *
 * @param T - data type of queue element.
 */
template <typename T>
class Queue : public Collection<T>, public IllegalValue<T>
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Queue() = 0;

    /**
     * @brief Tests if this object has been constructed.
     *
     * @return true if object has been constructed successfully.
     */
    virtual bool_t isConstructed() const = 0;

    /**
     * @brief Inserts a new element to this container.
     *
     * NOTE: A passed element must be copied to an internal data structure of
     * a realizing class by calling a copy constructor so that the element
     * might be invalidated after the function called.
     *
     * @param element - inserting element.
     * @return true if element is added.
     */
    virtual bool_t add(const T& element) = 0;

    /**
     * @brief Removes the head element of this container.
     *
     * @return true if an element is removed successfully.
     */
    virtual bool_t remove() = 0;

    /**
     * @brief Examines the head element of this container.
     *
     * @return the head element.
     */
    virtual T& peek() const = 0;

};

template <typename T>
inline Queue<T>::~Queue() {}
        
} // namespace api
} // namespace eoos
#endif // API_QUEUE_HPP_

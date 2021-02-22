/**
 * @brief List iterator interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_LIST_ITERATOR_HPP_
#define API_LIST_ITERATOR_HPP_

#include "api.Iterator.hpp"

namespace eoos
{
namespace api
{
        
/**
 * @brief Primary template implementation.
 *
 * @tparam T - data type of list iterator element.
 */
template <typename T>
class ListIterator : public Iterator<T>
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~ListIterator() = 0;

    /**
     * @brief Inserts the specified element into the list.
     *
     * Method inserts given element before the element
     * that will be returned by next method.
     * Therefore subsequent call to next will be unaffected,
     * and a subsequent call to prev will return the inserted element.
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
     * @brief Returns previous element and advances the cursor backwards.
     *
     * @return reference to element.
     */
    virtual T& getPrevious() const = 0;

    /**
     * @brief Tests if this iteration may return a previous element.
     *
     * @return true if previous element is had.
     */
    virtual bool_t hasPrevious() const = 0;

    /**
     * @brief Returns the index of the element that would be returned by a subsequent call to next().
     *
     * @return index of the next element or list size if the list iterator is at the end of the list.
     */
    virtual int32_t getNextIndex() const = 0;

    /**
     * @brief Returns the index of the element that would be returned by a subsequent call to prev().
     *
     * @return index of the previous element or -1 if the list iterator is at the beginning of the list.
     */
    virtual int32_t getPreviousIndex() const = 0;

};

template <typename T>
inline ListIterator<T>::~ListIterator() {}

} // namespace api
} // namespace eoos
#endif // API_LIST_ITERATOR_HPP_

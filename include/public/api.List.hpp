/**
 * @file      api.List.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_LIST_HPP_
#define API_LIST_HPP_

#include "api.Collection.hpp"
#include "api.IllegalValue.hpp"
#include "api.ListIterator.hpp"

namespace eoos
{
namespace api
{

/**
 * @class List<T>
 * @brief List interface.
 *
 * @tparam T Data type of list element.
 */
template <typename T>
class List : public Collection<T>, public IllegalValue<T>
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~List() = 0;

    /**
     * @brief Inserts new element to the end of this container.
     *
     * @note A passed element must be copied to an internal data structure of
     * a realizing class by calling a copy constructor so that the element
     * might be invalidated after the function called.
     *
     * @param element An inserting element.
     * @return True if element is added.
     */
    virtual bool_t add(const T& element) = 0;

    /**
     * @brief Inserts new element to the specified position in this container.
     *
     * @note A passed element must be copied to an internal data structure of
     * a realizing class by calling a copy constructor so that the element
     * might be invalidated after the function called.
     *
     * @param index   A position in this container.
     * @param element An inserting element.
     * @return True if element is inserted.
     */
    virtual bool_t add(int32_t index, const T& element) = 0;

    /**
     * @brief Removes all elements from this container.
     */
    virtual void clear() = 0;

    /**
     * @brief Removes the element at the specified position in this container.
     *
     * @param index Position in this container.
     * @return True if an element is removed successfully.
     */
    virtual bool_t remove(int32_t index) = 0;

    /**
     * @brief Removes the first element from this container.
     *
     * @return True if an element is removed successfully.
     */
    virtual bool_t removeFirst() = 0;

    /**
     * @brief Removes the last element from this container.
     *
     * @return True if an element is removed successfully.
     */
    virtual bool_t removeLast() = 0;

    /**
     * @brief Removes the first occurrence of the specified element from this container.
     *
     * @param element Reference to element.
     * @return True if an element is removed successfully.
     */
    virtual bool_t removeElement(const T& element) = 0;

    /**
     * @brief Returns an element from this container by index.
     *
     * @param index Position in this container.
     * @return Indexed element of this container.
     */
    virtual T& get(int32_t index) const = 0;

    /**
     * @brief Returns the first element in this container.
     *
     * @return The first element in this container.
     */
    virtual T& getFirst() const = 0;

    /**
     * @brief Returns the last element in this container.
     *
     * @return The last element in this container.
     */
    virtual T& getLast() const = 0;

    /**
     * @brief Returns a list iterator of this container elements.
     *
     * You have to call delete operator for returned iterator after it is used.
     * Given index must not be out of bounds (index < 0 || index > length()).
     *
     * @param index Start position in this container.
     * @return Pointer to new list iterator.
     */
    virtual ListIterator<T>* getListIterator(int32_t index) = 0;

    /**
     * @brief Returns the index of the first occurrence of the specified element in this container.
     *
     * @param element Reference to the element.
     * @return Index or -1 if this container does not contain the element.
     */
    virtual int32_t getIndexOf(const T& element) const = 0;

    /**
     * @brief Tests if given index is available.
     *
     * @param index Checking position in this container.
     * @return True if index is present.
     */
    virtual bool_t isIndex(int32_t index) const = 0;

};

template <typename T>
inline List<T>::~List() {}
        
} // namespace api
} // namespace eoos
#endif // API_LIST_HPP_

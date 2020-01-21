/**
 * List interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2016, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_LIST_HPP_
#define API_LIST_HPP_

#include "api.Collection.hpp"
#include "api.IllegalValue.hpp"
#include "api.ListIterator.hpp"

namespace local
{
    namespace api
    {
        /**
         * Primary template implementation.
         *
         * @param T - data type of list element.
         */
        template <typename T>
        class List : public api::Collection<T>, public api::IllegalValue<T>
        {

        public:

            /**
             * Destructor.
             */
            virtual ~List(){}

            /**
             * Tests if this object has been constructed.
             *
             * @return true if object has been constructed successfully.
             */
            virtual bool isConstructed() const = 0;

            /**
             * Inserts new element to the end of this container.
             *
             * NOTE: A passed element must be copied to an internal data structure of
             * a realizing class by calling a copy constructor so that the element
             * might be invalidated after the function called.
             *
             * @param element - an inserting element.
             * @return true if element is added.
             */
            virtual bool add(const T& element) = 0;

            /**
             * Inserts new element to the specified position in this container.
             *
             * NOTE: A passed element must be copied to an internal data structure of
             * a realizing class by calling a copy constructor so that the element
             * might be invalidated after the function called.
             *
             * @param index   - a position in this container.
             * @param element - an inserting element.
             * @return true if element is inserted.
             */
            virtual bool add(int32 index, const T& element) = 0;

            /**
             * Removes all elements from this container.
             */
            virtual void clear() = 0;

            /**
             * Removes the element at the specified position in this container.
             *
             * @param index - position in this container.
             * @return true if an element is removed successfully.
             */
            virtual bool remove(int32 index) = 0;

            /**
             * Removes the first element from this container.
             *
             * @return true if an element is removed successfully.
             */
            virtual bool removeFirst() = 0;

            /**
             * Removes the last element from this container.
             *
             * @return true if an element is removed successfully.
             */
            virtual bool removeLast() = 0;

            /**
             * Removes the first occurrence of the specified element from this container.
             *
             * @param element - reference to element.
             * @return true if an element is removed successfully.
             */
            virtual bool removeElement(const T& element) = 0;

            /**
             * Returns an element from this container by index.
             *
             * @param index - position in this container.
             * @return indexed element of this container.
             */
            virtual T& get(int32 index) const = 0;

            /**
             * Returns the first element in this container.
             *
             * @return the first element in this container.
             */
            virtual T& getFirst() const = 0;

            /**
             * Returns the last element in this container.
             *
             * @return the last element in this container.
             */
            virtual T& getLast() const = 0;

            /**
             * Returns a list iterator of this container elements.
             *
             * You have to call delete operator for returned iterator after it is used.
             * Given index must not be out of bounds (index < 0 || index > length()).
             *
             * @param index - start position in this container.
             * @return pointer to new list iterator.
             */
            virtual api::ListIterator<T>* getListIterator(int32 index) = 0;

            /**
             * Returns the index of the first occurrence of the specified element in this container.
             *
             * @param element - reference to the element.
             * @return index or -1 if this container does not contain the element.
             */
            virtual int32 getIndexOf(const T& element) const = 0;

            /**
             * Tests if given index is available.
             *
             * @param index - checking position in this container.
             * @return true if index is present.
             */
            virtual bool isIndex(int32 index) const = 0;

        };
    }
}
#endif // API_LIST_HPP_

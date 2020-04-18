/**
 * String interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_STRING_HPP_
#define API_STRING_HPP_

#include "api.Collection.hpp"

namespace eoos
{
    namespace api
    {
        /**
         * Primary template implementation.
         *
         * @param T - data type of string characters.
         */
        template <typename T>
        class String : public api::Collection<T>
        {

        public:

            /**
             * Destructor.
             */
            virtual ~String(){}

            /**
             * Copies a passed string into this string.
             *
             * NOTE: A passed string must be copied to an internal containing string of
             * a realizing class so that the passed string might be invalidated after the function called.
             *
             * @param string - a string object interface to be copied.
             * @return true if a passed string has been copied successfully.
             */
            virtual bool_t copy(const api::String<T>& string) = 0;

            /**
             * Concatenates a passed string to this string.
             *
             * NOTE: A passed string must be appended to an internal containing string of
             * a realizing class so that the passed string might be invalidated after the function called.
             *
             * @param string - a string object interface to be appended.
             * @return true if a passed string has been appended successfully.
             */
            virtual bool_t concatenate(const api::String<T>& string) = 0;

            /**
             * Compares this string with a passed string lexicographically.
             *
             * @param string - a string object interface to be compared.
             * @return the value 0 if a passed string is equal to this string;
             *         a value less than 0 if this string is less than a passed string;
             *         a value greater than 0 if this string is greater than a passed string,
             *         or the minimum possible value if an error has been occurred.
             */
            virtual int32_t compare(const api::String<T>& string) const = 0;

            /**
             * Returns pointer to the first character of containing string.
             *
             * NOTE: Be careful, some action with the object might relocate internal buffer
             * that contains characters. By this reason, a returned address will be actual
             * until you do not call no constant method of this class for an object.
             *
             * @return first character of containing string characters, or NULL if no string contained.
             */
            virtual const T* getChar() const = 0;

        };
    }
}
#endif // API_STRING_HPP_

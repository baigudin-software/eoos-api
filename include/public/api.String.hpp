/**
 * @file      api.String.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_STRING_HPP_
#define API_STRING_HPP_

#include "api.Collection.hpp"

namespace eoos
{
namespace api
{

/**
 * @class String<T>
 * @brief String interface.
 *
 * @tparam T Data type of string characters.
 */
template <typename T>
class String : public Collection<T>
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~String() = 0;

    /**
     * @brief Copies a passed string into this string.
     *
     * @note A passed string must be copied to an internal containing string of
     * a realizing class so that the passed string might be invalidated after the function called.
     *
     * @param string A string object interface to be copied.
     * @return True if a passed string has been copied successfully.
     */
    virtual bool_t copy(const String<T>& string) = 0;

    /**
     * @brief Concatenates a passed string to this string.
     *
     * @note A passed string must be appended to an internal containing string of
     * a realizing class so that the passed string might be invalidated after the function called.
     *
     * @param string A string object interface to be appended.
     * @return True if a passed string has been appended successfully.
     */
    virtual bool_t concatenate(const String<T>& string) = 0;

    /**
     * @brief Compares this string with a passed string lexicographically.
     *
     * @param string A string object interface to be compared.
     * @return The value 0 if a passed string is equal to this string;
     *         a value less than 0 if this string is less than a passed string;
     *         a value greater than 0 if this string is greater than a passed string,
     *         or the minimum possible value if an error has been occurred.
     */
    virtual int32_t compare(const String<T>& string) const = 0;

    /**
     * @brief Returns pointer to the first character of containing string.
     *
     * @note Be careful, some action with the object might relocate internal buffer
     * that contains characters. By this reason, a returned address will be actual
     * until you do not call no constant function of this class for an object.
     *
     * @return First character of containing string characters, or NULLPTR if no string contained.
     */
    virtual const T* getChar() const = 0;

};

template <typename T>
inline String<T>::~String() {}
        
} // namespace api
} // namespace eoos
#endif // API_STRING_HPP_

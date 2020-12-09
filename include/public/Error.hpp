/**
 * @brief The operating system error codes.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2020, Sergey Baigudin
 */
#ifndef ERROR_HPP_
#define ERROR_HPP_

namespace eoos
{
    
enum Error
{
    /**
     * @brief No errors have been occurred.
     */
    ERROR_OK = 0,

    /**
     * @brief Error of the operating system kernel syscall calling.
     */
    ERROR_SYSCALL_CALLED = 1,

    /**
     * @brief Error of a no strict MISRA C++ function calling.
     */
    ERROR_NO_MISRA_FUNCTION_CALLED = 2,

    /**
     * @brief Error of a user program occurred.
     */
    ERROR_USER_TERMINATION = 3,

    /**
     * @brief Error of searching of a resource.
     */
    ERROR_RESOURCE_NOT_FOUND = 4,

    /**
     * @brief An undefined error has been occurred.
     */
    ERROR_UNDEFINED = 127,

    /**
     * @brief The last unused error code.
     */
    ERROR_LAST = 128

};

} // namespace eoos
#endif /* ERROR_H_ */

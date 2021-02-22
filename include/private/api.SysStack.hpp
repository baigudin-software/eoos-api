/**
 * @brief Stack interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYS_STACK_HPP_
#define API_SYS_STACK_HPP_

#include "api.Collection.hpp"
#include "api.IllegalValue.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @brief Primary template implementation.
 *
 * @tparam T - data type of default stack element.
 */
template <typename T>
class SysStack : public Collection<T>, public IllegalValue<T>
{

public:

    /**
     * @brief Stack operations.
     *
     * Stack operations:
     * - Full stacks have stack pointers that point to the last used location.
     * - Empty stacks have stack pointers that point to the first unused location.
     * - Descending stacks grow towards decreasing memory addresses.
     * - Ascending stacks grow towards increasing memory addresses.
     */
    enum Operation
    {
        /**
         * @brief Full Descending.
         */
        FD = 0,

        /**
         * @brief Empty Descending.
         */
        ED = 1,

        /**
         * @brief Full Ascending.
         */
        FA = 2,

        /**
         * @brief Empty Ascending.
         */
        EA = 3

    };

    /**
     * @brief Destructor.
     */
    virtual ~SysStack() = 0;

    /**
     * @brief Tests if this object has been constructed.
     *
     * @return true if object has been constructed successfully.
     */
    virtual bool_t isConstructed() const = 0;

    /**
     * @brief Returns an initial top of stack.
     *
     * @return a memory address to top of this stack when object was built.
     */
    virtual const T* getTos() = 0;

    /**
     * @brief Returns an type of stack operation.
     *
     * @return the stack operation.
     */
    virtual Operation getType() const = 0;

};

template <typename T>
inline SysStack<T>::~SysStack() {}
        
} // namespace api
} // namespace eoos
#endif // API_SYS_STACK_HPP_

/**
 * @file      api.SysStack.hpp
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
 * @class SysStack<T>
 * @brief Stack interface.
 *
 * @tparam T Data type of default stack element.
 */
template <typename T>
class SysStack : public Collection<T>, public IllegalValue<T>
{

public:

    /**
     * @enum Operation
     * @brief Stack operations.
     *
     * Stack operations:
     * - Full stacks have stack pointers that point to the last used location.
     * - Empty stacks have stack pointers that point to the first unused location.
     * - Descending stacks grow towards decreasing memory addresses.
     * - Ascending stacks grow towards increasing memory addresses.
     *
     * @todo Following AUTOSAR C++ this class shall be revised to be moved from template class scope.
     */
    enum Operation
    {
        FD = 0, //< Full Descending.
        ED = 1, //< Empty Descending.
        FA = 2, //< Full Ascending.
        EA = 3  //< Empty Ascending.
    };

    /**
     * @brief Destructor.
     */
    virtual ~SysStack() = 0;

    /**
     * @brief Tests if this object has been constructed.
     *
     * @return True if object has been constructed successfully.
     */
    virtual bool_t isConstructed() const = 0;

    /**
     * @brief Returns an initial top of stack.
     *
     * @return A memory address to top of this stack when object was built.
     */
    virtual const T* getTos() = 0;

    /**
     * @brief Returns an type of stack operation.
     *
     * @return The stack operation.
     */
    virtual Operation getType() const = 0;

};

template <typename T>
inline SysStack<T>::~SysStack() {}
        
} // namespace api
} // namespace eoos
#endif // API_SYS_STACK_HPP_

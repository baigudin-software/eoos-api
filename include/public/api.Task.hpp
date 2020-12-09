/**
 * @brief Task interface.
 *
 * The interface of a task that is being executed in self context.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_TASK_HPP_
#define API_TASK_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
        
class Task : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Task() = 0;

    /**
     * @brief Starts executing an operating system prorgam in itsself context.
     *
     * @return zero, or error code if an error has been occurred.
     */
    virtual int32_t start() = 0;

    /**
     * @brief Returns size of stack.
     *
     * The method returns size of stack in bytes which should be allocated for the task.
     *
     * @return stack size in bytes.
     */
    virtual int32_t getStackSize() const = 0;

};

inline Task::~Task() {}
        
} // namespace api
} // namespace eoos
#endif // API_TASK_HPP_

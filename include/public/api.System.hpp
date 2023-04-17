/**
 * @file      api.System.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYSTEM_HPP_
#define API_SYSTEM_HPP_

#include "api.Object.hpp"
#include "api.Scheduler.hpp"
#include "api.Heap.hpp"
#include "api.SystemMutex.hpp"
#include "api.Semaphore.hpp"
#include "api.OutStream.hpp"

namespace eoos
{
namespace api
{

/**
 * @class System
 * @brief The operating system syscall interface.
 */
class System : public Object
{

public:

    /**
     * @brief Returns the system scheduler.
     *
     * @return The system scheduler.
     */
    virtual Scheduler& getScheduler() = 0;

    /**
     * @brief Returns the system heap memory.
     *
     * @return The system heap memory.
     */
    virtual Heap& getHeap() = 0;

    /**
     * @brief Returns system output character stream.
     *
     * @return The system output character stream.
     */
    virtual OutStream<char_t>& getOutStreamChar() = 0;

    /**
     * @brief Returns system error output character stream.
     *
     * @return The system error output character stream.
     */
    virtual OutStream<char_t>& getErrorStreamChar() = 0;

    /**
     * @brief Returns mutex sub-system.
     *
     * @return The mutex sub-system.
     */
    virtual SystemMutex& getSystemMutex() = 0;

    /**
     * @brief Creates a new semaphore resource.
     *
     * @param permits The initial number of permits available.
     * @return A new semaphore resource, or NULLPTR if an error has been occurred.
     */
    virtual Semaphore* createSemaphore(int32_t permits) = 0;
    
protected:

    /**
     * @brief Destructor.
     */
    virtual ~System() = 0;

};

inline System::~System() {}

} // namespace api
} // namespace eoos
#endif // API_SYSTEM_HPP_

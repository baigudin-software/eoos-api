/**
 * @brief The opearating system syscall interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYSTEM_HPP_
#define API_SYSTEM_HPP_

#include "api.Object.hpp"
#include "api.Heap.hpp"
#include "api.Runtime.hpp"
#include "api.Scheduler.hpp"
#include "api.Mutex.hpp"
#include "api.Semaphore.hpp"
#include "api.Interrupt.hpp"
#include "api.Task.hpp"
#include "api.Toggle.hpp"

namespace eoos
{
namespace api
{

class System : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~System() = 0;

    /**
     * @brief Returns running time of the system in nanoseconds.
     *
     * @return time in nanoseconds.
     */
    virtual int64_t getTime() const = 0;

    /**
     * @brief Returns the system heap memory.
     *
     * @return the heap memory.
     */
    virtual Heap& getHeap() const = 0;

    /**
     * @brief Returns the system runtime environment.
     *
     * @return the system runtime environment.
     */
    virtual Runtime& getRuntime() const = 0;

    /**
     * @brief Returns a global interrupt controller.
     *
     * @return a global interrupt controller.
     */
    virtual Toggle& getGlobalInterrupt() const = 0;

    /**
     * @brief Returns the kernel scheduler.
     *
     * @return the kernel scheduler.
     */
    virtual Scheduler& getScheduler() const = 0;

    /**
     * @brief Creates a new mutex resource.
     *
     * @return a new mutex resource, or NULLPTR if an error has been occurred.
     */
    virtual Mutex* createMutex() = 0;

    /**
     * @brief Creates a new semaphore resource.
     *
     * @param permits - the initial number of permits available.
     * @param isFair  - true if this semaphore will guarantee FIFO granting of permits under contention.
     * @return a new semaphore resource, or NULLPTR if an error has been occurred.
     */
    virtual Semaphore* createSemaphore(int32_t permits, bool_t isFair) = 0;

    /**
     * @brief Creates a new interrupt resource.
     *
     * @param handler - user class which implements an interrupt handler interface.
     * @param source  - available interrupt source number.
     * @return a new interrupt resource, or NULLPTR if an error has been occurred.
     */
    virtual Interrupt* createInterrupt(Task& handler, int32_t source) = 0;

    /**
     * @brief Terminates the system execution.
     *
     * If the system is RTOS, all the operating system is terminated, and CPU goes to idle state.
     * If the system is OS, a process of operating system executing a user program is terminated.
     */
    virtual void terminate() const = 0;

};

inline System::~System() {}

} // namespace api
} // namespace eoos
#endif // API_SYSTEM_HPP_

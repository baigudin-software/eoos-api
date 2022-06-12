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
#include "api.Mutex.hpp"
#include "api.Semaphore.hpp"
#include "api.Task.hpp"
#include "api.Toggle.hpp"

namespace eoos
{
namespace api
{

/**
 * @class System
 * @brief The opearating system syscall interface.
 */
class System : public Object
{

public:

    /**
     * @brief Returns the kernel scheduler.
     *
     * @return The kernel scheduler.
     */
    virtual Scheduler& getScheduler() = 0;

    /**
     * @brief Returns the kernel heap memory.
     *
     * @return The kernel heap memory.
     */
    virtual Heap& getHeap() = 0;

    /**
     * @brief Creates a new mutex resource.
     *
     * @return A new mutex resource, or NULLPTR if an error has been occurred.
     */
    virtual Mutex* createMutex() = 0;

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

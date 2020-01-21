/**
 * The opearating system syscall interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
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

namespace local
{
    namespace api
    {
        class System : public api::Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~System(){}

            /**
             * Returns running time of the operating system in nanoseconds.
             *
             * @return time in nanoseconds.
             */
            virtual int64 getTime() const = 0;

            /**
             * Returns the operating system heap memory.
             *
             * @return the heap memory.
             */
            virtual api::Heap& getHeap() const = 0;

            /**
             * Returns the system runtime environment.
             *
             * @return the system runtime environment.
             */
            virtual api::Runtime& getRuntime() const = 0;

            /**
             * Returns a global interrupt controller.
             *
             * @return a global interrupt controller.
             */
            virtual api::Toggle& getGlobalInterrupt() const = 0;

            /**
             * Returns the kernel scheduler.
             *
             * @return the kernel scheduler.
             */
            virtual api::Scheduler& getScheduler() const = 0;

            /**
             * Creates a new mutex resource.
             *
             * @return a new mutex resource, or NULL if an error has been occurred.
             */
            virtual api::Mutex* createMutex() = 0;

            /**
             * Creates a new semaphore resource.
             *
             * @param permits - the initial number of permits available.
             * @param isFair  - true if this semaphore will guarantee FIFO granting of permits under contention.
             * @return a new semaphore resource, or NULL if an error has been occurred.
             */
            virtual api::Semaphore* createSemaphore(int32 permits, bool isFair) = 0;

            /**
             * Creates a new interrupt resource.
             *
             * @param handler - user class which implements an interrupt handler interface.
             * @param source  - available interrupt source number.
             * @return a new interrupt resource, or NULL if an error has been occurred.
             */
            virtual api::Interrupt* createInterrupt(api::Task& handler, int32 source) = 0;

            /**
             * Terminates the operating system execution.
             */
            virtual void terminate() const = 0;

        };
    }
}
#endif // API_SYSTEM_HPP_

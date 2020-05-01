/**
 * Threads scheduler interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SCHEDULER_HPP_
#define API_SCHEDULER_HPP_

#include "api.Object.hpp"
#include "api.Thread.hpp"
#include "api.Task.hpp"
#include "api.Toggle.hpp"

namespace eoos
{
    namespace api
    {
        class Scheduler : public Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Scheduler(){}

            /**
             * Creates a new thread.
             *
             * @param task - an user task which main method will be invoked when created thread is started.
             * @return a new thread.
             */
            virtual Thread* createThread(Task& task) = 0;

            /**
             * Returns currently executing thread.
             *
             * @return executing thread.
             */
            virtual Thread& getCurrentThread() const = 0;

            /**
             * Yields to next thread.
             */
            virtual void yield() = 0;

            /**
             * Returns the toggle interface for controlling global thread switching.
             *
             * @return toggle interface.
             */
            virtual Toggle& toggle() = 0;

        };
    }
}
#endif // API_SCHEDULER_HPP_

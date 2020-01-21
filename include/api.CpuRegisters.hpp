/**
 * A central processing unit registers resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2018, Sergey Baigudin, Baigudin Software
 * @license   http://embedded.team/license/
 */
#ifndef API_CPU_REGISTERS_HPP_
#define API_CPU_REGISTERS_HPP_

#include "api.Object.hpp"
#include "api.Stack.hpp"

namespace local
{
    namespace api
    {
        class CpuRegisters : public api::Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~CpuRegisters(){}

            /**
             * Initializes the CPU registers.
             *
             * The method is mostly used for restoring from an interrupt service routine.
             *
             * @param stack    - a routine stack.
             * @param entry    - a routine entry address.
             * @param argument - a routine argument.
             */
            virtual void setInitialization(api::Stack<int64>& stack, void* entry, int32 argument) = 0;

            /**
             * Returns a pointer to the first register of CPU registers context.
             *
             * @return memory address of registers order, or NULL if an error has been occurred.
             */
            virtual void* getRegisters() = 0;

        };
    }
}
#endif // API_CPU_REGISTERS_HPP_

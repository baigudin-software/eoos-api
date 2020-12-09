/**
 * @brief Runtime program execution interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_RUNTIME_HPP_
#define API_RUNTIME_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
class Runtime : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Runtime() = 0;

    /**
     * @brief Loads a program for executing.
     *
     * @param path - a system path to a program.
     * @return true if program has been loaded successfully.
     */
    virtual bool_t load(const char_t* path) = 0;

    /**
     * @brief Terminates a program execution.
     *
     * @param status - a termination status.
     */
    virtual void exit(int32_t status = 0) = 0;

};

inline Runtime::~Runtime() {}

} // namespace api
} // namespace eoos
#endif // API_RUNTIME_HPP_

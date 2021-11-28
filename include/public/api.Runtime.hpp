/**
 * @file      api.Runtime.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_RUNTIME_HPP_
#define API_RUNTIME_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class Runtime
 * @brief Runtime program execution interface.
 */    
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
     * @param path A system path to a program.
     * @return True if program has been loaded successfully.
     */
    virtual bool_t load(const char_t* path) = 0;

};

inline Runtime::~Runtime() {}

} // namespace api
} // namespace eoos
#endif // API_RUNTIME_HPP_

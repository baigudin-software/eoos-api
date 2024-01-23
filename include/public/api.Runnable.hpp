/**
 * @file      api.Runnable.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2024, Sergey Baigudin, Baigudin Software
 */
#ifndef API_RUNNABLE_HPP_
#define API_RUNNABLE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class Runnable
 * @brief Runnable interface.
 *
 * The interface of a task that is being executed in self context.
 */        
class Runnable : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Runnable() = 0;

    /**
     * @brief Starts executing an operating system task in itself context.
     */
    virtual void start() = 0;

};

inline Runnable::~Runnable() {}
        
} // namespace api
} // namespace eoos
#endif // API_RUNNABLE_HPP_

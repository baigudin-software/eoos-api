/**
 * @brief Mutex interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_MUTEX_HPP_
#define API_MUTEX_HPP_

#include "api.Resource.hpp"

namespace eoos
{
namespace api
{
    
class Mutex : public Resource
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Mutex() = 0;

    /**
     * @brief Locks this mutex.
     *
     * @return true if this mutex is locked successfully.
     */
    virtual bool_t lock() = 0;

    /**
     * @brief Unlocks this mutex.
     */
    virtual void unlock() = 0;

};

inline Mutex::~Mutex() {}

} // namespace api
} // namespace eoos
#endif // API_MUTEX_HPP_

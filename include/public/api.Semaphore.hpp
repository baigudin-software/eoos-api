/**
 * @file      api.Semaphore.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SEMAPHORE_HPP_
#define API_SEMAPHORE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class Semaphore
 * @brief Semaphore interface.
 */
class Semaphore : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Semaphore() = 0;

    /**
     * @brief Acquires one permit from this semaphore.
     *
     * The method acquires one permit or waits
     * while the permit will be released.
     *
     * @return True if the semaphore is acquired successfully.
     */
    virtual bool_t acquire() = 0;

    /**
     * @brief Acquires the given number of permits from this semaphore.
     *
     * The method acquires given permits number or waits
     * while the number will be released.
     *
     * @param permits The number of permits to acquire.
     * @return True if the semaphore is acquired successfully.
     */
    virtual bool_t acquire(int32_t permits) = 0;

    /**
     * @brief Releases one permit.
     *
     * The method releases from one permit and returns this to the semaphore.
     */
    virtual void release() = 0;

    /**
     * @brief Releases the given number of permits.
     *
     * The method releases from the permits and returns these to the semaphore.
     *
     * @param permits The number of permits to release.
     */
    virtual void release(int32_t permits) = 0;

    /**
     * @brief Tests if this semaphore is fair.
     *
     * @return True if this semaphore has fairness set true.
     */
    virtual bool_t isFair() const = 0;

};
        
inline Semaphore::~Semaphore() {}

} // namespace api
} // namespace eoos
#endif // API_SEMAPHORE_HPP_

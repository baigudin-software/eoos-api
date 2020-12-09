/**
 * @brief One program synchronization for executing in several processor units.
 *
 * This interface provides a synchronization of one program
 * which is being executed by several processor units.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYNCHRONIZABLE_HPP_
#define API_SYNCHRONIZABLE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

class Synchronizable : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Synchronizable() = 0;

    /**
     * @brief Synchronizes an executing code section.
     *
     * The method waits while other processor units get this program pointer
     * and continues executing the program after this.
     */
    virtual void synchronize() = 0;

    /**
     * @brief Recasts given data to a gauge.
     *
     * The method compares given data with a gauge and recasts to it
     * if the data does not equal to the gauge.
     *
     * @param ptr     - address of data for synchronizing.
     * @param size    - number of bytes for synchronizing.
     * @param channel - number of processor core which data is the gauge of synchronization.
     * @return true if given data was recast to the gauge.
     */
    virtual bool_t recast(void* ptr, int32_t size, int32_t channel) = 0;

    /**
     * @brief Tests if given data equals the gauge.
     *
     * @param ptr     - address of data for synchronizing.
     * @param size    - number of bytes for synchronizing.
     * @param channel - number of processor core which data is the gauge of synchronization.
     * @return true if given data equals to the gauge.
     */
     virtual bool_t isEqual(void* ptr, int32_t size, int32_t channel) = 0;

};
        
inline Synchronizable::~Synchronizable() {}

} // namespace api
} // namespace eoos
#endif // API_SYNCHRONIZABLE_HPP_

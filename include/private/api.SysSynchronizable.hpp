/**
 * @file      api.SysSynchronizable.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYS_SYNCHRONIZABLE_HPP_
#define API_SYS_SYNCHRONIZABLE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class SysSynchronizable
 * @brief One program synchronization for executing in several processor units.
 *
 * This interface provides a synchronization of one program
 * which is being executed by several processor units.
 */
class SysSynchronizable : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SysSynchronizable() = 0;

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
     * @param ptr     Address of data for synchronizing.
     * @param size    Number of bytes for synchronizing.
     * @param channel Number of processor core which data is the gauge of synchronization.
     * @return True if given data was recast to the gauge.
     */
    virtual bool_t recast(void* ptr, int32_t size, int32_t channel) = 0;

    /**
     * @brief Tests if given data equals the gauge.
     *
     * @param ptr     Address of data for synchronizing.
     * @param size    Number of bytes for synchronizing.
     * @param channel Number of processor core which data is the gauge of synchronization.
     * @return True if given data equals to the gauge.
     */
     virtual bool_t isEqual(void* ptr, int32_t size, int32_t channel) = 0;

};
        
inline SysSynchronizable::~SysSynchronizable() {}

} // namespace api
} // namespace eoos
#endif // API_SYS_SYNCHRONIZABLE_HPP_

/**
 * @brief A central processing unit phase-locked loop controller resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_CPU_PLL_HPP_
#define API_CPU_PLL_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{
    
class CpuPll : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~CpuPll() = 0;

    /**
     * @brief Returns source clock of CPU oscillator in Hz.
     *
     * @return frequency value in Hz.
     */
    virtual int64_t getSourceClock() = 0;

    /**
     * @brief Returns source clock of CPU in Hz.
     *
     * @return frequency value in Hz.
     */
    virtual int64_t getCpuClock() = 0;

};

inline CpuPll::~CpuPll() {}

} // namespace api
} // namespace eoos
#endif // API_CPU_PLL_HPP_

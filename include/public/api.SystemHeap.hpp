/**
 * @file      api.SystemHeap.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2022, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYSTEMHEAP_HPP_
#define API_SYSTEMHEAP_HPP_

#include "api.Heap.hpp"
#include "api.Toggle.hpp"

namespace eoos
{
namespace api
{

/**
 * @class SystemHeap
 * @brief System heap memory interface.
 */        
class SystemHeap : public Heap
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SystemHeap() = 0;

    /**
     * @brief Sets a context switching locker.
     *
     * The method allows disabling and enabling thread context switching
     * when memory is being allocated or freed. Thus, the best way is
     * to pass an interface of global interrupt toggling. The parameter type
     * is reference to pointer, as when referenced pointer equals to NULLPTR,
     * no blocks are happening.
     *
     * @param toggle Reference to pointer to some controller.
     */
    virtual void setToggle(Toggle*& toggle) = 0;

    /**
     * @brief Resets a context switching locker.
     */
    virtual void resetToggle() = 0;

};

inline SystemHeap::~SystemHeap() {}

} // namespace api
} // namespace eoos
#endif // API_SYSTEMHEAP_HPP_

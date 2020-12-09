/**
 * @brief Hardware interrupt resource.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef INTERRUPT_HPP_
#define INTERRUPT_HPP_

#include "Object.hpp"
#include "api.Interrupt.hpp"
#include "api.Task.hpp"
#include "System.hpp"

namespace eoos
{
    
class Interrupt : public Object<>, public api::Interrupt
{
    typedef ::eoos::Object<> Parent;

public:

    /**
     * @brief Constructor.
     *
     * @param handler - user class which implements an interrupt handler interface.
     * @param source  - available interrupt source.
     */
    Interrupt(api::Task& handler, const int32_t source) : Parent(),
        isConstructed_ (getConstruct()),
        interrupt_     (NULLPTR){
        setConstruct( construct(handler, source) );
    }

    /**
     * @brief Destructor.
     */
    virtual ~Interrupt()
    {
        delete interrupt_;
    }

    /**
     * @brief Tests if this object has been constructed.
     *
     * @return true if object has been constructed successfully.
     */
    virtual bool_t isConstructed() const
    {
        return isConstructed_;
    }

    /**
     * @brief Jumps to interrupt hardware vector.
     */
    virtual void jump()
    {
        if( isConstructed_ )
        {
            interrupt_->jump();
        }
    }

    /**
     * @brief Clears an interrupt status of this source.
     */
    virtual void clear()
    {
        if( isConstructed_ )
        {
            interrupt_->clear();
        }
    }

    /**
     * @brief Sets an interrupt status of this source.
     */
    virtual void set()
    {
        if( isConstructed_ )
        {
            interrupt_->set();
        }
    }

    /**
     * @brief Locks this interrupt source.
     *
     * @return an interrupt enable source bit value before method was called.
     */
    virtual bool_t disable()
    {
        if( isConstructed_ )
        {
            return interrupt_->disable();
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief Unlocks this interrupt source.
     *
     * @param status - returned status by lock method.
     */
    virtual void enable(const bool_t status)
    {
        if( isConstructed_ )
        {
            interrupt_->enable(status);
        }
    }

private:

    /**
     * @brief Constructor.
     *
     * @param handler - pointer to user class which implements an interrupt handler interface.
     * @param source  - available interrupt source.
     * @return true if object has been constructed successfully.
     */
    bool_t construct(api::Task& handler, const int32_t source)
    {
        if( not isConstructed_ )
        {
            return false;
        }
        interrupt_ = System::call().getKernel().createInterrupt(handler, source);
        return (interrupt_ != NULLPTR) ? interrupt_->isConstructed() : false;
    }

    /**
     * @brief Copy constructor.
     *
     * @param obj - reference to source object.
     */
    Interrupt(const Interrupt& obj);

    /**
     * @brief Assignment operator.
     *
     * @param obj - reference to source object.
     * @return reference to this object.
     */
    Interrupt& operator=(const Interrupt& obj);

    /**
     * @brief The root object constructed flag.
     */
    const bool_t& isConstructed_;

    /**
     * @brief System interrupt controller interface.
     */
    api::Interrupt* interrupt_;

};

} // namespace eoos
#endif // INTERRUPT_HPP_

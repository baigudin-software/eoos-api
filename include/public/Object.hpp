/**
 * @brief Root class of the class hierarchy.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "api.Object.hpp"
#include "ObjectAllocator.hpp"

namespace eoos
{
    
/**
 * @brief Primary template implementation.
 *
 * @param A - heap memory allocator class.
 */
template <class A = Allocator>
class Object : public ObjectAllocator<A>, public api::Object
{

public:

    /**
     * @brief Constructor.
     */
    Object() :
        isConstructed_ (true){
    }

    /**
     * @brief Destructor.
     */
    virtual ~Object()
    {
        isConstructed_ = false;
    }
    
    /**
     * @brief Copy constructor.
     *
     * @param obj - reference to a source object.
     */
    Object(const Object& obj) :
        isConstructed_(obj.isConstructed_){
    }
    
    
    /**
     * @brief Copy assignment operator.
     *
     * @param obj - reference to a source object.
     * @return reference to this object.
     */       
    Object& operator=(const Object& obj)
    {
        isConstructed_ = obj.isConstructed_;
        return *this;
    }    

    #if EOOS_CPP_STANDARD >= 2011

    /**
     * @brief Move constructor.
     *
     * @param obj - right reference to a source object.     
     */       
    Object(Object&& obj) :
        isConstructed_(obj.isConstructed_){
        obj.setConstructed(false);
    }   
    
    /**
     * @brief Move assignment operator.
     *
     * @param obj - right reference to a source object.
     * @return reference to this object.
     */
    Object& operator=(Object&& obj)
    {
        isConstructed_ = obj.isConstructed_;
        obj.setConstructed(false);
        return *this;
    }        
    
    #endif // EOOS_CPP_STANDARD >= 2011

    /**
     * @brief Tests if this object has been constructed.
     *
     * @return true if object has been constructed successfully.
     */
    virtual bool_t isConstructed() const
    {
        return isConstructed_;
    }

protected:

    /**
     * @brief Sets the object constructed flag.
     *
     * @param flag - a new constructed flag.
     */
    void setConstructed(bool_t const flag)
    {
        if( isConstructed_ == true )
        {
            isConstructed_ = flag;
        }
    }

private:

    /**
     * @brief This object constructed flag.
     */
    bool_t isConstructed_;

};
  
} // namespace eoos

#endif // OBJECT_HPP_

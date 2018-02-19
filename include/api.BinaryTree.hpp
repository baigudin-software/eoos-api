/** 
 * Binary tree interface.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef API_BINARY_TREE_HPP_
#define API_BINARY_TREE_HPP_

#include "api.Object.hpp"

namespace api
{
    /** 
     * @param T data type of an element.
     */ 
    template <typename T>
    class BinaryTree : public ::api::Object
    {
      
    public:
    
        /**
         * Destructor.
         */
        virtual ~BinaryTree(){}
        
        /**
         * Inserts a new element to this tree.
         *
         * NOTE: A passed element must be copied to an internal data structure of 
         * a realizing class by calling a copy constructor so that the element 
         * might be invalidated after the function called.
         *
         * @param element an inserting element.
         * @return true if element has been added successfully.
         */      
        virtual bool add(const T& element) = 0;

    };
}
#endif // API_BINARY_TREE_HPP_

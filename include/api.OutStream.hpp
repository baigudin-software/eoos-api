/**
 * Output stream interface.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/ 
 */
#ifndef API_OUT_STREAM_HPP_
#define API_OUT_STREAM_HPP_

#include "api.Object.hpp"

namespace api
{
  class OutStream : public ::api::Object
  {
    
  public:

    /** 
     * Destructor.
     */
    virtual ~OutStream(){}
    
    /** 
     * Writes to an output stream passed string.
     *
     * @param str output string.
     * @return this interface.
     */    
    virtual OutStream& operator <<(const char* str) = 0;
    
  };
}
#endif // API_OUT_STREAM_HPP_

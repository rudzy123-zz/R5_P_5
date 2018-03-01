/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Header file for an object thrown on violation of precondition.
 *
 *  Adapted from page 250 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 7 Feb 2018
 *
 *  @version 7.0 */

#ifndef PRECOND_VIOLATED_EXCEP_
#define PRECOND_VIOLATED_EXCEP_

#include <stdexcept>
#include <string>

/** @class PrecondViolatedExcept PrecondViolatedExcept.h "PrecondViolatedExcep.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class PrecondViolatedExcept : public std::overflow_error {
public:
    explicit PrecondViolatedExcept(const std::string& message = "");
    
    virtual ~PrecondViolatedExcept() noexcept = default; //throw();
};

#endif

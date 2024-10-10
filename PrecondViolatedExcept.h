// PrecondViolatedExcept.h
#ifndef PRECOND_VIOLATED_EXCEPT_H
#define PRECOND_VIOLATED_EXCEPT_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error {
public:
    PrecondViolatedExcept(const std::string& message = "");
};

#endif

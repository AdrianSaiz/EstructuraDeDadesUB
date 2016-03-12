/* 
 * File:   BadInputException.h
 * Author: ruben
 *
 * Created on 5 de marzo de 2016, 17:20
 */

#ifndef BADINPUTEXCEPTION_H
#define	BADINPUTEXCEPTION_H

#include <stdexcept>
using std::runtime_error;

class BadInputException : public runtime_error {
public:
    BadInputException(int i);
    char* what();
private: 
    char* errorMessage;
};

#endif	/* BADINPUTEXCEPTION_H */


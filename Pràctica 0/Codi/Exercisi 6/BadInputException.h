/* 
 * File:   BadInputException.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
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


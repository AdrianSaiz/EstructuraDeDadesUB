/* 
 * File:   BadInputException.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
 */
#include "BadInputException.h"

BadInputException::BadInputException(int i): runtime_error("Error")  { 
    if(i == -1) {
        this->errorMessage = "The number that you have entered is <= 0.";
    }
    else {
        //-2
        this->errorMessage = "Your input is not a number" ;
    }
}
char* BadInputException::what(){
    // @Overrides runtime-error what method.
    return this->errorMessage;
}

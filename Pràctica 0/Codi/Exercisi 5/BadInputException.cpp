/* 
 * File:   BadInputException.cpp
 * Author: ruben
 * 
 * Created on 5 de marzo de 2016, 17:20
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
    return this->errorMessage;
}

/* 
 * File:   Square.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
 */

#include "Square.h"
#include <iostream>
#include "Figure.h"

using namespace std;

Square::Square():Figure() {
    side = 1; // Default
    //cout << "Sóc el constructor de Square" << endl;
}
Square::Square(float side):Figure() {
    this->side = side;
    //cout << "Sóc el constructor de Square" << endl;
}
Square::Square(const Square& orig) {
}

Square::~Square() {
    cout << "Sóc el destructor de Square" << endl;
}

float Square :: getPerimeter() {
    return this->side*4;
}


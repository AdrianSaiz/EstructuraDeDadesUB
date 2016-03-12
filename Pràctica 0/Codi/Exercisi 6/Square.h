
/* 
 * File:   Square.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
 */
#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : public Figure {
public:
    Square();
    Square(float side);
    Square(const Square& orig);
    virtual ~Square();
    float getPerimeter();
private:
    float side;
};

#endif /* SQUARE_H */


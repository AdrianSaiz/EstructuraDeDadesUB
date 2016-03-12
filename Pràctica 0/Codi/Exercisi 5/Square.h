/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Square.h
 * Author: rballeba50.alumnes
 *
 * Created on 3 / març / 2016, 12:42
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


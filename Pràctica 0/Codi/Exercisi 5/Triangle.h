/* 
 * File:   Triangle.h
 * Author: Rubén Ballester Bautista
 * Author: Oriol Rabasseda Alcaide
 * 
 * Created on 25 / febrer / 2016, 12:56
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle(double baseAux, double alcadaAux);
    virtual ~Triangle();
    double getArea();
    float getPerimeter();
private:
    double base;
    double alcada;
};

#endif /* TRIANGLE_H */


/* 
 * File:   Triangle.h
 * Author: Rubén Ballester Bautista
 * Author: Oriol Rabasseda Alcaide
 * 
 * Created on 25 / febrer / 2016, 12:56
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
public:
    Triangle(double baseAux, double alcadaAux);
    virtual ~Triangle();
    double getArea();
private:
    double base;
    double alcada;
};

#endif /* TRIANGLE_H */


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
private:
    double base;
    double alcada;
public:
    Triangle(double baseAux, double alcadaAux);
    ~Triangle();
    double getArea();
};

#endif /* TRIANGLE_H */


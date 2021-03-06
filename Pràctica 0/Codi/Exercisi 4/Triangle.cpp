/* 
 * File:   Triangle.cpp
 * Author: Rubén Ballester Bautista
 * Author: Oriol Rabasseda Alcaide
 * 
 * Created on 25 / febrer / 2016, 12:56
 */
#include "Triangle.h"

Triangle::Triangle(double baseAux, double alcadaAux) {
    this->base = baseAux;
    this->alcada = alcadaAux;
}

double Triangle::getArea() {
    double area;
    area = (this->base * this->alcada ) / 2.0;
    return area;
}
Triangle::~Triangle() {};
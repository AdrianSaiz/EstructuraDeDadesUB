/* 
 * File:   Rectangle.cpp
 * Author: Rubén Ballester Bautista
 * Author: Oriol Rabasseda Alcaide
 * 
 * Created on 25 / febrer / 2016, 12:56
 */

#include "Rectangle.h"

Rectangle::Rectangle(double baseAux, double alcadaAux) : Figure() {
    this->base = baseAux;
    this->alcada = alcadaAux;
}
double Rectangle::getArea() {
    return this->base * this->alcada;
}
float Rectangle::getPerimeter() {
    return (base+alcada)*2;
}
Rectangle::~Rectangle() {
}


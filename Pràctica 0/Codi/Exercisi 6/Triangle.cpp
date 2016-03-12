/* 
 * File:   Triangle.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 * Created on 3 / març / 2016, 12:17
 */

#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(double baseAux, double alcadaAux):Figure() {
    this->base = baseAux;
    this->alcada = alcadaAux;
}

double Triangle::getArea() {
    double area;
    area = (this->base * this->alcada ) / 2.0;
    return area;
}
float Triangle::getPerimeter() {
    return (base+alcada)*2;
}
Triangle::~Triangle() {
cout << "Sóc el destructor de Triangle" << endl;
};
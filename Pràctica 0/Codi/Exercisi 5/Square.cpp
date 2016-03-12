/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Square.cpp
 * Author: rballeba50.alumnes
 * 
 * Created on 3 / març / 2016, 12:42
 */

#include "Square.h"
#include <iostream>
#include "Figure.h"

using namespace std;

Square::Square():Figure() {
    side = 1; // Per defecte
    //cout << "Sóc el constructor de Square" << endl;
}
Square::Square(float side):Figure() {
    this->side = side;
    //cout << "Sóc el constructor de Square" << endl;
}
Square::Square(const Square& orig) {
}

Square::~Square() {
}

float Square :: getPerimeter() {
    return this->side*4;
}


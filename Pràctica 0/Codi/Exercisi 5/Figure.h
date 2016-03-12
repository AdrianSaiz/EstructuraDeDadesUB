/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Figure.h
 * Author: rballeba50.alumnes
 *
 * Created on 3 / març / 2016, 12:35
 */

#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    Figure();
    Figure(const Figure& orig);
    virtual ~Figure();
    virtual float getPerimeter() = 0;
private:

};

#endif /* FIGURE_H */


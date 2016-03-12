/* 
 * File:   Figure.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
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


/* 
 * File:   FigureContainer.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
 */
#ifndef FIGURECONTAINER_H
#define	FIGURECONTAINER_H

using namespace std;
#include "Figure.h"
#include <vector>

class FigureContainer {
public:
    FigureContainer();
    FigureContainer(const FigureContainer& orig);
    virtual ~FigureContainer();
    void addFigure(Figure* figurePointer);
    float getPerimeters();
private:
    vector<Figure*> figureList;

};

#endif	/* FIGURECONTAINER_H */


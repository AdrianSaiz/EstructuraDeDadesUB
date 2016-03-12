/* 
 * File:   FigureContainer.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
 */

#include "FigureContainer.h"
#include <iostream>
using namespace std;
#include "Square.h"
#include "Triangle.h"

FigureContainer::FigureContainer() {
}

FigureContainer::FigureContainer(const FigureContainer& orig) {
}

FigureContainer::~FigureContainer() {
    Figure* figurePointerAux;
    for(vector<Figure*>::iterator it = figureList.begin(); it != figureList.end(); ++it ) {
        figurePointerAux = *it;
        if (dynamic_cast<Square*>(figurePointerAux)) {
            delete (Square*)(figurePointerAux);
        }
        else if (dynamic_cast<Triangle*>(figurePointerAux)) {
            delete(Triangle*)(figurePointerAux);
        }
    }
    figureList.clear();
    cout << "Sóc el destructor de Figure Container" << endl;
}
void FigureContainer::addFigure(Figure* figurePointer) {
    this->figureList.push_back(figurePointer);
}
float FigureContainer::getPerimeters() {
    Figure* figurePointerAux;
    float sumPerimeters = 0;
    for(vector<Figure*>::iterator it = figureList.begin(); it != figureList.end(); ++it ) {
        figurePointerAux = *it;
        sumPerimeters = sumPerimeters + figurePointerAux->getPerimeter();
    }
    return sumPerimeters;
}
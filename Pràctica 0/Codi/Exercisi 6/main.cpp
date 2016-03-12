/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 3 / març / 2016, 12:17
 */

#include <cstdlib>
#include <iostream>
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "BadInputException.h"
#include "FigureContainer.h"

using namespace std;
/**
 * Auxiliary function that checks if the user have introduced a valid input to calculate the perimeter.
 * @return a treated number which was introduced by the user
 */
double getElement() {
    double element = -1;
        do{
        try {
            cin >> element;
            if(cin.fail()) {
                //We could have declared two single exceptions but actually we preefer to experiment with the handling-exceptions methods of C++
                throw BadInputException(-2);
            }
            if(element < 0) {
                throw BadInputException(-1);
            }
        }
        catch(BadInputException& exception) {
            element = -1;
            cout << exception.what() << endl;
            cout << "Introdueix la mida correctament";
        }
    } while(element == -1);
    return element;
}
/**
 * It adds a square to the vector list.
 * @param figureCont reference to an object of the class "FigureContainer" where a square will be saved.
 */
void addSquare(FigureContainer &figureCont) {
    float base, alcada;
    Square *square;
    cout << "Introdueix la mida d'un costat del cuadrat " << endl;
    base = getElement();
    square = new Square(base);
    figureCont.addFigure(square);
}
/**
 * It adds a triangle to the vector list.
 * @param figureCont reference to an object of the class "FigureContainer" where a triangle will be saved.
 */
void addTriangle(FigureContainer &figureCont) {
    float base, alcada;
    Triangle *triangle;
    cout << "Introdueix el primer costat del triangle" << endl;
    base = getElement();
    cout << "Introdueix el segón costat del triangle" << endl;
    alcada = getElement();;
    triangle = new Triangle (base, alcada);
    figureCont.addFigure(triangle);
}
/**
 * Main method of the software.
 * @param argc
 * @param argv
 * @return 0
 */
int main(int argc, char** argv) {
    FigureContainer figureCont;
    for(int i = 0; i<2; i++) {
        addSquare(figureCont);
    }
    addTriangle(figureCont);
    cout << "Suma de perimetres = " << figureCont.getPerimeters() << endl;
    return 0;
}


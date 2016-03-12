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

using namespace std;
/*
 * 
 */
double getElement() {
    double element = -1;
        do{
        try {
            cin >> element;
            if(cin.fail()) {
                //Podriem haver declarat dos excepcions diferents i seria més correcte, però voliem experimentar amb la flexiblitat del handling-errors de C++
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

int main(int argc, char** argv) {
    Square *square;
    Triangle *triangle;
    Rectangle *rectangle;
    float base, alcada;
    cout << "Intrudueix la mida d'un costat del cuadrat" << endl;
    base = getElement();
    square = new Square(base);
    cout << "Perímetre: " << square->getPerimeter() << endl;
    delete square;
    cout << "Introdueix el primer costat del rectangle" << endl;
    base = getElement();;
    cout << "Introdueix el segón costat del rectangle" << endl;
    alcada = getElement();;
    rectangle = new Rectangle (base, alcada);
    cout << "Perímetre: " << rectangle->getPerimeter() << endl;
    delete rectangle;    
    cout << "Introdueix el primer costat del triangle" << endl;
    base = getElement();
    cout << "Introdueix el segón costat del triangle" << endl;
    alcada = getElement();;
    triangle = new Triangle (base, alcada);
    cout << "Perímetre: " << triangle->getPerimeter() << endl;
    delete triangle; 
    return 0;
}


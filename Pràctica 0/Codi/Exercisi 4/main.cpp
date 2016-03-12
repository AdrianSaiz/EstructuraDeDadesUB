/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista
 * Author: Oriol Rabasseda Alcaide
 * 
 * Created on 25 / febrer / 2016, 12:56
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream meu_fitxer("figures.txt");
    char tipus;
    double baseAux, alcadaAux;
    
    //Objectes auxiliars no inicilitzats mitjançant punters.
    Triangle *triangleAux;
    Rectangle *rectangleAux;

    while (!meu_fitxer.eof()) {
        meu_fitxer >> tipus;
        meu_fitxer >> baseAux;
        meu_fitxer >> alcadaAux;
        
        if (baseAux <= 0 || alcadaAux <= 0 || (tipus != 'T' && tipus != 'R')) {
            cout << "Atenció: aquest valor no és acceptat." << endl;
        }
        
        //En cas que tot sigui correcte procedim a donar l'informació desitjada.
        else {
            if (tipus == 'T') {
                triangleAux = new Triangle (baseAux, alcadaAux);
                cout << "Àrea del triangle " << triangleAux->getArea() << endl;
                delete triangleAux;
            }
            else {
                rectangleAux = new Rectangle (baseAux, alcadaAux);
                cout << "Àrea del rectangle " << rectangleAux->getArea() << endl;
                delete rectangleAux;
            }
        }
    }
    meu_fitxer.close(); 
    return 0;
}
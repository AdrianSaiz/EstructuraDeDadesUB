/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista
 * Author: Oriol Rabasseda Alcaide
 * 
 * Created on 25 / febrer / 2016, 12:56
 */

#include <cstdlib>
#include <iostream>
#include "Triangle.h"

using namespace std;

int main(int argc, char** argv) {
    double baseAux, alcadaAux;
    int counter;
    Triangle *triangleAux;
    char sortida;
    sortida = 'S';
    counter = 1;
    cout << "*** Inici ***" << endl;
    do {
        cout << "Triangle " << counter << endl;
        cout << "Base?" << endl;
        cin >> baseAux;
        //Comprovem que el tipus d'entrada de l'usuari sigui correcte.
        try {
            if (cin.fail() || baseAux <= 0) {
                throw "Atenció: aquest valor no és acceptat."; 
            }
            else {
                cout << "Alçada?" << endl;
                cin >> alcadaAux;
                //Comprovem que el tipus d'entrada de l'usuari sigui correcte.
                if (cin.fail() || alcadaAux <= 0) {
                    throw "Atenció: aquest valor no és acceptat.";
                }
                //En cas que tot sigui correcte procedim a donar l'informació desitjada.
                else {
                    triangleAux = new Triangle (baseAux, alcadaAux);
                    cout << triangleAux->getArea() << endl;
                    delete triangleAux;
                    //Augmentem contador de triangles totals calculats.
                    counter++;
                }   
            }
        }
        catch(const char* s) {
            cin.clear();
            cin.ignore();
            cout << s << endl;
        }
        cout << "Vols calcular un altre triangle? (S/N)" << endl;
        cin >> sortida;
    } while(sortida != 'N' && sortida != 'n');
    cout << "*** Fi ***";
    return 0;
}
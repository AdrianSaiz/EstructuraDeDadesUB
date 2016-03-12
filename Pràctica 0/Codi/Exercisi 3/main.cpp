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
#include "Rectangle.h"

using namespace std;

int main(int argc, char** argv) {
    //Variables locals que ens ajudaran en la creació dels objectes pertinents
    double baseAux, alcadaAux;
    //Emmagatzema el tipus de figura [T | R]
    char tipus;
    //Objectes auxiliars no inicilitzats mitjançant punters.
    Triangle *triangleAux;
    Rectangle *rectangleAux;
    //Variable local que permet al bucle saber quan l'usuari desitja sortir.
    char sortida;
    sortida = 'S';
    cout << "*** Inici ***" << endl;
    do {
        cout << "Entra les dades de la teva figura (tipus [T o R] base alçada):" << endl;
        cin >> tipus;
        /*Utilitzarem ifs aniuats per veure que tot funciona correctament. No podem possar totes les condicions 
        en una perque cal executar processos abans de cada condició en cas que es cumpli l'anterior */
        try {
            if(cin.good() && (tipus == 'T' || tipus == 'R')) {
                cin >> baseAux;
                if(cin.good() && baseAux > 0) {
                    cin >> alcadaAux;
                    if(cin.good() && alcadaAux > 0) {
                        cin.clear();
                        if(tipus == 'T') {
                        triangleAux = new Triangle (baseAux, alcadaAux);
                        cout << triangleAux->getArea() << endl;
                        delete triangleAux;
                        }
                        else if(tipus == 'R') {
                        rectangleAux = new Rectangle (baseAux, alcadaAux);
                        cout << rectangleAux->getArea() << endl;
                        delete rectangleAux;                        
                        }
                    }
                    else {
                        throw "El número de alçada no és correcte o ha estat mal introduït, torna a intentar-ho.";
                    }
                }
                else {
                    throw "El número de base no és correcte o ha estat mal introduït, torna a intentar-ho.";
                }
            }
            else {
                throw "El tipus de la figura no és correcte, torna a intentar-ho.";
            }
        }
        catch(char const* error) {
            cin.clear();
            cin.ignore(256 , '\n');
            cout << error;
        }
        //Comprovem si l'usuari vol afegir un altra figura.
        cout << "Vols calcular una altra figura? (S/N)" << endl;
        cin >> sortida;
    } while(sortida != 'N' && sortida != 'n');
    
    cout << "*** Fi ***";
    return 0;
}
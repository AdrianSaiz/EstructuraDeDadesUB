/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: orabasal15.alumnes
 *
 * Created on 31 / març / 2016, 12:17
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>
#include <random>
#include <iterator>
#include "LinkedQueue.h"

using namespace std;

/*
 * Algorisme donat a classe.
 */
int main(int argc, char** argv) {
    LinkedQueue cua;
    cout<< "La cua és buida? "<< cua.empty() << endl;
    int item, minut, contador, maxim, temps;
    float mitjana;
    mitjana = 0.0;
    maxim = 0;
    contador = 0;
    uniform_int_distribution<> u(1,3); //u és un enter que pot prendre els valors 1, 2 i 3
    default_random_engine e; //e és un generador de nombres random
    unsigned k; //k és l’enter que necessitem
    for (minut = 0; minut < 100; minut++) { // substituir per 100 minuts
        k=u(e); //k serà un nombre aleatori entre 1 i 3
        if (!cua.empty()) {
            item = cua.first(); // retorna el front de la cua
            cout << "El primer element de la cua és: "<< item << endl;
            temps = minut - item;
            cua.dequeue();
            cout << "El desencuem" << endl;
            if (temps > maxim) {
                maxim = temps;
            }
            mitjana += (float)temps;
        } //si la cua no és buida, treure un client
        if (k==1) { //Si k és 1 afegir un client a la cua
            cout << "Encuem " << minut << endl;
            cua.enqueue(minut);
            contador++;
        }
        else if (k==2) { //Si k és 2 afegir dos clients a la cua
            cout<<"Encuem "<<minut<<endl;
            cout<<"Encuem "<<minut<<endl;
            cua.enqueue(minut);
            cua.enqueue(minut);
            contador += 2;
        }
        else if (k==3) { // Si k és 3 no afegir ningú a la cua
        }
        cua.show(); // Imprimeix la cua per pantalla
    }
    mitjana /= (float)contador;
    cout << "El temps mig d'espera és de (minuts): " << mitjana << endl;
    cout << "El temps màxim d'espera és (minuts): " << maxim << endl;
    cout << "El nombre de persones ateses és: " << contador << endl;
    return 0;
}


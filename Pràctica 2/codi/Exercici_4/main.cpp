/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ruben
 *
 * Created on 17 de abril de 2016, 17:40
 */

#include <cstdlib>
#include "OrderedList.h"
#include "NodeList.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    NodeList<int> llista;
    OrderedList<int> llistaOrd;
    cout << "Vols introduir les dades per consola o per fitxer (C/F)?" << endl;
    if(cin.get() == 'F') {
        FILE * pFile;
        pFile = fopen("fitxer.txt" , "r");
        
        int n;
        ifstream fe("fitxer.txt");
        while (scanf("%d", &n) == 1) {
            llista.insert(n);
            llistaOrd.insert(n);
        }
    }
    else {
        cout << "Introdueix una seqüència de nombres acabada per 99:" << endl;
        int aux;
        cin >> aux;
        while(aux != 99) {
            llista.insert(aux);
            llistaOrd.insert(aux);
            cin >> aux;
        }
    }
    cout << "Llista: ";
    llista.show();
    cout << "Llista Ordenada: ";
    llistaOrd.show();
    cout << endl << "Introdueix un nombre a cercar:" << endl;
    cin >> aux;
    cout << "Nombres posteriors a " << aux << " a la llista:" << endl;
    llista.begin();
    bool trobat = false;
    while(!llista.end()) {
        if(trobat) {
            cout << llista.get() << "  " ; 
        }
        else {
            if(llista.get() == aux) trobat = true;
        }
        llista.next();
    }
    cout << endl << "Nombres posteriors a " << aux << " a la llista ordenada:" <<endl;  
    trobat = false;
    llistaOrd.begin();
    while(!llistaOrd.end()) {
        if(trobat) {
            cout << llistaOrd.get() << "  " ; 
        }
        else {
            if(llistaOrd.get() == aux) trobat = true;
        }
        llistaOrd.next();
    }    
    cout << endl << "Llista esborrada i recursos alliberats" << endl;
    llista.begin();
    while(!llista.end()) {
        llista.remove();
    }
    cout << "Llista ordenada esborrada i recursos alliberats:" << endl;
    llistaOrd.begin();
    while(!llistaOrd.end()) {
        
        llistaOrd.remove();
    }
    cout << "Llista:" << endl;
    llista.show();
    cout << "Llista ordenada:" << endl;
    llistaOrd.show();
    return 0;
}




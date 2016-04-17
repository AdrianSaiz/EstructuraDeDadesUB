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
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Esto es una prueba 
    OrderedList<int> list;
    list.insert(1);
    list.show();
    list.insert(2);
    list.show();
    list.insert(6);
    list.show();
    list.insert(4);
    list.show();
    list.begin();
    list.remove();
    list.show();
    list.begin();
    list.next();
    list.remove();
    list.modify(5);
    cout<< list.get() <<endl;
    list.show();
    cout << "Tamaño " << list.size();
    return 0;
}




/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 / març / 2016, 12:13
 */

#include <cstdlib>
#include <iostream>
#include "ArrayStack.h"

using namespace std;

bool comprovaExpresio (ArrayStack &pila) {
    if(!pila.empty()) {
        ArrayStack pilaAux2;
        ArrayStack pilaAux1;
        pilaAux1 = pila;
        cout<<"Pila 1"<<endl;
        pilaAux1.print();
        while(!pilaAux1.empty()) {
            switch (pilaAux1.top()) {
                case '[' :
                    pilaAux2.push(']');
                    break;
                case ']' :
                    pilaAux2.push('[');
                    break;
                case '(' :
                    pilaAux2.push(')');
                    break;
                case ')' :
                    pilaAux2.push('(');
                    break;
                case '{' :
                    pilaAux2.push('}');
                    break;
                case '}' :
                    pilaAux2.push('{');
                    break;
            }
            pilaAux1.pop();
        }
        cout<<"Pila"<<endl;
        pila.print();
        cout<<"Pila 2"<<endl;
        pilaAux2.print();
        cout << pila.top() << "|" << pilaAux2.top();
        while (pila.top() == pilaAux2.top()) {
            pila.pop();
            pilaAux2.pop();
        }
        if (pila.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }
}
ArrayStack getStackFromInput(ArrayStack &pila) {
    char aux;
    string cadenaAux;
    int tamanyCadena;
    cout << "Introduce a numeric expresion" << endl;
    cin >> cadenaAux;
    tamanyCadena = sizeof(cadenaAux);
    for(int i = 0; i<tamanyCadena; ++i) {
        aux = cadenaAux[i];
        if (aux == '{' || aux == '}' || aux == '[' || aux == ']' || aux == '(' ||aux == ')') {
            pila.push(aux);
        }
    }
    return pila;
}
int main(int argc, char** argv) {
    ArrayStack pila;
    getStackFromInput(pila);
    if (comprovaExpresio(pila)) {
        cout << "The expresion is well done";
    }
    else {
        cout << "The expresion is bad done"; 
    }
    return 0;
}


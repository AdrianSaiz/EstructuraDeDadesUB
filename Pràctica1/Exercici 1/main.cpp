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
        //If the stack is not empty
        ArrayStack pilaAux2;
        ArrayStack pilaAux1;
        pilaAux1 = pila;
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
        bool trobat = true;
        pilaAux2.print();
        while (!pila.empty() && !pilaAux2.empty() && trobat) {
            if(pila.top() == pilaAux2.top()) {
                pila.pop();
                pilaAux2.pop();
            }
            else {
                trobat = false;
            }
        }
        if (trobat) {
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
void getStackFromInput(ArrayStack &pila) {
    char aux;
    cout << "Introduce a numeric expresion" << endl;
    while(cin.get(aux)) {
        //Control d para parar, por ahora
        if (aux == '{' || aux == '}' || aux == '[' || aux == ']' || aux == '(' ||aux == ')') {
            pila.push(aux);
        }
    }
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


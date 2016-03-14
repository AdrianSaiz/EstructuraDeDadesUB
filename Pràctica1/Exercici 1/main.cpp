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
/**
 * It returns if top is the opposite of top2. top2 represents the elements of stack.
 * @param top1, top of expression
 * @param top2, top of stack
 */
bool topAparellat(char top1, char top2) {
    bool isClosed = false;
    switch (top2) {
        case ']' :
            isClosed = (top1 == '[') ? true : false;
            break;
        case ')' :
            isClosed = (top1 == '(') ? true : false;
            break;
        case '}' :
            isClosed = (top1 == '{') ? true : false;
            break;
    }
    return isClosed;
}
/**
 * It checks if a sequence of characters have the correct order to do a arithmetic operation.
 * @param pila The stack that is going to be analyzed
 * @return true If the expression have the correct order | false If the expression doesn't have the correct order.
 */
bool comprovaExpresio (ArrayStack &pila) {
    //If the stack is empty, it returns true because there isn't elements to analyze.
    if(!pila.empty()) {
        /**
         * If the stack is not empty, we proceed to do the next algorithm:
         * Two elements: pila (the original stack) pilaAux2 (a auxiliary stack to do the proper operations)
         * 1) If "pilaAux2" is empty, we transfer the last char of "pila" to "pilaAux2" and we delete this char from "pila". We go directly to step 4.
         *    If "pilaAux2" is not empty, we go to the step 2:
         * 2) We check if the top of pilaAux2 is equal to the opposite of top of "pila" (Note that we only check the closing expression). If it is true, we delete the char from "pilaAux2" and "pila" and we go directly to step 4. If it is not true, we go to the step 3,:
         * 3) We transfer the opposite element to pilaAux2 from pila. We go to the step 4.
         * 4)If pila is not empty, we do again the process.
         * 
         * We can prove that the loop finishes. If the size of the stack is n and also the size of the stack is a positive integer 
         * this implies that we have a size n that follow the next rule, 0<=n. If n = 0 we stop. If not, we have that in each loop we decrement 
         * the size of stack in 1 so we have a size of n-1. If n-1 = 0 pila is empty, and the algorithm stops, 
         * if not, we do again the same process until we have n=0. QED
         * 
         * If pilaAux2 is empty, that implies the expression is correct.
         * The complexity function of this algorithm is of O(n). This is because we have O(n) (we create the first stack) + O(n) (we check all elements of first stack) + O(1) (cte senteces) = 3O(n) = O(n)
         */
        ArrayStack pilaAux2;
        while(!pila.empty()) {
            
            if(pilaAux2.empty()) {
                pilaAux2.push(pila.top());
            }
            else {
                if(topAparellat(pila.top() , pilaAux2.top())) {
                    pilaAux2.pop();
                }
                else {
                    pilaAux2.push(pila.top());
                }
            }
            pila.pop();
        }
        if (pilaAux2.empty()) { 
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
    string stringAux;
    char aux;
    cout << "Introduce a numeric expresion" << endl;
    std::getline (std::cin,stringAux);
    for(char aux: stringAux) {
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
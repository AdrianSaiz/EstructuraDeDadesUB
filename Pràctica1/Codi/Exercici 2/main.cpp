/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 / març / 2016, 12:13
 */

#include <cstdlib>
#include <iostream>
#include "ArrayQueue.h"

using namespace std;

/**
 * Maximum number of elements that can contain the queue
 */
const int MAX_QUEUE = 3;

/*
 * Sequence of instructions that the queue object can run.
 */
int main(int argc, char** argv) {
    ArrayQueue mevaCua (MAX_QUEUE);
    cout << "Mida actual de la cua: " << mevaCua.size() << endl;
    cout << "Encuem 3 elements a la cua..." << endl;
    mevaCua.enqueue(1); mevaCua.enqueue(2); mevaCua.enqueue(3);
    mevaCua.print();
    cout << "Cua plena (0: no, 1: si): " << mevaCua.full() << endl;
    cout << "Traiem 1er element de la cua: " << mevaCua.dequeue() << endl;
    mevaCua.print();
    cout << "Traiem 2on element de la cua: " << mevaCua.dequeue() << endl;
    cout << "Encuem 2 elements a la cua... " << endl;
    mevaCua.enqueue(4); mevaCua.enqueue(5);
    cout << "Traiem 3er element de la cua: " << mevaCua.dequeue() << endl;
    cout << "Mida actual de la cua: " << mevaCua.size() << endl;
    mevaCua.print();
    cout << "Cua buida (0:no, 1:si): " << mevaCua.empty() << endl;
    return 0;
}


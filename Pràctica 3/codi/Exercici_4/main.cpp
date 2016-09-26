/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "AVLTree.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <ctime>
#include <exception>
#include "BalancedTreeWordFinder.h"
using namespace std;

/**
 * Main with some tests to show that the TAD BinarySearchTree is working correctly.
 */
int main(int argc, char** argv) {
    try {
        //Variables
        string stringAux;
        double duration, start;
        vector<pair<int, int>> vectorAux;
        BalancedTreeWordFinder bstFinder;
        ifstream isf("dictionary.txt");
        ///////////////////////////////////////
        //First we catch the filename
        cout << "Inserta el nom del fitxer" << endl;
        cin >> stringAux;
        ///////////////////////////////////////
        //Second we make the bstFinder with the text finded in file.
        bstFinder.appendText(stringAux);
        ///////////////////////////////////////
        //View all elements in the three.
        bstFinder.viewIndex();
        ///////////////////////////////////////
        //Now we are going to analyze the dictionary.txt
        cout << "==================" << endl << "Elements cercats" << endl << "==================" << endl;
        vector<pair<int,int>>::iterator it; 
        start = std::clock();
        //While there are new words to analyze.
        while(!isf.eof()) {
            //We catch the word.
            isf >> stringAux;
            //We return the ocurrences, if the word is not in the tree, we do nothing.
            vectorAux = bstFinder.findOccurences(stringAux);
            //Check if occurence is the sentinel
            if(vectorAux.at(0).first != -1) {
                cout << stringAux;
                cout << "[";
                //We print all ocurrences
                for(vector<pair<int,int>>::iterator it = vectorAux.begin(); it != vectorAux.end(); ++it) {
                    cout << "(" << it->first << "," << it->second << ")";
                }
                 cout << "]" << endl;
            }
        }
        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        //We print the time.
        cout << "Time:" << duration << " seconds." << endl <<"Height:" << bstFinder.height();
    }
    catch(runtime_error& e) {
        cout << e.what() << endl;
    }
    catch(out_of_range& e) {
        cout << e.what() << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}


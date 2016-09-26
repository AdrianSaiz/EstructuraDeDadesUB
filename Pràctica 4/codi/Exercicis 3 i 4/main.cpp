/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 15 / may / 2016, 12:23
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <ctime>
#include <exception>
#include "HashWordFinder.h"

using namespace std;

/**
 * Main that show that HashWordFinder is working and that does exactly what is
 * asked to do in the practice.
 */
int main(int argc, char** argv) {
    try {
        //Variables
        string stringAux;
        double duration, start;
        vector<pair<int, int>> vectorAux;
        HashWordFinder hashFinder;
        ifstream isf("dictionary.txt");
        ///////////////////////////////////////
        //First we catch the filename
        cout << "Inserta el nom del fitxer" << endl;
        cin >> stringAux;
        ///////////////////////////////////////
        //Second we make the hashFinder with the text finded in file.
        start = std::clock();
        hashFinder.appendText(stringAux);
        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Fitxer afegit en " << duration << " segons." << endl;
        ///////////////////////////////////////
        //Now we are going to analyze the dictionary.txt
        cout << endl << "==================" << endl << "Elements cercats" << endl << "==================" << endl;
        vector<pair<int,int>>::iterator it; 
        int paraulesTotals = 0, paraulesTrobades = 0;
        start = std::clock();
        //While there are new words to analyze.
        while(!isf.eof()) {
            //We catch the word.
            isf >> stringAux;
            //We return the ocurrences, if the word is not in the tree, we do nothing.
            vectorAux = hashFinder.findOccurrences(stringAux);
            //Check if occurence is the sentinel
            if(vectorAux.at(0).first != -1) {
                cout << stringAux;
                cout << "[";
                //We print all ocurrences
                for(vector<pair<int,int>>::iterator it = vectorAux.begin(); it != vectorAux.end(); ++it) {
                    cout << "(" << it->first << "," << it->second << ")";
                }
                 cout << "]" << endl;
                 paraulesTrobades++;
            }
            paraulesTotals++;
        }
        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        //We print the time.
        cout << "Time:" << duration << " seconds." << endl << " Number of cells: " <<
                hashFinder.celles() << " Number of colision: " << hashFinder.totalCol() << 
                " Max colision: " << hashFinder.maxCol() << " Empty percentage cells: " << hashFinder.perBuit() <<
                " Paraules totals cercades: " << paraulesTotals << " de les quals trobades: " << paraulesTrobades;
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


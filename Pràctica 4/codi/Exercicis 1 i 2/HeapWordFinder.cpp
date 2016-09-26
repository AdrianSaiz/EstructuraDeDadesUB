/* 
 * File:   HeapWordFinder.cpp
 * Author: Rubén Ballester Bautista / Oriol Rabasseda Alcaide
 * 
 * Created on 15 / may / 2016, 12:28
 */

#include "HeapWordFinder.h"
#include <fstream>
#include <regex>

/**
 * It allows users to append the text from a file in a HeapWordFinder
 * @param filename string with the absolute/relative path to the file.
 */
void HeapWordFinder::appendText(const string filename) {
    ifstream file(filename);
    if (file.fail()) throw runtime_error("El fitxer no existeix");
    else {
        string stringAux, stringAux2;
        int numParaula ,numLinia = 0;
        int contadorkk = 0;
        while(getline(file, stringAux)) {
            stringAux.erase (remove_if (stringAux.begin(), stringAux.end(), ::ispunct), stringAux.end()); //It deletes all puntuation marks.
            transform(stringAux.begin(), stringAux.end(), stringAux.begin(), ::tolower); //to lowercase.
            //String stream.
            istringstream iss(stringAux);
            numParaula = 0;
            while(!iss.eof()) {
                iss >> stringAux2;
                //We only insert into BST if the word is not a control char.
                if(stringAux2 != "") insertWord(stringAux2, numLinia, numParaula);
                numParaula++;
            }
            numLinia++;
        }
    }
    file.close(); 
}

/**
 * It allows users to add a new word in the HeapWordFinder.
 * @param word
 * @param line 
 * @param position
 */
void HeapWordFinder::insertWord(const string word, int line, int position) {
    heap.insert(word,line, position);
}

/**
 * It returns the ocurrences of a value given by parameter in the text.
 * @param word word to search
 * @return vector<pair<int, int>>
 */
const vector<pair<int, int>> HeapWordFinder::findOccurrences(const string word) {
    //If it doesn't exist then the BST object throws an error.
    if(heap.getPosition(word) != nullptr) {
        return heap.getPosition(word)->getValues();
    }
    else {
        vector<pair<int,int>> aRetornar;
        aRetornar.push_back(make_pair(-1,-1));
        return aRetornar;
    } 
}

/**
 * It shows the elements of the Heap in order.
 */
void HeapWordFinder::viewIndex() const {
    MinHeap<string,int> aux = heap;
    
    while (!aux.empty()) {
        aux.getPosition(aux.min())->toString();
        aux.removeMin();
    }
}
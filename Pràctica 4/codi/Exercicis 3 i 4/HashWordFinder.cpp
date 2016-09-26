/* 
 * File:   HashWordFinder.cpp
 * Author: Rubén Ballester Bautista / Oriol Rabasseda Alcaide
 * 
 * Created on 15 / may / 2016, 12:28
 */

#include "HashWordFinder.h"
#include <fstream>
#include <regex>

/**
 * It allows users to append the text from a file in a HashWordFinder
 * @param filename string with the absolute/relative path to the file.
 */
void HashWordFinder::appendText(const string filename) {
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
                if(stringAux2 != "" && stringAux2 != "–" && stringAux2 != "←") insertWord(stringAux2, numLinia, numParaula);
                numParaula++;
            }
            numLinia++;
        }
    }
    file.close(); 
}

/**
 * It allows users to add a new word in the HasWordFinder.
 * @param word
 * @param line 
 * @param position
 */
void HashWordFinder::insertWord(const string word, int line, int position) {
    hash.put(word,line, position);
}

/**
 * It returns the ocurrences of a value given by parameter in the text.
 * @param word word to search
 * @return vector<pair<int, int>>
 */
vector<pair<int, int>>& HashWordFinder::findOccurrences(const string word) {
    //If it doesn't exist then the BST object throws an error.
    if(hash.getPosition(word) != nullptr) {
        return hash.getPosition(word)->getValue();
    }
    else {
        return aRetornar;
    } 
}

/* 
 * File:   BalancedTreeWordFinder.cpp
 * Author: Oriol Rabasseda Alcaide | Rubén Ballester Bautista

 */

#include "BalancedTreeWordFinder.h"
#include <fstream>
#include <regex>
/**
 * It allows users to append the text from a file in a BST
 * @param filename string with the absolute/relative path to the file.
 */
void BalancedTreeWordFinder::appendText(const string filename) {
    ifstream file(filename);
    if (file.fail()) throw runtime_error("El fitxer no existeix");
    else {
        string stringAux, stringAux2;
        int numParaula ,numLinia = 0;
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
 * It returns the ocurrences of a value given by parameter in the text.
 * @param word word to search
 * @return vector<pair<int, int>>
 */
const vector<pair<int, int>> BalancedTreeWordFinder::findOccurences(const string word) {
    //If it doesn't exist then the BST object throws an error.
    if(tree.getPosition(word) != nullptr) {
        return tree.getPosition(word)->getValues();
    }
    else {
        vector<pair<int,int>> aRetornar;
        aRetornar.push_back(make_pair(-1,-1));
        return aRetornar;
    } 
}
/**
 * It allows users to add a new word in the BST.
 * @param word
 * @param line 
 * @param position
 */
void BalancedTreeWordFinder::insertWord(const string word, const int line, const int position) {
    tree.insert(word,line, position);
}
/**
 * It shows the elements of the BST in order.
 */
void BalancedTreeWordFinder::viewIndex() const {
    tree.printInorder();
}
const int BalancedTreeWordFinder::height() const {
    return tree.height();
}


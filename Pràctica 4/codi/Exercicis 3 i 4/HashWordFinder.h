/* 
 * File:   HeapWordFinder.h
 * Author: Rubén Ballester Bautista / Oriol Rabasseda Alcaide
 * 
 * Created on 15 / may / 2016, 12:28
 */

#ifndef HASHWORDFINDER_H
#define HASHWORDFINDER_H

#include <string>
#include "HashMap.h"
#include <vector>

using namespace std;

class HashWordFinder {
public:
    HashWordFinder() {aRetornar.push_back(make_pair(-1,-1));};
    virtual ~HashWordFinder() {};
    void appendText(const string filename);
    void insertWord(const string word, int line, int  position);
    vector<pair<int, int>>& findOccurrences(const string word);
    int celles() {return hash.celles;};
    int totalCol() {return hash.size - hash.celles;};
    int maxCol() {return hash.colisioMax;};
    int perBuit() {return hash.celles*100/hash.MAX_TABLE;};
private:
    HashMap <string,int> hash;
    vector<pair<int,int>> aRetornar;
};

#endif /* HASHWORDFINDER_H */




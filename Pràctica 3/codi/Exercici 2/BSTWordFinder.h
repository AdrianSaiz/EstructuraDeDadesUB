/* 
 * File:   BSTWordFinder.h
 * Author: Rubén Ballester Bautista / Oriol Rabasseda Alcaide
 * 
 * Created on 28 / abril / 2016, 12:28
 */

#ifndef BSTWORDFINDER_H
#define BSTWORDFINDER_H

#include <string>
#include "BinarySearchTree.h"
#include <vector>

using namespace std;
class BSTWordFinder {
public:
    BSTWordFinder() {};
    virtual ~BSTWordFinder() {};
    void appendText(const string filename);
    void insertWord(const string word, const int line, const int position);
    const int height() const;
    const vector<pair<int,int>> findOccurences(const string word);
    void viewIndex() const;
private:
    BinarySearchTree<string, int> tree;
};

#endif /* BSTWORDFINDER_H */


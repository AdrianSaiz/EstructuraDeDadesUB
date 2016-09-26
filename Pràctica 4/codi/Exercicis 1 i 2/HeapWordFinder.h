/* 
 * File:   HeapWordFinder.h
 * Author: Rubén Ballester Bautista / Oriol Rabasseda Alcaide
 * 
 * Created on 15 / may / 2016, 12:28
 */

#ifndef HEAPWORDFINDER_H
#define HEAPWORDFINDER_H

#include <string>
#include "MinHeap.h"
#include <vector>

using namespace std;

class HeapWordFinder {
public:
    HeapWordFinder() {};
    virtual ~HeapWordFinder() {};
    void appendText(const string filename);
    void insertWord(const string word, int line, int  position);
    const vector<pair<int, int>> findOccurrences(const string word);
    void viewIndex() const;
    int height() {return heap.height();};
private:
    MinHeap <string,int> heap;
};

#endif /* HEAPWORDFINDER_H */


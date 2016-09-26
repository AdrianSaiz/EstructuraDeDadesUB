/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedTreeWordFinder.h
 * Author: orabasal15.alumnes
 *
 * Created on 12 / maig / 2016, 12:29
 */

#ifndef BALANCEDTREEWORDFINDER_H
#define BALANCEDTREEWORDFINDER_H

#include <string>
#include "AVLTree.h"
#include <vector>

class BalancedTreeWordFinder {
public:
    BalancedTreeWordFinder() {};
    virtual ~BalancedTreeWordFinder() {};
    void appendText(const string filename);
    void insertWord(const string word, const int line, const int position);
    const int height() const;
    const vector<pair<int,int>> findOccurences(const string word);
    void viewIndex() const;
private:
    AVLTree<string, int> tree;
private:

};

#endif /* BALANCEDTREEWORDFINDER_H */


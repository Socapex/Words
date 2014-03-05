//
//  CGenerateSentence.h
//  Words
//
//  Created by Philippe Groarke on 2014-03-04.
//  Copyright (c) 2014 Groarke & Co. All rights reserved.
//

#ifndef __Words__CGenerateSentence__
#define __Words__CGenerateSentence__

#include <iostream>
#include <vector>
#include <list>
#include <locale>
#include <algorithm>

#include "CMap.h"

using namespace std;

class CGenerateSentence {
public:
    CGenerateSentence(CMap &map);
    //~CGenerateSentence();

    void generate();
    void Bruteforce();
    void GenerateFile();

    void setNumSentence(const int &num);
    void setRandomness(const int &rand);
    void setMinWords(const int &min);
    void setMaxWords(const int &max);
    void setMinChars(const int &min);
    void setMaxChars(const int &max);

private:
    CMap getNextMarkovWord(list<CMap> maps) const;
    vector<pair<CTYPE> > sortChildren(CMap map) const;
    string getRandomTopString(vector<pair<CTYPE> > sortedVector) const;
    CMap getRandomSentenceTerminator() const;

    string getFirstSentenceWord() const;

    CMap* _map;
    vector<pair<CTYPE> > _sortedWordsByCount;
    vector<string> _sentenceTerminators;
    int _numSentence, _randomness, _minWords, _maxWords, _minChars, _maxChars;
};

#endif /* defined(__Words__CGenerateSentence__) */

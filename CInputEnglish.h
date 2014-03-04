//
//  CInputEnglish.h
//  Words
//
//  Created by Philippe Groarke on 2014-03-03.
//  Copyright (c) 2014 Groarke & Co. All rights reserved.
//

#ifndef __Words__CInputEnglish__
#define __Words__CInputEnglish__

#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "CMap.h"

using namespace std;

class CInputEnglish {
public:
    CInputEnglish(CMap &map);
//    ~CInputEnglish();

    void ReadStdin();
    void ReadFile(string filename);
    void setMarkovLength(const int& length);

private:
    void addWord(string &word);
    void insertChain();

    CMap* _map;
    list<string> _markovChain;
    int _markovLength;
};

#endif /* defined(__Words__CInputEnglish__) */

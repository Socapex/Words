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
    int ReadFile(string filename);
    //void setMarkovLength(const int& length);

private:
    void parseText(char &c);
    void addWord();
    void addCharacter(string c);
    void insertChain();

    CMap* _map;
    list<string> _markovChain;
    //int _markovLength;
    string _currentWord;
};

#endif /* defined(__Words__CInputEnglish__) */

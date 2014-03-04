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

#include "CMap.h"

using namespace std;

class CGenerateSentence {
public:
    CGenerateSentence(CMap &map);
    //~CGenerateSentence();

    void generate(const int &num);
    void Bruteforce();
    void GenerateFile();

    void setMinWords(const int &min);
    void setMaxWords(const int &max);
    void setMinChars(const int &min);
    void setMaxChars(const int &max);

private:
    CMap* _map;
    int _minWords, _maxWords, _minChars, _maxChars;
};

#endif /* defined(__Words__CGenerateSentence__) */

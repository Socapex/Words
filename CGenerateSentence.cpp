//
//  CGenerateSentence.cpp
//  Words
//
//  Created by Philippe Groarke on 2014-03-04.
//  Copyright (c) 2014 Groarke & Co. All rights reserved.
//

#include "CGenerateSentence.h"


CGenerateSentence::CGenerateSentence(CMap &map)
{
    _map = &map;
}

void CGenerateSentence::generate(const int &num)
{
    
}

void CGenerateSentence::Bruteforce()
{

}

void CGenerateSentence::GenerateFile()
{

}

// SETTERS/GETTERS
void CGenerateSentence::setMinWords(const int &min)
{
    _minWords = min;
}

void CGenerateSentence::setMaxWords(const int &max)
{
    _maxWords = max;
}

void CGenerateSentence::setMinChars(const int &min)
{
    _minChars = min;
}

void CGenerateSentence::setMaxChars(const int &max)
{
    _maxChars = max;
}



// PRIVATE



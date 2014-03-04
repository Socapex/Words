//
//  CInputEnglish.cpp
//  Words
//
//  Created by Philippe Groarke on 2014-03-03.
//  Copyright (c) 2014 Groarke & Co. All rights reserved.
//

#include "CInputEnglish.h"

CInputEnglish::CInputEnglish(CMap &map)
{
    _map = &map;
}

void CInputEnglish::ReadStdin()
{

}

void CInputEnglish::ReadFile(string filename)
{

    ifstream file;
    file.open( filename.c_str(), ifstream::in );
    string word;
    //char x ;
    word.clear();

    string words[3];
    unsigned int count = 0;

    //int c;

    while( file.good() )
    {
        char c = file.get();   // get character from file

        if( file.good() )
        {
            switch( c )
            {
                case ' ':
                    addWord(words, word, count );
                    break;

                case '\n':
                    if( word.empty() )
                    {
                        addWord(words, word, count );
                    }
                    break;

                default:
                    word = word + c;
            }
        }
        else if( word.empty() )
        {
            addWord(words, word, count );
        }
    }
    
    _map->GetMap().erase("");
    file.close();

}





void CInputEnglish::addWord(string* words, string& word, unsigned int& count )
{
    words[2] = words[1];
    words[1] = words[0];
    words[0] = word;
    if( count > 2 )
    {
        _map->insert( words[2] ).insert( words[1] ).insert( words[0] );
    }
    else
    {
        count++;
    }
    word.clear();
}

void CInputEnglish::setMarkovLength(const int &length)
{
    _markovLength = length;
}
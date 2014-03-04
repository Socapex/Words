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
    _markovLength = 3;
}


void CInputEnglish::ReadStdin()
{

}


void CInputEnglish::ReadFile(string filename)
{

    ifstream file;
    file.open( filename.c_str(), ifstream::in );
    string word;
    word.clear();

    while( file.good() )
    {
        char c = file.get();   // get character from file

        if( file.good() )
        {
            switch( c )
            {
                case ' ':
//                    cout << word << endl;
                    addWord(word);
                    break;

                case ',':
                    addWord(word);
                    word = ",";
                    addWord(word);
                    break;

                case ';':
                    addWord(word);
                    word = ";";
                    addWord(word);
                    break;

                case '-':
                    addWord(word);
                    word = "-";
                    addWord(word);
                    break;

                // Terminating strings
                case '.':
                    //Get the first word.
                    addWord(word);
                    //Now process .
                    word = ".";
                    addWord(word);
                    break;

                case '?':
                    addWord(word);
                    word = ".";
                    addWord(word);
                    break;

                case '!':
                    addWord(word);
                    word = ".";
                    addWord(word);
                    break;

                // Custom stuff
                case '\n':
                    addWord(word);
                    break;

                case '\'':
                    //Do nothing for now
                    break;
                case '"':
                    break;
                case '(':
                    break;
                case ')':
                    break;

                default:
//                    cout << c << endl;
                    word = word + c;
            }
        }
//        else if( word.empty() )
//        {
//            addWord(word);
//        }
    }

    file.close();

}


void CInputEnglish::addWord(string& word)
{
    if (word.empty()) {
        return;
    }

    //cout << word << endl;

    // Check beginning of text
    if (_markovChain.size() < _markovLength)
    {
        _markovChain.push_back(word);

        // Reached the correct size?
        if (_markovChain.size() == _markovLength)
            insertChain();
    }
    else
    {
        // Make the new chain
        _markovChain.pop_front();
        _markovChain.push_back(word);

        insertChain();
    }

    word.clear();
}


void CInputEnglish::insertChain()
{
    // Insert the chain
    CMap* previousMap = _map;

    for (auto x : _markovChain)
    {
        previousMap = &previousMap->insert(x);
    }
}


void CInputEnglish::setMarkovLength(const int &length)
{
    _markovLength = length;
}
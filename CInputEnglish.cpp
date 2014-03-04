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
    _currentWord.clear();
}


void CInputEnglish::ReadStdin()
{
    char c;
    while (cin.get(c))
    {
        parseText(c);
    }
}

int CInputEnglish::ReadFile(string filename)
{

    ifstream file;
    file.open( filename.c_str(), ifstream::in );

    if (file.fail())
    {
        cout << "Couldn't open " << filename << endl;
        return -1;
    }

    while( file.good() )
    {
        char c = file.get();   // get character from file

        if( file.good() )
        {
            parseText(c);
        }

//        else if( _currentWord.empty() )
//        {
//            addWord(_currentWord);
//        }
    }

    file.close();
    return 0;
}


void CInputEnglish::parseText(char &c)
{
    switch( c )
    {
        case ' ':
            //                    cout << _currentWord << endl;
            addWord();
            break;

        case ',':
            addCharacter(",");
            break;

        case ';':
            addCharacter(";");
            break;

        case ':':
            addCharacter(":");
            break;

        case '-':
            addCharacter("-");
            break;

            // Terminating strings
        case '.':
            addCharacter(".");
            break;

        case '?':
            addCharacter("?");
            break;

        case '!':
            addCharacter("!");
            break;

            // Custom stuff
        case '\n':
            addWord();
            break;

            //Do nothing for now
        case '\'':
            break;
        case '"':
            break;
        case '(':
            break;
        case ')':
            break;
        case '{':
            break;
        case '}':
            break;
        case '[':
            break;
        case ']':
            break;
        case '_':
            break;
        case '*':
            break;

        default:
            //                    cout << c << endl;
            _currentWord += c;
    }

}



void CInputEnglish::addWord()
{
    if (_currentWord.empty()) {
        return;
    }

    //cout << _currentWord << endl;

    // Check beginning of text
    if (_markovChain.size() < _markovLength)
    {
        _markovChain.push_back(_currentWord);

        // Reached the correct size?
        if (_markovChain.size() == _markovLength)
            insertChain();
    }
    else
    {
        // Make the new chain
        _markovChain.pop_front();
        _markovChain.push_back(_currentWord);

        insertChain();
    }

    _currentWord.clear();
}

void CInputEnglish::addCharacter(string c)
{
    addWord();
    _currentWord = c;
    addWord();
}


void CInputEnglish::insertChain()
{
    // Point to our map, it will be changed after every insert.
    CMap* previousMap = _map;

    // Insert the chain
    for (auto x : _markovChain)
    {
        previousMap = &previousMap->insert(x);
    }
}


void CInputEnglish::setMarkovLength(const int &length)
{
    _markovLength = length;
}
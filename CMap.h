//
//  CMap.h
//  Words
//
//  Created by Alexandre Arsenault on 2014-03-06.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//
#ifndef DEF_CMAP
#define DEF_CMAP

#include <iostream>
#include <string>

#include <map>
#include "CWord.h"
#include "CDebug.h"



using namespace std;

class CMap;

#define CTYPE string,CMap

typedef pair<CTYPE> CPair;
typedef map<CTYPE>::iterator CIterator;

class CMap
{
public:
    CMap();

    // C++ Doc:
    // Because element keys in a map are unique, the insertion operation
    // checks whether each inserted element has a key equivalent to the
    // one of an element already in the container, and if so, the element
    // is not inserted, returning an iterator to this existing element
    // (if the function returns a value).
    CMap &insert(  const string& str  );

    CMap GetWordMap(const string& str ) const;

    CWord GetWord() const;

    void SetWord( const string& word );
    void SetWordCount (const int &count);
    void incrementWordCount();

	void Print(ostream& stream = cout);

    unsigned long GetSize() const;

	void SetMap(map<CTYPE>& m);

    map<CTYPE>& GetMap()
    {
        return _map;
    }

    void setMarkovLength(const int &len);
    int getMarkovLength() const;

	//bool Save( const string& path );

    //CWord& operator[] ( const string& str );
    friend bool operator== (const CMap &map1, const CMap &map2);

private:
    map<CTYPE> _map;
    CWord _word;
    int _markovLength;
};


// Function pointer
extern bool orderCMapByCount(pair<CTYPE> first, pair<CTYPE> second);

extern CMap notFound; // Une map retourner quand ca trouve rien... P-e pas tres nice

#endif

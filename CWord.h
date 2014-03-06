//
//  CAttribute.h
//  Words
//
//  Created by Alexandre Arsenault on 2014-03-06.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//
#ifndef DEF_CWORD
#define DEF_CWORD

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "CAttribute.h"

using namespace std;

#define ATT_STRING ( 0 )
#define ATT_COUNT  ( 1 )

class CWord
{
public:
	CWord();

    CWord( const string& word ):
		   // Members
           _word(word), _count(1)
    {

    }

    CAttribute* GetAttribute( const unsigned int& index )
    {
        return (CAttribute*)(_attributes[index]);
    }

	CAttribute* operator[](const string& att);
	bool AddAttribute(const string& att_name, CAttribute* att);

    CLong GetCount() const;

    void increment();

    void SetWord( const string& word );
    void SetCount(const int &count);

    string GetString() const;

	// Why friend ??
    friend bool operator== (const CWord &word1, const CWord &word2);

private:
    string _word;
    CLong _count;

    vector< CAttribute* > _attributes;
	map<string, CAttribute*> _map;
};


#endif

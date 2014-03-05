#ifndef DEF_CWORD
#define DEF_CWORD

#include <iostream>
#include <string>
#include <vector>

#include "CAttribute.h"

using namespace std;

#define ATT_STRING ( 0 )
#define ATT_COUNT ( 1 )

class CWord
{
public:
    CWord():
    // Members
        _count( 0 )
    {
        _attributes.push_back( new CString( "MyString") );
        _attributes.push_back( new CCount() );
    }

    CWord( const string& word ):
    // Members
        _word(word), _count(1)
    {

    }

    CAttribute* GetAttribute( const unsigned int& index )
    {
        return (CAttribute*)(_attributes[index]);//->GetAttribute());
    }

    CLong GetCount() const;

    void increment();

    void SetWord( const string& word );
    void SetCount(const int &count);

    string GetString() const;

    friend bool operator== (const CWord &word1, const CWord &word2);

private:
    string _word;
    CLong _count;

    vector< CAttribute* > _attributes;
};


#endif

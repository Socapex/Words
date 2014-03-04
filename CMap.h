#ifndef DEF_CMAP
#define DEF_CMAP

#include <iostream>
#include <string>

#include <map>
#include "CWord.h"

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

    CMap& GetWordMap(const string& str );

    CWord& GetWord();

    void SetWord( const string& word );

    void Print();

    unsigned long GetSize();

	void SetMap(map<CTYPE>& m);

    map<CTYPE>& GetMap()
    {
        return _map;
    }

	//bool Save( const string& path );

    //CWord& operator[] ( const string& str );

private:
    map<CTYPE> _map;
    CWord _word;
};

#endif

#ifndef DEF_C_ATTRIBUTE
#define DEF_C_ATTRIBUTE

#include <iostream>
#include <string>

using namespace std;

typedef unsigned long CLong;

class CAttribute
{
public:
    CAttribute(){}
};

class CCount : public CAttribute
{
public:
    CCount():
    // Members
        _count( 0 ) {}

    CLong GetCount()
    {
        return _count;
    }

private:
    CLong _count;
};


class CString : public CAttribute
{
public:
    CString() {}

    CString( const string& str ):
    // Members
        _str( str ) {}

    string GetString()
    {
        return _str;
    }

private:
    string _str;
};

#endif // DEF_C_ATTRIBUTE.

//
//  CAttribute.h
//  Words
//
//  Created by Alexandre Arsenault on 2014-03-06.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//
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

template<typename T>
class CAtt: public CAttribute
{
public:
	CAtt() :
		// Members
		_att(0) {}

	T& GetValue()
	{
		return _att;
	}

	void SetValue(const T& v)
	{
		_att = v;
	}

private:
	T _att;
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

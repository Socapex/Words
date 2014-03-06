//
//  CDebug.h
//  Words
//
//  Created by Alexandre Arsenault on 2014-03-06.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//
#ifndef DEF_C_DEBUG
#define DEF_C_DEBUG

#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

// Assert function with assert line and messsage.
#define ASSERT(condition, message) \
	if (!(condition)) {cerr << "Assert `" #condition "` failed in " \
		<< __FILE__ << " line " << __LINE__ << ": " << message << endl; \
		assert((condition)); }

enum CDebugOutputList
{
	D_FLOW,
	D_OUT1,
	D_OUT2
};

class CDebug
{
public:
	CDebug();
	~CDebug();

	ofstream& operator[] (const CDebugOutputList& out);

private:
	ofstream _outs[3];
};

extern CDebug DEBUG;

#endif // DEF_C_DEBUG.

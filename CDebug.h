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
#include <iomanip>
#include <string>

using namespace std;

#if __APPLE__
/// @todo Find macro for demangled function name. 
#define __func__
#else
#define FCT_NAME __FUNCTION__ 
#endif

// Output exit message in program flow output.
#define DEBUG_EXIT(value, text) DEBUG[D_FLOW] << \
								"EXIT : " << text << endl; exit(value)

// Output function name in program flow output.
#define DEBUG_FCT DEBUG[D_FLOW] << FCT_NAME << endl;

// Assert function with assert line and messsage.
#define ASSERT(condition, message) \
	if (!(condition)) {cerr << "Assert `" #condition "` failed in " \
		<< __FILE__ << " line " << __LINE__ << ": " << message << endl; \
		assert((condition)); }

// Output a progress bar on stdout.
void CProgressBar(const double& value0_1, const string& msg);

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
	void Show();

private:
	ofstream _outs[3];
	bool _show;
};

extern CDebug DEBUG;

#endif // DEF_C_DEBUG.

//
//  COption.h
//  Words
//
//  Created by Alexandre Arsenault and Philippe Groarke on 2014-03-06.
//  Copyright (c) 2014. All rights reserved.
//
#ifndef DEF_C_OPTION
#define DEF_C_OPTION

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#ifdef __APPLE__
#include <getopt.h>
#else
#include "getopt.h"
#endif

#include "CDebug.h"

class COption
{
public:
	COption();

	void init(int argc, char* argv[]);

private:
	void printHelp();
	virtual void OnReadFile(const string& str){ (void)str; };
	virtual void OnReadStdin(){}
	virtual void OnSetMarkovChain(const int& length){ (void)length; }
	virtual void OnSetNumberSentence(const int& nb){ (void)nb; }
	virtual void OnSetRandomness(const int& random){ (void)random; }
	virtual void OnSetMinWords(const int& min){ (void)min; }
	virtual void OnSetMaxWords(const int& max){ (void)max; }
	virtual void OnSetMinChars(const int& min_char){ (void)min_char; }
	virtual void OnSetMaxChars(const int& max_char){ (void)max_char; }
	virtual void OnGenerate(){}
	virtual void OnPrintMostUsed(const int& num){ (void)num; }
};

#endif // DEF_C_OPTION.

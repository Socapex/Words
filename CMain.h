//
//  CMain.h
//  Words
//
//  Created by Alexandre Arsenault on 2014-03-06.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//
#ifndef DEF_C_MAIN
#define DEF_C_MAIN

#include "CMap.h"
#include "CDataBase.h"
#include "CInputEnglish.h"
#include "CGenerateSentence.h"
#include "CAnalysis.h"
#include "COption.h"

class CMain : public COption
{
public:
	CMain();

	CMap* GetMap();
	CInputEnglish* GetCInputEnglish()
	{
		return &_inputEnglish;
	}
	CGenerateSentence* GetCGenerateSentence()
	{
		return &_generator;
	}
	CAnalysis* GetCAnalysis()
	{
		return &_analyser;
	}

private:
	CMap _map;
	CInputEnglish _inputEnglish;
	CGenerateSentence _generator;
	CAnalysis _analyser;

	virtual void OnReadFile(const string& str);
	virtual void OnReadStdin();
	virtual void OnSetMarkovChain(const int& length);
	virtual void OnSetNumberSentence(const int& nb);
	virtual void OnSetRandomness(const int& random);
	virtual void OnSetMinWords(const int& min);
	virtual void OnSetMaxWords(const int& max);
	virtual void OnSetMinChars(const int& min_char);
	virtual void OnSetMaxChars(const int& max_char);
	virtual void OnGenerate();
	virtual void OnPrintMostUsed(const int& num);
	virtual void OnDebug();
};

#endif // DEF_C_MAIN.

#include "CMain.h"

CMain::CMain(int argc, char* argv[]) :
			//Heritage
			COption(),
			// Members
			_map(),
			_inputEnglish(_map),
			_generator(_map),
			_analyser(_map)
{
	DEBUG[D_FLOW] << "CMain constructor" << endl;

	init(argc, argv);
}

CMap* CMain::GetMap()
{
	return &_map;
}

void CMain::OnReadFile(const string& str)
{
	if (_inputEnglish.ReadFile(str) == -1)
	{
		exit(0);
	}
}

void CMain::OnReadStdin()
{
	_inputEnglish.ReadStdin();
}

void CMain::OnSetMarkovChain(const int& length)
{
	_map.setMarkovLength(length);
}

void CMain::OnSetNumberSentence(const int& nb)
{
	_generator.setNumSentence(nb);
}

void CMain::OnSetRandomness(const int& random)
{
	_generator.setRandomness(random);
}
void CMain::OnSetMinWords(const int& min)
{
	_generator.setMinWords(min);
}

void CMain::OnSetMaxWords(const int& max)
{
	_generator.setMaxWords(max);
}

void CMain::OnSetMinChars(const int& min_char)
{
	_generator.setMinChars(min_char);
}

void CMain::OnSetMaxChars(const int& max_char)
{
	_generator.setMaxChars(max_char);
}

void CMain::OnGenerate()
{
	_generator.generate();
}

void CMain::OnPrintMostUsed(const int& num)
{
	_analyser.PrintMostUsed(num);
}
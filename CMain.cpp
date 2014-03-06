#include "CMain.h"

CMain::CMain() :
			//Heritage
			COption(),
			// Members
			_map(),
			_inputEnglish(_map),
			_generator(_map),
			_analyser(_map)
{
	DEBUG_FCT

	// Add Markov chaine length argument to the first map.
	_map.AddWordAttribute("Markov", new ATT_MARKOV_T(3));

	//init(argc, argv);
}

CMap* CMain::GetMap()
{
	return &_map;
}

void CMain::OnReadFile(const string& str)
{
	DEBUG_FCT
	if (_inputEnglish.ReadFile(str) == -1)
	{
		DEBUG_EXIT(0, "Couldn't open" << str);
	}
}

void CMain::OnDebug()
{
	DEBUG_FCT
	DEBUG.Show();
}

void CMain::OnReadStdin()
{
	DEBUG_FCT
	_inputEnglish.ReadStdin();
}

void CMain::OnSetMarkovChain(const int& length)
{
	DEBUG_FCT
	((ATT_MARKOV_T*)_map.GetWordAttribute("Markov"))->SetValue(length);
}

void CMain::OnSetNumberSentence(const int& nb)
{
	DEBUG_FCT
	_generator.setNumSentence(nb);
}

void CMain::OnSetRandomness(const int& random)
{
	DEBUG_FCT
	_generator.setRandomness(random);
}
void CMain::OnSetMinWords(const int& min)
{
	DEBUG_FCT
	_generator.setMinWords(min);
}

void CMain::OnSetMaxWords(const int& max)
{
	DEBUG_FCT
	_generator.setMaxWords(max);
}

void CMain::OnSetMinChars(const int& min_char)
{
	DEBUG_FCT
	_generator.setMinChars(min_char);
}

void CMain::OnSetMaxChars(const int& max_char)
{
	DEBUG_FCT
	_generator.setMaxChars(max_char);
}

void CMain::OnGenerate()
{
	DEBUG_FCT
	_generator.generate();
}

void CMain::OnPrintMostUsed(const int& num)
{
	DEBUG_FCT
	_analyser.PrintMostUsed(num);
}
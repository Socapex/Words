#include "CDebug.h"

CDebug DEBUG;

CDebug::CDebug() :
		// Members
		_show(0)
{
	//cerr << "Error output." << endl;

	_outs[D_FLOW].open("D_FLOW.txt", ofstream::out);

	if (_outs[D_FLOW].fail())
	{
		cout << "Couldn't open " << "OUTPUT1.txt" << endl;
	}

	_outs[D_OUT1].open("D_OUT1.txt", ofstream::out);

	if (_outs[D_OUT1].fail())
	{
		cout << "Couldn't open " << "OUTPUT2.txt" << endl;
	}

	_outs[D_OUT2].open("D_OUT2.txt", ofstream::out);

	if (_outs[D_OUT2].fail())
	{
		cout << "Couldn't open " << "OUTPUT2.txt" << endl;
	}

	DEBUG_FCT
}

CDebug::~CDebug()
{
	DEBUG_FCT

	_outs[D_FLOW].close();
	_outs[D_OUT1].close();
	_outs[D_OUT2].close();

	if (_show)
	{
#if __APPLE__

#else
		_wexecl(L"C:/Python27/python.exe", L"C:/Python27/python.exe C:/Words/debug.py", NULL);
#endif
	}	
}

void CDebug::Show()
{
	_show = true;
}

ofstream& CDebug::operator[] (const CDebugOutputList& out)
{
	return _outs[out];
}
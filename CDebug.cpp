#include "CDebug.h"

CDebug DEBUG;

void CProgressBar(const double& value0_1, const string& msg)
{
	string bar;
	if (value0_1 == 1.0)
	{
		cout << left << setfill(' ') << setw(100) << "" << '\xd';
		cout << msg << " : Completed." << endl;
	}
	else
	{
		unsigned int nBar = (unsigned int)(value0_1 * 50);
		for (unsigned int n = 0; n < nBar; n++)
			bar += "=";

		cout << msg << " : " << left << setw(50) << bar << " " \
		   	 << setprecision(2) << right << setw(6) << fixed << value0_1 * 100.0 << "%" << '\xd';
	}
}

CDebug::CDebug() :
		// Members
		_show(0)
{
	_outs[D_FLOW].open("D_FLOW.txt", ofstream::out);

	if (_outs[D_FLOW].fail())
	{
		system("color 8");
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
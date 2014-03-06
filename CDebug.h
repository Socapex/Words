#ifndef DEF_C_DEBUG
#define DEF_C_DEBUG

#include <iostream>
#include <fstream>

using namespace std;

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
	//ofstream& OUTPUT1();
	//ofstream& OUTPUT2();

	ofstream& operator[] (const CDebugOutputList& out);

private:
	//ofstream _out1, _out2;
	ofstream _outs[3];
};


#endif // DEF_C_DEBUG.

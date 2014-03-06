#include <iostream>
#include <string>

#include "CMain.h"

using namespace std;

int main(int argc, char* argv[])
{
	DEBUG[D_FLOW] << "PROGRAM START" << endl;

	CMain cmain(argc, argv);
	cmain.GetMap()->Print(DEBUG[D_OUT1]);

	//CDataBase data_base(mymap);
	//data_base.SaveData("cdb");
	//data_base.ReadData("cdb");

	DEBUG[D_FLOW] << "PROGRAM END" << endl;

	return 0;
}




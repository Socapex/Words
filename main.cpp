#include <iostream>
#include <string>

#include "CMain.h"

using namespace std;

int main(int argc, char* argv[])
{
	DEBUG[D_FLOW] << "PROGRAM START" << endl;

	CMain cmain;
	cmain.init(argc, argv);
	//CMap* m = cmain.GetMap();
	//cmain.GetCAnalysis()->PrintSorted(DEBUG[D_OUT1]);

    //ATT_MARKOV_T* markov = (ATT_MARKOV_T*)m->GetWordAttribute("Markov");
	//DEBUG[D_OUT2] << "ATTRIBUTE MARKOV : " << markov->GetValue() << endl;
	
	//CDataBase data_base(mymap);
	//data_base.SaveData("cdb");
	//data_base.ReadData("cdb");

	DEBUG[D_FLOW] << "PROGRAM END" << endl;

	return 0;
}




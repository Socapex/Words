#include <iostream>
#include <string>

#include "CMain.h"

using namespace std;

int main(int argc, char* argv[])
{
	DEBUG[D_FLOW] << "PROGRAM START" << endl;

	CMain cmain(argc, argv);
	CMap* m = cmain.GetMap();
	m->Print(DEBUG[D_OUT1]);

	// Refaire cette routine plus simplement dans CMap::GetWordAttribute("...").
	//---------------------------------------
	CAtt<unsigned int> att_markov;
	att_markov.SetValue(4);
	CWord* w = m->GetWordPtr();
	w->AddAttribute("Markov", &att_markov);

	CWord* w2 = m->GetWordPtr();
	CAttribute* att2 = (*w2)["Markov"];
	int value = ((CAtt<unsigned int>*)att2)->GetValue();
	DEBUG[D_OUT2] << "ATTRIBUTE MARKOV : " << value << endl;
	//---------------------------------------
	
	//CDataBase data_base(mymap);
	//data_base.SaveData("cdb");
	//data_base.ReadData("cdb");

	DEBUG[D_FLOW] << "PROGRAM END" << endl;

	return 0;
}




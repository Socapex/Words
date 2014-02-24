#ifndef DEF_CSAVE
#define DEF_CSAVE

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <fstream>
#include <map>
#include "CMap.h"

using namespace std;

struct c_map_struct
{
	uint8_t word_length;
	uint8_t* word;
	uint32_t nCWord; // Number of CWord.
	c_map_struct* c_map;
};

class CDataBase
{
public:
	CDataBase(CMap& root):_root(root)
	{
	}

	bool SaveData(const string& path);
	void PrintMap();
	bool ReadData(const string& path);

private:
	CMap& _root;
};

#endif

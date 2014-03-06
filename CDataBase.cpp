#include "CDataBase.h"
//#include <Windows.h>

bool CDataBase::SaveData(const string& path)
{
	ofstream outfile(path, ofstream::binary);

	//-----------------------------------------------------------
	// Root.
	//-----------------------------------------------------------
	uint8_t s = (uint8_t)_root.GetWord().GetString().size();
	unsigned long nCWord = _root.GetSize();

	//cout << "ROOT SIZE : " << _root->GetSize() << endl;

	outfile.write((const char*)&s, 1);
	outfile.write(_root.GetWord().GetString().c_str(), s);
	outfile.write((const char*)&nCWord, 4);

	//-----------------------------------------------------------
	// First layer.
	//-----------------------------------------------------------
	map<CTYPE> m1 = _root.GetMap();
	vector< pair<CTYPE> > v(m1.begin(), m1.end());

	for (unsigned int i = 0; i < v.size(); ++i)
	{
		s = (uint8_t)v[i].second.GetWord().GetString().size();
		nCWord = v[i].second.GetSize();

		outfile.write((const char*)&s, 1);
		outfile.write(v[i].second.GetWord().GetString().c_str(), s);
		outfile.write((const char*)&nCWord, 4);

		//-------------------------------------------------------
		map<CTYPE> m2 = v[i].second.GetMap();
		vector< pair<CTYPE> > v2(m2.begin(), m2.end());

		for (unsigned int n = 0; n < v2.size(); ++n)
		{
			s = (uint8_t)v2[n].second.GetWord().GetString().size();
			nCWord = v2[n].second.GetSize();

			outfile.write((const char*)&s, 1);
			outfile.write(v2[n].second.GetWord().GetString().c_str(), s);
			outfile.write((const char*)&nCWord, 4);

			//---------------------------------------------------
			map<CTYPE> m3 = v2[n].second.GetMap();
			vector< pair<CTYPE> > v3(m3.begin(), m3.end());

			for (unsigned int k = 0; k < v3.size(); ++k)
			{
				s = (uint8_t)v3[k].second.GetWord().GetString().size();
				nCWord = v3[k].second.GetSize();

				outfile.write((const char*)&s, 1);
				outfile.write(v3[k].second.GetWord().GetString().c_str(), s);
				outfile.write((const char*)&nCWord, 4);
			}
		}
	}

	outfile.close();

	return true;
}

void CDataBase::PrintMap()
{
	map<CTYPE> m1 = _root.GetMap();
	vector< pair<CTYPE> > v(m1.begin(), m1.end());
	cout << "FIRST WORD:" << endl;
	int n = 0;
	for (auto i : v)
	{
		cout << n++ << i.second.GetWord().GetString() << endl;
	}
}

bool CDataBase::ReadData(const string& path)
{
	ifstream infile(path, ios::in | ios::binary | ios::ate);
	infile.seekg(0, ios::beg);

	uint8_t str_size = 0;
	uint32_t nWord = 0;

	CMap m;

	infile.read((char*)&str_size, 1);
	if (str_size != 0)
	{
		char* c = new char[str_size];
		infile.read(c, str_size);
		m.SetWord(c);
		delete c; c = nullptr;
	}
	
	infile.read((char*)&nWord, 4);

	cout << (unsigned int)str_size << endl;
	cout << (unsigned int)nWord << endl;
	//-------------------------------------------
	// First layer.
	//for (int i = 0; i < nWord; ++i)
	//{
		CMap m1;
		str_size = 0;
		infile.read((char*)&str_size, 1);

		cout << (unsigned int)str_size << endl;

		if (str_size > 0)
		{
			char* c = new char[str_size+1];
			infile.read(c, str_size);
			c[str_size] = '\0';
			m1.SetWord(c);
			cout << m1.GetWord().GetString() << endl;
			delete c; c = nullptr;
		}

		uint32_t nWord_1 = 0;
		infile.read((char*)&nWord_1, 4);

		cout << (unsigned int)nWord_1 << endl;
	//}




	infile.close();

	return true;
}

CDataBase& CDataBase::operator = (CDataBase& database)
{
	(void)database;
	return *this;
}
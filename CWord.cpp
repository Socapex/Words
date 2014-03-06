#include "CWord.h"

CWord::CWord() :
	   // Members
	   _count(0)
{
	_attributes.push_back(new CString("MyString"));
	_attributes.push_back(new CCount());
}

CLong CWord::GetCount() const
{
    return _count;
}

void CWord::increment()
{
    _count++;
}

void CWord::SetWord( const string& word )
{
    _word = word;
    _count++;
}

void CWord::SetCount(const int &count)
{
    _count = count;
}

string CWord::GetString() const
{
    return _word;
}

bool CWord::AddAttribute(const string& att_name, CAttribute* att)
{
	_map.insert(pair<string, CAttribute*>(att_name, att));
	return 0;
}

// Operators
CAttribute* CWord::operator[](const string& att)
{
	map<string, CAttribute*>::iterator it = _map.find(att);
	if (it != _map.end())
	{
		return it->second;
	}
	return nullptr;
}

bool operator== (const CWord &word1, const CWord &word2)
{
    return word1._word == word2._word;
}
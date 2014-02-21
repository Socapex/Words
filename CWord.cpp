#include "CWord.h"

CLong CWord::GetCount()
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

string CWord::GetString()
{
    return _word;
}

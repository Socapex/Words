#include "CWord.h"

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



// Operators

bool operator== (const CWord &word1, const CWord &word2)
{
    return word1._word == word2._word;
}
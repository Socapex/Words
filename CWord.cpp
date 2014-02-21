#include "CWord.h"

CLong CWord::GetCount()
{
    return $count;
}

void CWord::increment()
{
    $count++;
}

void CWord::SetWord( const string& word )
{
    $word = word;
    $count++;
}

string CWord::GetString()
{
    return $word;
}

#include "CMap.h"

CDebug DEBUG;

CMap notFound;

bool orderCMapByCount(pair<CTYPE> first, pair<CTYPE> second)
{
    return first.second.GetWord().GetCount() > second.second.GetWord().GetCount();
}


CMap::CMap()
{
    _markovLength = 3;
}

CMap& CMap::insert(  const string& str  )
{

    pair<CIterator,bool> ret = _map.insert( CPair(str, CMap()) );

    // The pair::second element in the pair is set to true if a new element
    // was inserted or false if an equivalent key already existed.
    if( ret.second == false) //EXIST
    {
        ret.first->second.incrementWordCount();
        //cout << "Element already exist --- ";
        //cout << str << " :          " << ret.first->second.GetWord().GetCount() << endl;
    }
    else //EXIST PAS
    {
        ret.first->second.SetWord( str );
    }

    return ret.first->second;
}

CMap CMap::GetWordMap( const string& str ) const
/// @todo What happen when the word "str" is not in the map.
{
    if (_map.find(str) != _map.end())
        return _map.find( str )->second;

//    CMap criss;

    return notFound;
//    return criss;
}

CWord CMap::GetWord() const
{
    return _word;
}

void CMap::SetWord( const string& word )
{
    _word.SetWord( word );
}

void CMap::SetWordCount(const int &count)
{
    _word.SetCount(count);
}

void CMap::incrementWordCount()
{
    _word.increment();
}

void CMap::Print()
{
    for( CIterator i = _map.begin(); i != _map.end(); ++i )
    {

        cout << i->second.GetWord().GetString() << "    (" << i->second.GetWord().GetCount() << ") ";
        cout << "size :     " << i->second.GetSize() << endl;
    }
}

unsigned long CMap::GetSize() const
{
    return _map.size();
}

void CMap::SetMap(map<CTYPE>& m)
{
	if (_map.size() != 0)
	{
		cout << "Map wasn't empty." << endl;
	}
	_map = m;
}


void CMap::setMarkovLength(const int &len)
{
    _markovLength = len;
}

int CMap::getMarkovLength() const
{
    return _markovLength;
}




// Operators
bool operator== (const CMap &map1, const CMap &map2)
{
    return (map1._map == map2._map) && (map1._word == map2._word);
}







//bool CMap::Save( const string& path )
//{
//	return 0;
//}

//CMap& CMap::operator[] ( const string& str )
//{
//    pair<CInterator,bool> ret = $map.insert( CPair(str,CWord(str) ));
//    if( !ret.second )
//    {
//        ret.first->second.increment();
//        cout << "Element already exist." << endl;
//        cout << str << " : " << ret.first->second.GetCount() << endl;

//        return ret.first->second;
//    }
//    else
//    {
//        ret.first->second.$map = new CMap();
//    }


//    return ret.first->second;
//}

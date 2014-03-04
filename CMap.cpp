#include "CMap.h"

CMap::CMap()
{
}

CMap& CMap::insert(  const string& str  )
{

    pair<CIterator,bool> ret = _map.insert( CPair(str, CMap()) );
    
	if( !ret.second )
    {
        ret.first->second.GetWord().increment();
        //cout << "Element already exist --- ";
        //cout << str << " :          " << ret.first->second.GetWord().GetCount() << endl;
    }
    else
    {
        ret.first->second.SetWord( str );
    }

    return ret.first->second;
}

CMap& CMap::GetWordMap( const string& str )
{
    return ( _map.find( str )->second );
}

CWord& CMap::GetWord()
{
    return _word;
}

void CMap::SetWord( const string& word )
{
    _word.SetWord( word );
}

void CMap::Print()
{
    for( CIterator i = _map.begin(); i != _map.end(); ++i )
    {

        cout << i->second.GetWord().GetString() << "    (" << i->second.GetWord().GetCount() << ") ";
        cout << "size :     " << i->second.GetSize() << endl;
    }
}

unsigned long CMap::GetSize()
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

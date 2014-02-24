#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>
#include "CMap.h"
#include "CDataBase.h"

using namespace std;

void addWord( CMap* map, string* words, string& word, unsigned int& count )
{
    words[2] = words[1];
    words[1] = words[0];
    words[0] = word;
    if( count > 2 )
    {
        map->insert( words[2] ).insert( words[1] ).insert( words[0] );
    }
    else
    {
        count++;
    }
    word.clear();
}

void readfile( const string& path, CMap& map )
{
    ifstream file;
    file.open( path.c_str(), ifstream::in );
    string word;
    //char x ;
    word.clear();

    string words[3];
    unsigned int count = 0;

    //int c;

    while( file.good() )
    {
        char c = file.get();   // get character from file

        if( file.good() )
        {
            switch( c )
            {
                case ' ':
                    addWord( &map, words, word, count );
                    break;

            case '\n':
                if( word.empty() )
                {
                    addWord( &map, words, word, count );
                }
                break;

                default:
                    word = word + c;
            }
        }
        else if( word.empty() )
        {
            addWord( &map, words, word, count );
        }
    }

	map.GetMap().erase("");
    file.close();
}

bool myFunction(pair<CTYPE> first, pair<CTYPE> second)
{
    return first.second.GetWord().GetCount() > second.second.GetWord().GetCount();
}

void print_by_weight( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
    sort( myVec.begin(),myVec.end(),&myFunction );

    for( unsigned int i = 0; i < myVec.size(); i++ )
    {
        cout << myVec[i].first << "(" << myVec[i].second.GetWord().GetCount() << ")" << endl;
    }
}

// Not the best way to do it.
CMap& GetMostUse( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
	
    sort( myVec.begin(), myVec.end(), &myFunction );

	return m.GetWordMap(myVec[0].first);
}

CMap& GetOneOfTopThree( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
    sort( myVec.begin(),myVec.end(),&myFunction );
    //cout << (rand() % 3) << endl;

    if( myVec.size() > 3 )
    {
        //rand() % 3
		return m.GetWordMap(myVec[rand() % 3].first);
    }
    else if( myVec.size() > 2)
    {
        //rand() % 2
		return m.GetWordMap(myVec[rand() % 2].first);
    }
    else
    {
        return m.GetWordMap( myVec[0].first );
    }
}

CMap& GetFirstWord( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
    sort( myVec.begin(),myVec.end(),&myFunction );

    //rand() % 10
    return m.GetWordMap( myVec[rand() % 8].first );

}

int main()
{
    srand( (unsigned int)time( NULL ) );

    CMap mymap;
	readfile("test.txt", mymap);

	//CDataBase data_base(mymap);
	//data_base.SaveData("cdb");
	//data_base.ReadData("cdb");

	//data_base.PrintMap();
	

	CMap k = GetOneOfTopThree(mymap);
    cout << k.GetWord().GetString() << " ";
    CMap l = GetOneOfTopThree( k );
    cout << l.GetWord().GetString() << " ";
    CMap m = GetOneOfTopThree( l );
    cout << m.GetWord().GetString() << " ";

	CMap n = mymap.GetWordMap(l.GetWord().GetString());
    CMap o = n.GetWordMap( m.GetWord().GetString() );
    CMap p = GetOneOfTopThree( o );
    cout << p.GetWord().GetString() << " ";

	CMap q = mymap.GetWordMap(o.GetWord().GetString());
    CMap r = q.GetWordMap( p.GetWord().GetString() );
    CMap s = GetOneOfTopThree( r );
    cout << s.GetWord().GetString() << " ";

	CMap t = mymap.GetWordMap(r.GetWord().GetString());
    CMap u = t.GetWordMap( s.GetWord().GetString() );
    CMap v = GetOneOfTopThree( u );
    cout << v.GetWord().GetString() << " ";

	CMap w = mymap.GetWordMap(u.GetWord().GetString());
    CMap x = w.GetWordMap( v.GetWord().GetString() );
    CMap y = GetOneOfTopThree( x );
    cout << y.GetWord().GetString() << " ";

	CMap z = mymap.GetWordMap(x.GetWord().GetString());
    CMap a = z.GetWordMap( y.GetWord().GetString() );
    CMap b = GetOneOfTopThree( a );
    cout << b.GetWord().GetString() << " ";

	CMap c = mymap.GetWordMap(a.GetWord().GetString());
    CMap d = c.GetWordMap( b.GetWord().GetString() );
    CMap e = GetOneOfTopThree( d );
	cout << e.GetWord().GetString() << " " << endl;


    //print_by_weight( map.GetWordMap("system") );

    //cout << "------------------------------------" << endl;
    //cout << "THE STUDY" << endl;
    //cout << "------------------------------------" << endl;
    //print_by_weight( map.GetWordMap("study").GetWordMap("of") );
	system("pause");
    return 0;
}

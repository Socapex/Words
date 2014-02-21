#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>

#include "CMap.h"

using namespace std;

void readfile( const string& path, CMap& map )
{
    ifstream file;
    file.open( path.c_str(), ifstream::in );
    string word;
    char x ;
    word.clear();

    string words[3];
    unsigned count = 0;

    while ( file >> word && file.good() )
    {
        x = file.get();

        while ( x != ' ' )
        {
            word = word + x;
            x = file.get();
        }

        words[2] = words[1];
        words[1] = words[0];
        words[0] = word;

        if( count > 2 )
        {
            map.insert( words[2] ).insert( words[1] ).insert( words[0] );
        }
        //cout<< word <<endl;
        count++;

        word.clear();
    }

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

    for( int i = 0; i < myVec.size(); i++ )
    {
        cout << myVec[i].first << "(" << myVec[i].second.GetWord().GetCount() << ")" << endl;
    }
}

// Not the best way to do it.
CMap& GetMostUse( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
    sort( myVec.begin(),myVec.end(),&myFunction );

    return m.GetWordMap( myVec[0].first );
}

CMap& GetOneOfTopThree( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
    sort( myVec.begin(),myVec.end(),&myFunction );
    //cout << (rand() % 3) << endl;

    if( myVec.size() > 3)
        return m.GetWordMap( myVec[rand() % 3].first );
    else if( myVec.size() > 2)
        return m.GetWordMap( myVec[rand() % 2].first );
    else
        return m.GetWordMap( myVec[0].first );
}

CMap& GetFirstWord( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
    sort( myVec.begin(),myVec.end(),&myFunction );
    //cout << (rand() % 3) << endl;

    //rand() % 10
    return m.GetWordMap( myVec[rand() % 8].first );

}

int main()
{
    srand( time( NULL ) );

    CMap map;
    readfile( "text.txt", map );

    CMap k = GetOneOfTopThree( map );
    cout << k.GetWord().GetString() << " ";
    CMap l = GetOneOfTopThree( k );
    cout << l.GetWord().GetString() << " ";
    CMap m = GetOneOfTopThree( l );
    cout << m.GetWord().GetString() << " ";

    CMap n = map.GetWordMap( l.GetWord().GetString() );
    CMap o = n.GetWordMap( m.GetWord().GetString() );
    CMap p = GetOneOfTopThree( o );
    cout << p.GetWord().GetString() << " ";

    CMap q = map.GetWordMap( o.GetWord().GetString() );
    CMap r = q.GetWordMap( p.GetWord().GetString() );
    CMap s = GetOneOfTopThree( r );
    cout << s.GetWord().GetString() << " ";

    CMap t = map.GetWordMap( r.GetWord().GetString() );
    CMap u = t.GetWordMap( s.GetWord().GetString() );
    CMap v = GetOneOfTopThree( u );
    cout << v.GetWord().GetString() << " ";

    CMap w = map.GetWordMap( u.GetWord().GetString() );
    CMap x = w.GetWordMap( v.GetWord().GetString() );
    CMap y = GetOneOfTopThree( x );
    cout << y.GetWord().GetString() << " ";

    CMap z = map.GetWordMap( x.GetWord().GetString() );
    CMap a = z.GetWordMap( y.GetWord().GetString() );
    CMap b = GetOneOfTopThree( a );
    cout << b.GetWord().GetString() << " ";

    CMap c = map.GetWordMap( a.GetWord().GetString() );
    CMap d = c.GetWordMap( b.GetWord().GetString() );
    CMap e = GetOneOfTopThree( d );
    cout << e.GetWord().GetString() << " ";


    //print_by_weight( map.GetWordMap("system") );

    //cout << "------------------------------------" << endl;
    //cout << "THE STUDY" << endl;
    //cout << "------------------------------------" << endl;
    //print_by_weight( map.GetWordMap("study").GetWordMap("of") );

    return 0;
}

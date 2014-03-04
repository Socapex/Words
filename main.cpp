#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>
#include <stdlib.h>

// TEMPORAIRE! Juste pour debugger un truc :)
#ifdef __APPLE__
#include <unistd.h>
#include <signal.h>
#include <getopt.h>
#else
#include "getopt.h"
#endif


#include "CMap.h"
#include "CDataBase.h"
#include "CInputEnglish.h"

using namespace std;


void printHelp()
{
    cout << "########################" << endl
    << "Word Engine" << endl << "v0.01" << endl
    << "########################" << endl << endl;

    cout << "Usage: words [options]" << endl << endl;

    cout << "========" << endl
    << "Options" << endl
    << "========" << endl << endl;

    cout << "* Input:" << endl << endl;
    cout << setw(20) << left << "--stdin" << "Read from input pipe." << endl;
    cout << setw(20) << left << "-i [filename]" << "Read from text file." << endl;
    cout << setw(20) << left << "-m [number]" << "Markov length (default 3)." << endl;

    cout << endl << endl;
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

int main(int argc, char* argv[])
{
    //Wait for debugger to attach
    //Mac only je pense...
    //kill(getpid(), SIGSTOP);


    // Initialise stuff
    CMap mymap;
    CInputEnglish inputEnglish(mymap);


    //MENU
    if (argc == 1)
    {
        printHelp();
        return 0;
    }

    //http://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Option-Example.html
    static struct option long_options[] =
    {
        {"help",    no_argument,        0, 'h'},
        {"stdin",   no_argument,        0, 's'},
        {"i",       required_argument,  0, 'b'},
        {"m",       required_argument,  0, 'm'},
        {0, 0, 0, 0}
    };
    int option_index = 0;

    int opt = 0;
    while ((opt = getopt_long(argc, argv, "i:shm:", long_options, &option_index))
           != -1)
    {
        switch (opt) {
            case 'i':
//                cout << " got i" << endl;
                if (inputEnglish.ReadFile((string)optarg) == -1)
                    return -1;
                break;

            case 'm':
                inputEnglish.setMarkovLength(atoi(optarg));
                break;

            case 's':
//                cout << "got stdin" << endl;
                inputEnglish.ReadStdin();
                break;

            case 'h':
                printHelp();
                return 0;
                break;

            case '?':
                cout << "dfgdfgdf" << endl;
                return 0;
                break;
                
            default:
                printHelp();
                return 0;
                break;
        }
    }







    srand( (unsigned int)time( NULL ) );

	//readfile("test.txt", mymap);

	CDataBase data_base(mymap);
	data_base.SaveData("cdb");
	data_base.ReadData("cdb");

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


//    print_by_weight( map );

    //cout << "------------------------------------" << endl;
    //cout << "THE STUDY" << endl;
    //cout << "------------------------------------" << endl;
    //print_by_weight( map.GetWordMap("study").GetWordMap("of") );
#ifdef _MSC_VER
	system("pause");
#endif
    return 0;
}

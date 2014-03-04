#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>
#include "getopt.h"
#include <stdlib.h>

#include "CMap.h"
#include "CDataBase.h"
#include "CInputEnglish.h"

using namespace std;

void generateSentence(CMap& mymap,
					  const unsigned int& length,
					  const unsigned int& nb_sentense);

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
                inputEnglish.ReadFile((string)optarg);
                break;

            case 'm':
                inputEnglish.setMarkovLength(atoi(optarg));
                break;

            case 's':
//                cout << "got stdin" << endl;
                break;

            case 'h':
                printHelp();
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

	//for (int i = 0; i < 5000; i++)
	//	cout << "Process--------------" << i << '\xd';

	CDataBase data_base(mymap);
	data_base.SaveData("cdb");
	data_base.ReadData("cdb");

	//data_base.PrintMap();
	generateSentence(mymap, 5, 8);

	


//    print_by_weight( map );

    //cout << "------------------------------------" << endl;
    //cout << "THE STUDY" << endl;
    //cout << "------------------------------------" << endl;
    //print_by_weight( map.GetWordMap("study").GetWordMap("of") );

//#ifdef _MSC_VER >= 1600
	//system("pause");
	//cout << "Test" << endl;
//#endif
    return 0;
}

void generateSentence(CMap& mymap, 
					  const unsigned int& nb_sentense, 
					  const unsigned int& length)
{	
	for (unsigned int n = 0; n < nb_sentense; ++n)
	{
		vector<string> sentence;
		CMap* m1 = &GetOneOfTopThree(mymap);
		CMap* m2 = &GetOneOfTopThree(*m1);
		CMap* m3 = &GetOneOfTopThree(*m2);

		sentence.push_back(m1->GetWord().GetString());
		sentence.push_back(m2->GetWord().GetString());
		sentence.push_back(m3->GetWord().GetString());

		for (unsigned int i = 3; i < length; ++i)
		{
			m1 = &mymap.GetWordMap(m2->GetWord().GetString());
			m2 = &m1->GetWordMap(m3->GetWord().GetString());
			m3 = &GetOneOfTopThree(*m2);
			sentence.push_back(m3->GetWord().GetString());
		}

		for (string s : sentence)
		{
			cout << s << " ";
		}
		cout << endl;
	}
}
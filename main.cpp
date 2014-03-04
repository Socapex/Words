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
//#ifdef __APPLE__
//#include <unistd.h>
//#include <signal.h>
//#include <getopt.h>
//#else
#include "getopt.h"
//#endif


#include "CMap.h"
#include "CDataBase.h"
#include "CInputEnglish.h"
#include "CGenerateSentence.h"
#include "CAnalysis.h"

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

    //Input
    cout << "* Input:" << endl << endl;
    cout << setw(25) << left << "--stdin" << "Read from input pipe." << endl;
    cout << setw(25) << left << "-i [filename]" << "Read from text file." << endl;
    cout << setw(25) << left << "-m [number]" << "Markov length (default 3)." << endl;

    //Output
    cout << endl << "* Output:" << endl << endl;
    cout << setw(25) << left << "-g [number]" << "Generate x number of sentences." << endl;
    cout << setw(25) << left << "--bruteforce" << "Generate all sentences." << endl;
    cout << setw(25) << left << "--stdout" << "Write to general output." << endl;
    cout << setw(25) << left << "-o [filename]" << "Write to text file." << endl;
    cout << setw(25) << left << "--min-words [number]" << "Minimum sentence words"
        " (default 3)." << endl;
    cout << setw(25) << left << "--max-words [number]" << "Maximum sentence words"
        " (default none)." << endl;
    cout << setw(25) << left << "--min-chars [number]" << "Minimum sentence characters,"
        "including spaces (default none)." << endl;
    cout << setw(25) << left << "--max-chars [number]" << "Maximum sentence characters,"
        "including spaces (default none)." << endl;

    //Analysis
    cout << endl << "* Analysis:" << endl;
    cout << setw(25) << left << "--top-words [number]" << "Print most used words." << endl;

    cout << endl << endl;
}


CMap& GetOneOfTopThree( CMap& m )
{
    map<CTYPE> myMap = m.GetMap();
    vector< pair<CTYPE> > myVec( myMap.begin(), myMap.end() );
    sort( myVec.begin(),myVec.end(),&orderCMapByCount );
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
    sort( myVec.begin(),myVec.end(),&orderCMapByCount );

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
    CGenerateSentence generator(mymap);
    CAnalysis analyser(mymap);



    //MENU
    if (argc == 1)
    {
        printHelp();
        return 0;
    }

    //http://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Option-Example.html
    static struct option long_options[] =
    {
        {"help",        no_argument,        0, 'h'},

        //Input
        {"stdin",       no_argument,        0, 's'},
        {"i",           required_argument,  0, 'b'},
        {"m",           required_argument,  0, 'm'},

        //Output
        {"g",           required_argument,  0, 'g'},
        {"bruteforce",  no_argument,        0, 'B'},
        {"stdout",      no_argument,        0, 'S'},
        {"o",           required_argument,  0, 'o'},
        {"min-words",   required_argument,  0, 'w'},
        {"max-words",   required_argument,  0, 'W'},
        {"min-chars",   required_argument,  0, 'c'},
        {"max-chars",   required_argument,  0, 'C'},

        //Analysis & Debug
        {"top-words",   required_argument,  0, 't'},
        {0, 0, 0, 0}
    };
    int option_index = 0;

    int opt = 0;
    while ((opt = getopt_long(argc, argv, "i:shm:", long_options, &option_index))
           != -1)
    {
        switch (opt) {
            case 'h':
                printHelp();
                return 0;
                break;

        //Input
            case 'i':
                if (inputEnglish.ReadFile((string)optarg) == -1)
                    return -1;
                break;

            case 'm':
                inputEnglish.setMarkovLength(atoi(optarg));
                break;

            case 's':
                inputEnglish.ReadStdin();
                break;

            //Output
            case 'g':
                generator.generate(atoi(optarg));
                break;

            case 'w':
                generator.setMinWords(atoi(optarg));
                break;
            case 'W':
                generator.setMaxWords(atoi(optarg));
                break;
            case 'c':
                generator.setMinChars(atoi(optarg));
                break;
            case 'C':
                generator.setMaxChars(atoi(optarg));
                break;            

            //Analysis
            case 't':
                analyser.PrintMostUsed(atoi(optarg));
                break;




            case '?':
                cout << "What happened?" << endl;
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

	generateSentence(mymap, 1, 5);

	return 0;
}


// Sentenses must contain at least three words.
void generateSentence(CMap& mymap, 
					  const unsigned int& nb_sentense, 
					  const unsigned int& length)
{	
    // Generate "nb_sentense" number of sentenses.
	for (unsigned int n = 0; n < nb_sentense; ++n)
	{
        // Vector of size "length" words contaning the sentense.
		vector<string> sentense(length);

		// Get three first words.
		CMap* m1 = &GetOneOfTopThree(mymap);
		CMap* m2 = &GetOneOfTopThree(*m1);
		CMap* m3 = &GetOneOfTopThree(*m2);

		// Fill the vector with the first three words in the sentense.
		sentense[0] = m1->GetWord().GetString();
		sentense[1] = m2->GetWord().GetString();
		sentense[2] = m3->GetWord().GetString();
	
		// Add the rest of the words to the sentense.
		for (unsigned int i = 3; i < length; ++i)
		{
			m1 = &mymap.GetWordMap(m2->GetWord().GetString());
			m2 = &m1->GetWordMap(m3->GetWord().GetString());
			m3 = &GetOneOfTopThree(*m2);
			sentense[i] = m3->GetWord().GetString();
		}

		// Show sentense.
		for (string s : sentense)
		{
			cout << s << " ";
		}
		cout << endl;
	}
}

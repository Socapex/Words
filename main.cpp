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
#include "CDebug.h"

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

    //Input
    cout << "* Input:" << endl << endl;
    cout << setw(25) << left << "-m [number]" << "Markov length (default 3)." << endl;
    cout << setw(25) << left << "--stdin" << "Read from input pipe." << endl;
    cout << setw(25) << left << "-i [filename]" << "Read from text file." << endl;

    //Output
    cout << endl << "* Output:" << endl << endl;
    cout << setw(25) << left << "-n [number]" << "Generate n number of sentences." << endl;
    cout << setw(25) << left << "-r [number]" << "Randomness value (higher means "
        "more words included with lower count)." << endl;
    cout << setw(25) << left << "--min-words [number]" << "Minimum sentence words"
    " (default 3)." << endl;
    cout << setw(25) << left << "--max-words [number]" << "Maximum sentence words"
    " (default none)." << endl;
    cout << setw(25) << left << "--min-chars [number]" << "Minimum sentence characters,"
    "including spaces (default none)." << endl;
    cout << setw(25) << left << "--max-chars [number]" << "Maximum sentence characters,"
    "including spaces (default none)." << endl;
    cout << setw(25) << left << "--bruteforce" << "Generate all sentences." << endl;
    cout << setw(25) << left << "--stdout" << "Write to general output." << endl;
    cout << setw(25) << left << "-o [filename]" << "Write to text file." << endl;


    //Analysis
    cout << endl << "* Analysis:" << endl <<endl;
    cout << setw(25) << left << "--top-words [number]" << "Print most used words." << endl;

    cout << endl << endl;
}





int main(int argc, char* argv[])
{
    //Marche pas, cest quoi ste marde la?
	//DEBUG[D_FLOW] << "PROGRAM START_________________________________" << endl;

    //Wait for debugger to attach
    //Mac only je pense...
    //kill(getpid(), SIGSTOP);


    // Initialise stuff
    CMap mymap;
    CInputEnglish inputEnglish(mymap);
    CGenerateSentence generator(mymap);
    CAnalysis analyser(mymap);

    //Get better randomness...
    srand( (unsigned int)time( NULL ) );

	//DEBUG.OUTPUT1() << "TEST1" << endl;
	//DEBUG.OUTPUT2() << "TEST2" << endl;

    //MENU
    if (argc == 1)
    {
        printHelp();
        return 0;
    }

    //www.gnu.org/software/libc/manual/html_node/Getopt-Long-Option-Example.html
    static struct option long_options[] =
    {
        {"help",        no_argument,        0, 'h'},

        //Input
        {"stdin",       no_argument,        0, 's'},
        {"i",           required_argument,  0, 'i'},
        {"m",           required_argument,  0, 'm'},

        //Output
        {"n",           required_argument,  0, 'n'},
        {"r",           required_argument,  0, 'r'},
        {"min-words",   required_argument,  0, 'w'},
        {"max-words",   required_argument,  0, 'W'},
        {"min-chars",   required_argument,  0, 'c'},
        {"max-chars",   required_argument,  0, 'C'},
        {"stdout",      no_argument,        0, 'S'},
        {"bruteforce",  no_argument,        0, 'B'},
        {"o",           required_argument,  0, 'o'},

        //Analysis & Debug
        {"top-words",   required_argument,  0, 't'},
        {0, 0, 0, 0}
    };
    int option_index = 0;

    int opt = 0;
    while ((opt = getopt_long(argc, argv, "hsm:i:sn:r:w:W:c:C:SBo:", long_options, &option_index))
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
                mymap.setMarkovLength(atoi(optarg));
                //inputEnglish.setMarkovLength(atoi(optarg));
                break;

            case 's':
                inputEnglish.ReadStdin();
                break;

            //Output
            case 'n':
                generator.setNumSentence(atoi(optarg));
                break;
            case 'r':
                if (atoi(optarg) <= 0)
                {
                    cout << "Random value should be greater than 0." << endl;
                    return -1;
                }
                generator.setRandomness(atoi(optarg));
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
            case 'S':
                generator.generate();
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


	//readfile("test.txt", mymap);

	CDataBase data_base(mymap);
	data_base.SaveData("cdb");
	data_base.ReadData("cdb");

	//generateSentence(mymap, 1, 5);

	//DEBUG[D_FLOW] << "PROGRAM END___________________________________" << endl;

	return 0;
}




#include "COption.h"

COption::COption()
{
	DEBUG_FCT
}

void COption::init(int argc, char* argv[])
{
	DEBUG_FCT

	for (int i = 0; i < argc; i++) 
		m_DEBUG[D_FLOW] << argv[i] << " ";
	m_DEBUG[D_FLOW] << endl;
	

	//MENU
	if (argc == 1)
	{
		printHelp();
		DEBUG_EXIT(0, "argc == 1");
	}

	static struct option long_options[] =
	{
		{ "help", no_argument, 0, 'h' },

		//Input
		{ "stdin", no_argument, 0, 's' },
		{ "i", required_argument, 0, 'i' },
		{ "m", required_argument, 0, 'm' },

		//Output
		{ "n", required_argument, 0, 'n' },
		{ "r", required_argument, 0, 'r' },
		{ "min-words", required_argument, 0, 'w' },
		{ "max-words", required_argument, 0, 'W' },
		{ "min-chars", required_argument, 0, 'c' },
		{ "max-chars", required_argument, 0, 'C' },
		{ "stdout", no_argument, 0, 'S' },
		{ "bruteforce", no_argument, 0, 'B' },
		{ "o", required_argument, 0, 'o' },

		//Analysis & Debug
		{ "top-words", required_argument, 0, 't' },
		//Debug
		{ "DEBUG", no_argument, 0, 'D' },
		{ 0, 0, 0, 0 }
	};

	int option_index = 0;

	int opt = 0;
	while ((opt = getopt_long(argc, argv, "hsm:Di:sn:r:w:W:c:C:SBo:", long_options, &option_index))
		!= -1)
	{
		switch (opt)
		{
			// Input
			case 'i': OnReadFile((string)optarg); break;
			case 'm': OnSetMarkovChain(atoi(optarg)); break;
			case 's': OnReadStdin(); break;
			// Output
			case 'n': OnSetNumberSentence(atoi(optarg)); break;
			case 'w': OnSetMinWords(atoi(optarg)); break;
			case 'W': OnSetMaxWords(atoi(optarg)); break;
			case 'c': OnSetMinChars(atoi(optarg)); break;
			case 'C': OnSetMaxChars(atoi(optarg)); break;
			case 'S': OnGenerate(); break;
			// Debug
			case 'D': OnDebug(); break;
			// Analysis
			case 't': OnPrintMostUsed(atoi(optarg)); break;

			case 'r':
				if (atoi(optarg) <= 0)
				{
					cout << "Random value should be greater than 0." << endl;
					DEBUG_EXIT(0, "Random value should be greater than 0.");
				}
				OnSetRandomness(atoi(optarg));
				break;

			case 'h':
				printHelp();
				DEBUG_EXIT(0, "Print Help.");
				break;

			case '?':
				cout << "What happened?" << endl;
				DEBUG_EXIT(0, "What happened?");
				break;

			default:
				printHelp();
				DEBUG_EXIT(0, "PrintHelp");	
		}
	}
}

void COption::printHelp()
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
	cout << endl << "* Analysis:" << endl << endl;
	cout << setw(25) << left << "--top-words [number]" << "Print most used words." << endl;

	cout << endl << endl;
}
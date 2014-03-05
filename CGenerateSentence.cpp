//
//  CGenerateSentence.cpp
//  Words
//
//  Created by Philippe Groarke on 2014-03-04.
//  Copyright (c) 2014 Groarke & Co. All rights reserved.
//

#include "CGenerateSentence.h"


CGenerateSentence::CGenerateSentence(CMap &map)
{
    _map = &map;

    _sortedWordsByCount = sortChildren(map);

    _sentenceTerminators.push_back(".");
    _sentenceTerminators.push_back("!");
    _sentenceTerminators.push_back("?");
}

void CGenerateSentence::generate(const int &num)
{
    // Generate num sentences
    for (int i = 0; i < num; ++i)
    {
        string sentence = getFirstSentenceWord();
        CMap lastWordMap = _map->GetWordMap(sentence);
        string newWord = "";

        // While last character isn't terminator (. ! ?)
        while (find(_sentenceTerminators.begin(), _sentenceTerminators.end(),
                    newWord) == _sentenceTerminators.end())
        {
            newWord = getRandomTopString(sortChildren(lastWordMap));
            sentence += " " + newWord;
            lastWordMap = _map->GetWordMap(newWord);
        }

        cout << sentence << endl;
    }
}

void CGenerateSentence::Bruteforce()
{

}

void CGenerateSentence::GenerateFile()
{

}

// SETTERS/GETTERS
void CGenerateSentence::setRandomness(const int &rand)
{
    _randomness = rand;
}

void CGenerateSentence::setMinWords(const int &min)
{
    _minWords = min;
}

void CGenerateSentence::setMaxWords(const int &max)
{
    _maxWords = max;
}

void CGenerateSentence::setMinChars(const int &min)
{
    _minChars = min;
}

void CGenerateSentence::setMaxChars(const int &max)
{
    _maxChars = max;
}



// PRIVATE

vector<pair<CTYPE> > CGenerateSentence::sortChildren(CMap &map)
{
    vector<pair<CTYPE> > temp(map.GetMap().begin(), map.GetMap().end());
    sort(temp.begin(), temp.end(), &orderCMapByCount);
    return temp;
}


string CGenerateSentence::getRandomTopString(vector<pair<CTYPE> > sortedVector)
{
    // Bug si le vector est plus petit que le randomness
    int tempRand = sortedVector.size();
    if (tempRand > _randomness)
        tempRand = _randomness;
    return sortedVector[rand() % tempRand].first;
}

CMap& CGenerateSentence::getRandomSentenceTerminator()
{
    string terminator = _sentenceTerminators[rand() % _sentenceTerminators.size()];
    return _map->GetWordMap(terminator);
}

string CGenerateSentence::getFirstSentenceWord()
{
    // Get a random sentence terminator (. ! ?)
    // Then sort his children by most used word after it
    // Then grab a random word in the top (ex: top 10)
    // We get an often used word at the beginning of a sentence! yay

    // Because of ! and ? often used in "" or (), we make sure the first
    // letter is capital.
    string firstWord = getRandomTopString(sortChildren(getRandomSentenceTerminator()));

    while (!isupper(firstWord[0])) {
        firstWord = getRandomTopString(sortChildren(getRandomSentenceTerminator()));
    }

    return firstWord;

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

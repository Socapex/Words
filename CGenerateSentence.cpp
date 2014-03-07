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
	DEBUG_FCT
	//Get better randomness...
	srand((unsigned int)time(NULL));

    _map = &map;

    //Pretty much unused now...
    _sortedWordsByCount = sortChildren(map);

    // Create a list of line terminators, currently latin only, could be anything!
    _sentenceTerminators.push_back(".");
    _sentenceTerminators.push_back("!");
    _sentenceTerminators.push_back("?");
}

void CGenerateSentence::generate()
{
	DEBUG_FCT
    // Generate num sentences
    for (int i = 0; i < _numSentence; ++i)
    {
        // Initialise the beginning of sentence. We need the correct markov
        // number of words!
        list<CMap> sentence = {_map->GetWordMap(getFirstSentenceWord())}; //Add first word

		ATT_MARKOV_T* markov_att = ((ATT_MARKOV_T*)_map->GetWordAttribute("Markov"));
		ASSERT(markov_att != nullptr, "Markov attribute doesn't exist.");

		while ((int)sentence.size() < markov_att->GetValue())
        {
            // Get last word
            CMap newWord = sentence.back();
            // Find a commonly used word inside the tree of the first word
            newWord = newWord.GetWordMap(getRandomTopString(sortChildren(newWord)));
            sentence.push_back(newWord);
        }

        // While last character isn't terminator (. ! ?)
        while (find(_sentenceTerminators.begin(), _sentenceTerminators.end(),
                    sentence.back().GetWord().GetString()) == _sentenceTerminators.end())
        {
            sentence.push_back(getNextMarkovWord(sentence));
        }

        // TODO: Change this to give love to (, ; :) etc.
        bool first = true;
        for (auto x : sentence)
        {
            if (first)
            {
                cout << x.GetWord().GetString();
                first = false;
            }

            else
                cout << " " << x.GetWord().GetString();
        }
        cout << endl;
    }
}

void CGenerateSentence::Bruteforce()
{
	DEBUG_FCT
}

void CGenerateSentence::GenerateFile()
{
	DEBUG_FCT
}

// SETTERS/GETTERS

void CGenerateSentence::setNumSentence(const int &num)
{
	DEBUG_FCT
    _numSentence = num;
}

void CGenerateSentence::setRandomness(const int &rand)
{
	DEBUG_FCT
    _randomness = rand;
}

void CGenerateSentence::setMinWords(const int &min)
{
	DEBUG_FCT
    _minWords = min;
}

void CGenerateSentence::setMaxWords(const int &max)
{
	DEBUG_FCT
    _maxWords = max;
}

void CGenerateSentence::setMinChars(const int &min)
{
	DEBUG_FCT
    _minChars = min;
}

void CGenerateSentence::setMaxChars(const int &max)
{
	DEBUG_FCT
    _maxChars = max;
}



// PRIVATE

CMap CGenerateSentence::getNextMarkovWord(list<CMap> maps) const
{
    list<CMap> temp = maps;

	ATT_MARKOV_T* markov_att = ((ATT_MARKOV_T*)_map->GetWordAttribute("Markov"));
	
    // Remove the unused first words (we are creating a list of words
    // that is markov length).
	while ((int)temp.size() >= markov_att->GetValue())
    {
        temp.pop_front();
    }

    // Find the second word in original map, loosing the chain and starting a new.
    // P.S. We remove the first word, and take the second as first.
    CMap newWord = _map->GetWordMap(temp.front().GetWord().GetString());
    temp.pop_front();

    // Get the last inner map
    for (const auto x : temp)
    {
        // If our word isn't in the map... Probably a non-bug fixed with
        // my const WAR!!! lol
        if (newWord.GetWordMap(x.GetWord().GetString()) == notFound)
            newWord = newWord.GetWordMap(getRandomTopString(sortChildren(newWord)));
        else
            newWord = newWord.GetWordMap(x.GetWord().GetString());
    }

    // We have one more level to go. So go and find the next random word.
    newWord = newWord.GetWordMap(getRandomTopString(sortChildren(newWord)));

    // OUCH... Bobo a la tete
    return newWord;
}

vector<pair<CTYPE> > CGenerateSentence::sortChildren(CMap map) const
{
    vector<pair<CTYPE> > temp(map.GetMap().begin(), map.GetMap().end());
    sort(temp.begin(), temp.end(), &orderCMapByCount);
    return temp;
}


string CGenerateSentence::getRandomTopString(vector<pair<CTYPE> > sortedVector) const
{
    // Bugfix si le vector est plus petit que le randomness
	// Pas tant fix lol.
    int tempRand = sortedVector.size();
    if (tempRand > _randomness)
        tempRand = _randomness;

	ASSERT(tempRand > 0, "Index under zero or equal zero.");
	//ASSERT(tempRand < int(sortedVector.size() - 1), "Index is larger than vector");

    return sortedVector[rand() % tempRand].first;
}

CMap CGenerateSentence::getRandomSentenceTerminator() const
{
    string terminator = _sentenceTerminators[rand() % _sentenceTerminators.size()];
    return _map->GetWordMap(terminator);
}

string CGenerateSentence::getFirstSentenceWord() const
{
    // Get a random sentence terminator (. ! ?)
    // Then sort his children by most used word after it
    // Then grab a random word in the top (ex: top 10)
    // We get an often used word at the beginning of a sentence! yay

    // Because of ! and ? often used in "" or (), we make sure the first
    // letter is capital.
    string firstWord = getRandomTopString(sortChildren(
                                          getRandomSentenceTerminator()));

    while (!isupper(firstWord[0])) {
        firstWord = getRandomTopString(sortChildren(
                                       getRandomSentenceTerminator()));
    }

    return firstWord;

}

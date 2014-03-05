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

void CGenerateSentence::generate()
{
    // Generate num sentences
    for (int i = 0; i < _numSentence; ++i)
    {
        // Initialise the beginning of sentence. We need the correct markov
        // number of words!
        list<CMap> sentence = {_map->GetWordMap(getFirstSentenceWord())}; //Add first word

        while (sentence.size() < _map->getMarkovLength())
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

        for (auto x : sentence)
        {
            cout << x.GetWord().GetString() << " ";
        }
        cout << endl;
    }
}

void CGenerateSentence::Bruteforce()
{

}

void CGenerateSentence::GenerateFile()
{

}

// SETTERS/GETTERS

void CGenerateSentence::setNumSentence(const int &num)
{
    _numSentence = num;
}

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


CMap CGenerateSentence::getNextMarkovWord(list<CMap> maps) const
{
    list<CMap> temp = maps;
    // Remove the unused first words
    while (temp.size() >= _map->getMarkovLength())
    {
        temp.pop_front();
    }

    // Find the second word in original map, loosing the chain and starting anew.
    CMap newWord = _map->GetWordMap(temp.front().GetWord().GetString());
    temp.pop_front();

    // Get the last inner map
    for (const auto x : temp)
    {
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
    // Bug si le vector est plus petit que le randomness
    int tempRand = sortedVector.size();
    if (tempRand > _randomness)
        tempRand = _randomness;
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

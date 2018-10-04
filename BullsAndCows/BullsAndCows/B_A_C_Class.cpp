#include "stdafx.h"
#include "B_A_C_Class.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

B_A_C_Class::B_A_C_Class() { Reset(); }
int B_A_C_Class::GetCurrentTry() const { return MyCurrentTry; }
bool B_A_C_Class::IsGameWon() const{ return GameWinCndition; }
int B_A_C_Class::GetHiddenWordLength() const { return MyHiddenWord.length(); }


int B_A_C_Class::GetMaxTries() const 
{
	map <int, int> TriesDependingOnWord{ {3, 5}, {4, 7}, {5, 9}, {6, 10} };
	return TriesDependingOnWord[MyHiddenWord.length()];
}

void B_A_C_Class::Reset()
{
	GameWinCndition = false;

	MyCurrentTry = 1;
}

void B_A_C_Class::ChooseWordDifficulty(int ChosenWord)
{
	map <int, string> WordDifficulty{ {3,"ape"}, {4,"plan"}, {5,"earth"}, {6,"domain"} };
	MyHiddenWord = WordDifficulty[ChosenWord];
	return;
}

BullCowCount B_A_C_Class::SubmitGuess(string Guess)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;
	int HiddenWordLength = MyHiddenWord.length();
	for (int i = 0; i < HiddenWordLength; i++) 
	{
		for (int j = 0; j < HiddenWordLength; j++) 
		{
			if (Guess[i] == MyHiddenWord[j]) 
			{
				if (i == j) 
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == HiddenWordLength)
	{
		GameWinCndition = true;
	}
	else 
	{
		GameWinCndition = false;
	}
	return BullCowCount;
}

WordStatus B_A_C_Class::CheckGuessValidity(string Guess)
{
	if (!IsLowerCase(Guess))
	{
		return WordStatus::NotLowercase;
	}
	else if (!IsIsogram(Guess)) 
	{
		return WordStatus::NotIsogram;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return WordStatus::WrongLength;
	}
	else 
	{
		return WordStatus::OK;
	}
}

bool B_A_C_Class::IsIsogram(string Guess) const
{
	if (Guess.length() <= 1) 
	{ 
		return true; 
	}

	map <char, bool> LetterSeen;
	for (char Letter : Guess) 
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) 
		{
			return false;
		}
		else 
		{
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool B_A_C_Class::IsLowerCase(string Guess) const
{
	for (char Letter : Guess) 
	{
		if (!islower(Letter)) 
		{
			return false;	
		}
	}
	return true;
}

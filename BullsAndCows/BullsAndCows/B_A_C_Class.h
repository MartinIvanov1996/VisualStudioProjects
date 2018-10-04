#pragma once
#include <string>

struct BullCowCount 
{
	int Bulls = 0;
	int Cows = 0;
};

enum class WordStatus
{
	OK,
	NotIsogram,
	WrongLength,
	NotLowercase,
	InvalidStats
};

class B_A_C_Class
{
public:
	B_A_C_Class();
	int GetMaxTries()const;
	int GetCurrentTry()const;
	int GetHiddenWordLength() const;
	bool IsGameWon()const;

	void ChooseWordDifficulty(int);
	BullCowCount SubmitGuess(std::string);
	void Reset();
	WordStatus CheckGuessValidity(std::string);
private:

	bool IsIsogram(std::string) const;
	bool IsLowerCase(std::string) const;

	int MyCurrentTry;
	std::string MyHiddenWord;
	bool GameWinCndition;
};


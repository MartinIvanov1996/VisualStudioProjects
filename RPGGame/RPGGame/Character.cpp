#include "stdafx.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

Character::Character() { SetPrivateProperties(); }
int Character::SpellPowerBonusDamage(int Power) { return (Power / 5); }
int Character::GetMana(int inteligence) const { return (MageMana*inteligence); }

void Character::SetPrivateProperties()
{
	MaxStats = 20;
	MageMana = 20;
	return;
}

AttribtesMage Character::MageClass()
{
	AttribtesMage attributesMage;
	int RemainingStats = MaxStats;
	int StatsToInput[2];

	cout << endl;
	cout << "Lets set the strength of your character. There are 3 attributes: spellpower, intelligence and vitality." << endl;
	cout << "The more spellpowere the more damage your spells do. More intelligence means more mana, no mana to cast spells = death." << endl;
	cout << "Vitality is how much health you have." << endl;
	cout << "You have 20 points to put in all 3 attributes so choose wisely as this will affect your early game." << endl;

	do
	{
		cout << "Please type a number betwen 0 and " << RemainingStats << " to be added to your spell power:";
		cin >> StatsToInput[0];
		if (StatsToInput[0] > RemainingStats || StatsToInput[0] <= 0)
		{
			cout << "Invalid. The number cant be lower than 0 or higher than " << RemainingStats << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		attributesMage.SpellPower += StatsToInput[0];
	} while (StatsToInput[0] > RemainingStats || StatsToInput[0] <= 0);

	RemainingStats -= StatsToInput[0];

	if (RemainingStats == 0)
	{
		cout << "Attributes: Spell power = " << attributesMage.SpellPower << "  Intelligence = " << attributesMage.intelligence << "  Vitality: " << attributesMage.Vitality << endl;
		return attributesMage;
	}

	do
	{
		cout << "Please type a number betwen 0 and " << RemainingStats << " to be added to your intelligence:";
		cin >> StatsToInput[1];
		if (StatsToInput[1] > RemainingStats || StatsToInput[1] <= 0)
		{
			cout << "Invalid. The number cant be lower than 0 or higher than " << RemainingStats << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		attributesMage.intelligence += StatsToInput[1];
	} while (StatsToInput[1] > RemainingStats || StatsToInput[1] <= 0);

	RemainingStats -= StatsToInput[1];
	attributesMage.Vitality += RemainingStats;
	cout << "The remaining stats will be added to the last attribute vitality." << endl;
	cout << "Attributes: Spell power = " << attributesMage.SpellPower << "  Intelligence = " << attributesMage.intelligence << "  Vitality: " << attributesMage.Vitality << endl;
	return attributesMage;
}

bool Character::IsCharacterDead(int Health)
{
	if (Health <= 0) 
	{
		cout << "Fight Lost." << endl;
		return true;
	}
	else if (Health > 0) 
	{
		cout << "Fight Won." << endl;
		return false;
	}
}

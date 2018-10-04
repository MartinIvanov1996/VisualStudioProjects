#include "stdafx.h"
#include "ClassItemsPowers.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

//Mage Class

MageItemsAndPowers::MageItemsAndPowers() { SetItemsSpellStats(); }
int MageItemsAndPowers::AddSpellList() { return ++IncrementSpellList; }

int MageItemsAndPowers::SpellManaCost(int Spell)
{
	return (Spell * Spell);
}

void MageItemsAndPowers::SetItemsSpellStats()
{
	IncrementSpellList = 1;

	//defence spells
	IceBarier = 5;
	EnergyShield = 8;
	FrosShield = 10;

	//offence spells
	LightningBlast = 6;
	JadeBlast = 8;
	FireBall = 10;
	//elemental chain
	IceBall = 1;
	WindStrike = 2;
	WaterWave = 3;
	//most powerfull spells
	Inferno = 20;
	Implosion = 35;
	ElectricSurge = 15;

	return;
}

bool MageItemsAndPowers::CanSpellBeDodged(int SelectedSpell)
{
	if (SelectedSpell == LightningBlast || SelectedSpell == ElectricSurge)
	{
		return false;
	}
	return true;
}

int MageItemsAndPowers::MageOffenceSpells(int Response)
{
	map <int, int> ChosenSpell{ { 1, FireBall },{ 2, JadeBlast },{ 3, LightningBlast },{ 4, IceBall },{ 5, WindStrike },{ 6, WaterWave }, {7, Inferno}, {8, Implosion}, {9, ElectricSurge} };
	SpellTextWhenUsed(ChosenSpell[Response]);
	return ChosenSpell[Response];
}

int MageItemsAndPowers::MageDefenceSpells(int Response)
{
	map<int, int> ChosenSpell{ { 1, IceBarier },{ 2,EnergyShield },{ 3,FrosShield } };
	return ChosenSpell[Response];
}

void MageItemsAndPowers::GetNumberOfSpellsAvailiable(int Intelligence)
{
	const int SecondSpellList = 40;
	const int ThirdSpellList = 100;
	if (Intelligence >= SecondSpellList)
	{
		if (Intelligence >= ThirdSpellList)
		{
			AddSpellList();
		}
		AddSpellList();
	}
	return;
}

int MageItemsAndPowers::ElementalChainBonusDMG(int ChosenSpell, int PreviousSpell)
{
	int ElementBonus = 15;
	if (ChosenSpell == (PreviousSpell - NumberOfSpellsPerList) || ChosenSpell == (PreviousSpell + NumberOfSpellsPerList))
	{
		return ElementBonus;
	}
	return 0;
}

int MageItemsAndPowers::GetLowestCostSpell()
{
	int AllSpells[3]{ LightningBlast,JadeBlast,FireBall };
	int LowestCost = AllSpells[0];
	if (IncrementSpellList >= 2)
	{
		return (IceBall*IceBall);
	}
	for (int i = 0; i < 3; i++) 
	{
		if (AllSpells[i] < LowestCost) 
		{
			LowestCost = AllSpells[i];
		}
	}

	return (LowestCost*LowestCost);
}

bool MageItemsAndPowers::IsManaEnoughForLowestCostSpell(int Mana)
{
	if (Mana < GetLowestCostSpell())
	{
		cout << endl;
		cout << "You are too tired to cast any more spells, this is the end for you." << endl;
		return false;
	}
	return true;
}

int MageItemsAndPowers::SpellsToShow()
{
	return (NumberOfSpellsPerList * IncrementSpellList);
}

void MageItemsAndPowers::OffenceSpellsInfo(int SpellPower)
{
	Character character;
	if (IncrementSpellList >= 1)
	{
		cout << "You attack" << endl;
		cout << "Spell list:" << endl;
		cout << "(1)Fireball = " << (character.DamageCalculation(SpellPower) + FireBall) << " DMG - " << (FireBall*FireBall) << " mana" << endl;
		cout << "(2)Jade Blast  = " << (character.DamageCalculation(SpellPower) + JadeBlast) << " DMG - " << (JadeBlast*JadeBlast) << "mana" << endl;
		cout << "(3)Lightning Blast  = " << (character.DamageCalculation(SpellPower) + LightningBlast) << " DMG - " << (LightningBlast*LightningBlast) << " mana" << endl;
	}

	if (IncrementSpellList >= 2) 
	{
		cout << "(4)Ice Blast = " << (character.DamageCalculation(SpellPower) + IceBall) << "DMG - " << (IceBall*IceBall) << " Mana" << endl;
		cout << "(5)Wind Strike = " << (character.DamageCalculation(SpellPower) + WindStrike) << "DMG - " << (WindStrike*WindStrike) << " Mana" << endl;
		cout << "(6)Water wave = " << (character.DamageCalculation(SpellPower) + WaterWave) << "DMG - " << (WaterWave*WaterWave) << " Mana" << endl;
	}

	if (IncrementSpellList >= 3)
	{
		cout << "(7)Inferno = " << (character.DamageCalculation(SpellPower) + Inferno) << "DMG - " << (Inferno*Inferno) << " Mana" << endl;
		cout << "(8)Implosion = " << (character.DamageCalculation(SpellPower) + Implosion) << "DMG - " << (Implosion*Implosion) << " Mana" << endl;
		cout << "(9)Electric Surge = " << (character.DamageCalculation(SpellPower) + ElectricSurge) << "DMG - " << (ElectricSurge*ElectricSurge) << " Mana" << endl;
	}
	cout << "Please choose(1,2..): ";
	return;
}

void MageItemsAndPowers::DefenceSPellsInfo(int SpellPower)
{
	Character character;
	cout << "You see the enemy and prepare to cast a defensive spell on yourself." << endl;
	cout << "(1)Ice Barier = " << (character.DamageCalculation(SpellPower) + IceBarier) << " vitality - " << (IceBarier*IceBarier) << " mana" << endl;
	cout << "(2)Energy Shield = " << (character.DamageCalculation(SpellPower) + EnergyShield) << " vitality - " << (EnergyShield*EnergyShield) << " mana" << endl;
	cout << "(3)Frost shield = " << (character.DamageCalculation(SpellPower) + FrosShield) << " vitality - " << (FrosShield*FrosShield) << " mana" << endl;
	cout << "Any other number input will close the defence menu" << endl;
	cout << "Please choose(1,2,3,n): " << endl;
	return;
}

void MageItemsAndPowers::SpellTextWhenUsed(int Spell)
{
	if (Spell == FireBall) { cout << "Fire comes out of your palm and flyes towards the enemy." << endl; }
	if (Spell == JadeBlast) { cout << "A jade materializes and flyes towards the enemy with high speed." << endl; }
	if (Spell == LightningBlast) { cout << "Lightning flyes towards the enemy from your fingertips." << endl; }

	if (Spell == IceBall) { cout << "Ice flyes towards the enemy." << endl; }
	if (Spell == WindStrike) { cout << "The air focuses and rushes towards the target." << endl; }
	if (Spell == WaterWave) { cout << "Water spills over the target." << endl; }

	if (Spell == Inferno) { cout << "A circle of fire forms below the target and it explodes." << endl; }
	if (Spell == Implosion) { cout << "The very earth tries to attach itself on the target as if it's a strong magnet in an attempt to crush it." << endl; }
	if (Spell == ElectricSurge) { cout << "Electricity rushes towards the target." << endl; }
	return;
}

#pragma once
#include "Character.h"

const int ElementBonus = 15;
const int NumberOfSpellsPerList = 3;

//defence spells
const int IceBarier = 5;
const int EnergyShield = 8;
const int FrosShield = 10;

///offence spells
const int FireBall = 10;
const int JadeBlast = 8;
const int LightningBlast = 6;
//second list of spells
const int IceBall = 1;
const int WindStrike = 2;
const int WaterWave = 3;
//third list of spells
const int Inferno = 25;
const int Implosion = 35;
const int ElectricSurge = 20;

struct MageWeapons 
{
	const int WitchStaff = 15;
	const int StaffOfTheNetherworld = 30;
	const int StaffOfTheAncients = 50;
};

struct MageArmor
{
	//First tomb armor
	const int MageFirstSetSpellPower = 30;
	const int MageFirstSetVitality = 20;
	//Second tomb armor
	const int MageSecondSetSpellPower = 15;
	const int MageSecondSetVitality = 10;
	//Third tomb armor
	const int MageThirdetSpellPower = 60;
	const int MageThirdSetVitality = 50;
	const int MageThirdSetIntelligence = 40;
};

class MageItemsAndPowers 
{
public:
	int SpellsToShow();
	int AddSpellList();
	int MageOffenceSpells(int);
	int MageDefenceSpells(int);
	int SpellManaCost(int);
	int ElementalChainBonusDMG(int,int);
	void GetNumberOfSpellsAvailiable(int);
	void OffenceSpellsInfo(int);
	void DefenceSPellsInfo(int);
	void SpellTextWhenUsed(int);
	bool IsManaEnoughForLowestCostSpell(int);
	bool CanSpellBeDodged(int);

private:
	int GetLowestCostSpell();

	int IncrementSpellList = 1;

};

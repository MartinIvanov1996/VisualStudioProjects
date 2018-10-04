#pragma once
#include "Character.h"

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
	//Classes that depend on type of spells used
	friend class FightingSequenceMage;
	friend class EarthGolem;
	friend class FireElemental;
	friend class FinalGuardian;
	friend class TheKing;

	MageItemsAndPowers();
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
	const int NumberOfSpellsPerList = 3;

	int GetLowestCostSpell();
	// sets magic and item values
	void SetItemsSpellStats();

	int IncrementSpellList;

	//defence spells
	int IceBarier;
	int EnergyShield;
	int FrosShield;

	///offence spells
	int FireBall;
	int JadeBlast;
	int LightningBlast;
	//second list of spells
	int IceBall;
	int WindStrike;
	int WaterWave;
	//third list of spells
	int Inferno;
	int Implosion;
	int ElectricSurge;

};

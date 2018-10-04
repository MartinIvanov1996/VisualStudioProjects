#pragma once

class FightingSequenceMage
{
public:
	int WolfFight(int,int,int);
	int FirstPaladinFight(int,int,int);
	int SecondPaladinFight(int,int,int);
	int RematchInTheTomb(int,int,int);
	int EarthGuardian(int, int, int);
	int FireGuardian(int,int,int);
	int ThirdPaladinFight(int,int,int);
	int TheFinalGuardianFight(int,int,int);
	int FinalPaladinFight(int,int,int);
	int KingFight(int,int,int);
private:
	int PreviousSpell = 0;
	int ElementalChainBonus = 0;
	//variable is used in all fights setting itself as the remaining health 
	int EnemyHealth = 1;
};

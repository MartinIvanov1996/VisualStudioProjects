#pragma once

class Enemies
{
public:
	void SetDamage(int);
	void SetVitality(int);
protected:
	int Damage;
	int Vitality;
};

//MAGE FIGHTS

class WolfMutant : public Enemies
{
public:
	int Attacking();
	int HealthRemaining(int);

};

class FirstPaladin : public Enemies 
{
public:
	int Attacking();
	int HealthRemaining(int,int);
private:

	int Agility = 30;
};

class SecondPaladin : public Enemies 
{
public:
	int Attacking();
	int HealthRemaining(int);

private:
	int Shield = 30;
	
};

class EarthGolem : public Enemies 
{
public:
	int Attacking();
	int HealthRemaining(int, int);
private:
	int EarthShield = 100;
};

class FireElemental : public Enemies 
{
public:
	int Attacking();
	int HealthRemaining(int, int);
private:
	int FireProtection = 60;
};

class ThirdAndFourthPaladin : public Enemies
{
public:
	int Attacking();
	int HealthRemaining(int, int);
	int Skills(int);

private:
	int Agility = 100;
	//skills
	const int MultyHit = 16;
	const int DaggerTrow = 10;
	const int ShadowStrike = 13;
};

class FinalGuardian : public Enemies 
{
public:
	int Attacking();
	int HealthRemaining(int, int);
	int Skills();

private:
	int AvailableSkills = 3;

	int IceArmor = 50;
	int FireAmulet = 1;
	int EarthRing = 1;

	const int SecondSwordBonusDMG = 3;
	//skills
	const int IceWave = 10;
	const int RainOfFire = 15;
	const int EarthStrike = 13;
};

class TheKing : public Enemies 
{
public:
	int Attacking();
	int HealthRemaining(int, int);
	int Skills();


private:
	bool IsVulnerableToLightning = false;
	bool IsStuned = false;
	bool HaveOpportunityForKill = false;

	int AvailableWeapons = 3;
	int AvailableSkills = 2;
	//skills
	const int FastHit = 15;
	const int HeadKick = 18;
	//weapons
	const int Dagger = 4;
	const int Hammer = 10;
	const int Sword = 8;
};


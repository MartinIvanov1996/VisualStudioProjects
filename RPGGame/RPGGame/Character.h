#pragma once

struct AttribtesMage
{
	int SpellPower = 10;
	int intelligence = 10;
	int Vitality = 10;
};

class Character
{
public:
	friend class MageItemsAndPowers;

	int GetMana(int)const;
	
	Character();
	void SetPrivateProperties();
	AttribtesMage MageClass();
	int DamageCalculation(int);
	bool IsCharacterDead(int);

private:
	int MaxStats;
	int MageMana;
};


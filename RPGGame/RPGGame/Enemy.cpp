#include "stdafx.h"
#include "Enemy.h"
#include "Character.h" 
#include "ClassItemsPowers.h"
#include <iostream>
#include <time.h>

using namespace std;

void Enemies::SetDamage(int damage) { this->Damage = damage; }
void Enemies::SetVitality(int health) { this->Vitality = health; }

int WolfMutant::Attacking()
{
	cout << "Wolf is attacking for " << Damage << endl;
	return Damage;
}

int WolfMutant::HealthRemaining(int DamageTaken)
{
	Vitality -= DamageTaken;
	cout << "You hit wolf for " << DamageTaken << endl;
	cout << "Wolfs Remaining Health: " << Vitality << endl;
	return Vitality;
}

int FirstPaladin::Attacking()
{
	cout << "Paladin swings his sword and hits for " << Damage << endl;
	return Damage;
}

int FirstPaladin::HealthRemaining(int DamageTaken, int OpponentPower)
{
	Character character;
	MageItemsAndPowers magespells;

	int ChosenSpell = DamageTaken - character.DamageCalculation(OpponentPower);
	if (Agility > 0) 
	{
		if (magespells.CanSpellBeDodged(ChosenSpell)) 
		{
			cout << "Paladin dodged the attack, he looks more tired" << endl;
			Agility -= DamageTaken;
		}
		else if (!magespells.CanSpellBeDodged(ChosenSpell))
		{
			cout << "Paladin tries to dodge but was not quick enough." << endl;
			cout << "Lightning magic can not be dodged." << endl;
			Vitality -= DamageTaken;
		}
	}
	else if (Agility <= 0) 
	{
		cout << "Paladin could not dodge the attack he is too tired." << endl;
		Vitality -= DamageTaken;
	}
	Agility += 5;
	cout << "Paladin's Remaining Health: " << Vitality << endl;
	return Vitality;
}

int SecondPaladin::Attacking()
{
	cout << "Paladin is attacking for " << Damage << endl;
	return Damage;
}

int SecondPaladin::HealthRemaining(int DamageTaken)
{
	cout << "You hit paladin for: " << DamageTaken << endl;
	if (Shield > 0) 
	{
		Shield -= DamageTaken;
		cout << "Paladin blocks with shield. A crack appears" << endl;
		cout << "Shield durability: " << Shield << endl;
	}
	else 
	{
		cout << "The shield is broken and the paladin can no longer protect himself" << endl;
		Vitality -= DamageTaken;
	}
	cout << "Paladin's Remaining Health: " << Vitality << endl;
	return Vitality;
}

int EarthGolem::Attacking()
{
	cout << "Earth Golem is attacking for " << Damage << endl;
	return Damage;
}

int EarthGolem::HealthRemaining(int DamageTaken, int OpponentPower)
{
	Character character;
	MageItemsAndPowers magespells;

	int ChosenSpellDMG = DamageTaken - character.DamageCalculation(OpponentPower);
	cout << "You hit golem for: " << DamageTaken << endl;
	if (EarthShield > 0)
	{
		if (ChosenSpellDMG == magespells.WindStrike)
		{
			cout << "Spell ignores shield and hits golem directly." << endl;
			Vitality -= DamageTaken;
		}
		else
		{
			EarthShield -= DamageTaken;
			cout << "Golem is surounded by earth which protects him further." << endl;
			cout << "Earth Shield durability: " << EarthShield << endl;
		}
	}
	else
	{
		cout << "Golem takes the hit." << endl;
		Vitality -= DamageTaken;
	}
	cout << "Golem's Remaining Health: " << Vitality << endl;
	return Vitality;
}

int FireElemental::Attacking()
{
	cout << "Fire Elemental is attacking for " << Damage << endl;
	return Damage;
}

int FireElemental::HealthRemaining(int DamageTaken, int OpponentPower)
{
	Character character;
	MageItemsAndPowers magespells;

	int ChosenSpellDMG = DamageTaken - character.DamageCalculation(OpponentPower);
	FireProtection += 3;

	cout << "You hit elemental for: " << DamageTaken << endl;
	if (FireProtection > 0) 
	{
		if (ChosenSpellDMG == magespells.IceBall) 
		{
			cout << "The fire begins to fade. You need to put the fire out." << endl;
			FireProtection -= DamageTaken;
		}
		else if (ChosenSpellDMG == magespells.FireBall) 
		{
			cout << "For some reason you attack the fire elemental which has fire as protection with fire." << endl;
			cout << "Good job on that one." << endl;
			Vitality += DamageTaken;
		}
		else
		{
			cout << "Your magic hits the element without effect;" << endl;
		}
	}
	FireProtection += 3;
	cout << "Elemental's Fire Proteciton: " << FireProtection << endl;
	if (FireProtection <= 0)
	{
		cout << "The fire is out and a block of ice stands infront of you, but you can see light inside the ice." << endl;
		cout << "The element is regaining its strenght" << endl;
		FireProtection = 0;
		return FireProtection;
	}
	return FireProtection;
}

int ThirdAndFourthPaladin::Skills(int agility)
{
	srand(time(NULL));
	int ChosenSkill = rand() % 3;

	if (ChosenSkill == 0 && Agility >= MultyHit)
	{
		cout << "Paladin uses his superior agility to dash and hit you 4 times." << endl;
		Agility -= MultyHit;
		return MultyHit;
	}
	else if (ChosenSkill == 1 && Agility >= DaggerTrow) 
	{
		cout << "Paladin trows daggers at you with deadly precision." << endl;
		Agility -= DaggerTrow;
		return DaggerTrow;
	}
	else if (ChosenSkill == 2 && Agility >= ShadowStrike) 
	{
		cout << "Paladin merges with the shadows. He jumps on you from behind landing a heavy blow." << endl;
		Agility -= ShadowStrike;
		return ShadowStrike;
	}
	return 0;
}

int ThirdAndFourthPaladin::Attacking()
{
	int DMGFromSkill;
	DMGFromSkill = Skills(Agility);
	cout << "Damage Inflicted by paladin: " << (Damage + DMGFromSkill)<< endl;
	return (Damage + DMGFromSkill);
}

int ThirdAndFourthPaladin::HealthRemaining(int DamageTaken, int OpponentPower)
{
	Character character;
	MageItemsAndPowers magespells;

	int ChosenSpellDMG = DamageTaken - character.DamageCalculation(OpponentPower);
	if (Agility > 0)
	{
		if (magespells.CanSpellBeDodged(ChosenSpellDMG))
		{
			cout << "Paladin dodged the attack, he looks more tired" << endl;
			Agility -= DamageTaken;
		}
		else if (!magespells.CanSpellBeDodged(ChosenSpellDMG))
		{
			cout << "Paladin tries to dodge but was not quick enough." << endl;
			cout << "Lightning magic can not be dodged." << endl;
			Vitality -= DamageTaken;
		}
	}
	else if (Agility <= 0)
	{
		cout << "Paladin could not dodge the attack he is too tired." << endl;
		Vitality -= DamageTaken;
		Agility = 0;
	}
	Agility += 2;
	cout << "Paladin's Remaining Health: " << Vitality << endl;
	cout << "Paladin's agility: " << Agility << endl;
	return Vitality;
}

int FinalGuardian::Attacking()
{
	cout << "The Guardian Swings his first sword inflicting " << Damage << endl;
	cout << "His second sword inflictins " << (Damage + SecondSwordBonusDMG) << endl;
	return (Damage + Damage + SecondSwordBonusDMG);
}

int FinalGuardian::Skills()
{
	if (AvailableSkills <= 0) 
	{
		cout << "Without any of his items The Guardian can't cast adtional spells and is no longer immune to Bonus elemental chain DMG." << endl;
		AvailableSkills = 0;
		return 0;
	}
	srand(time(NULL));
	int ChosenSkill = rand() % AvailableSkills;

	if (ChosenSkill == 2 && IceArmor > 0)
	{
		cout << "The Guardian lifts his hand unleashing a wave that freezes the very air before it. Wave hits you for " << IceWave << endl;
		return IceWave;
	}
	else if (ChosenSkill == 1 && FireAmulet == 1)
	{
		cout << "The Guardians hand lifts upward to the sky. A cicrle apears above you and fire starts to rain. Fire causes " << RainOfFire << " damage" << endl;
		return RainOfFire;
	}
	else if (ChosenSkill == 0 && EarthRing == 1)
	{
		cout << "The Guardian thrusts his swords into the ground. The very earth below grabs your ankles.";
		cout << "The Guardian jumps and hits you in the face. From the impact the earth holding you breaks. Damage inflicted: " << EarthStrike << endl;
		return EarthStrike;
	}
	return 0;
}

int FinalGuardian::HealthRemaining(int DamageTaken, int OpponentPower)
{
	Character character;
	MageItemsAndPowers magespells;

	int ChosenSpellDMG = DamageTaken - character.DamageCalculation(OpponentPower);
	if (IceArmor <=0) 
	{
		if (FireAmulet > 0 && ChosenSpellDMG == magespells.WindStrike) 
		{
			cout << "The wind knocks down the guardian and the Amulet of fire falls off from him and breaks on the ground." << endl;
			AvailableSkills--;
			FireAmulet = 0;
		}
		else if (EarthRing > 0 && ChosenSpellDMG == magespells.WaterWave) 
		{
			cout << "Water makes the mud wet. The ring falls off his hand." << endl;
			AvailableSkills--;
			EarthRing = 0;
		}
		else 
		{
			if (FireAmulet > 0 && (ChosenSpellDMG == magespells.FireBall || ChosenSpellDMG == magespells.Inferno)) 
			{
				cout << "Since the amulet is on the guardian fire damage cannot harm him. Your spell does nothing." << endl;
				return Vitality;
			}
			cout << "You hit the Guardian and there is an effect, he looks angrier." << endl;
			cout << "The Guardian Takes " << DamageTaken << " DMG." << endl;
			Vitality -= DamageTaken;
		}
	}
	else if (ChosenSpellDMG == magespells.Implosion || ChosenSpellDMG == magespells.JadeBlast)
	{
		cout << "The earth tries to shatter the armor of ice" << endl;
		IceArmor -= DamageTaken;
		cout << "Armor Strength: " << IceArmor << endl;
		if (IceArmor <= 0) 
		{
			AvailableSkills--;
		}
	}
	else
	{
		cout << "Your magic hits the armor with no effect" << endl;
	}
	cout << "Guardian's Remaining Health: " << Vitality << endl;
	return Vitality;
}

int TheKing::Skills()
{
	srand(time(NULL));
	int ChosenSkill = rand() % AvailableSkills;

	if (ChosenSkill == 0)
	{
		cout << " after that he kicks you in the head." << endl;
		return HeadKick;
	}
	else
	{
		cout << "after that he punches you." << endl;
		return FastHit;
	}
	return 0;
}

int TheKing::Attacking()
{
	srand(time(NULL));
	int ChosenWeapon = rand() % AvailableWeapons;
	int ChosenSkill;
	if (ChosenWeapon == 0) 
	{
		cout << "The king swings his dagger and hits you." << endl;
		ChosenSkill = Skills();
		cout << "Damage taken: " << (Dagger + ChosenSkill) << endl;
		return (Dagger + Skills());
	}
	else if (ChosenWeapon == 1) 
	{
		cout << "The king swings his hammer and hits you." << endl;
		ChosenSkill = Skills();
		cout << "Damage taken: " << (Hammer + ChosenSkill) << endl;
		return (Hammer + ChosenSkill);
	}
	else 
	{
		cout << "The king swings his sword and hits you." << endl;
		ChosenSkill = Skills();
		cout << "Damage taken: " << (Sword + ChosenSkill) << endl;
		return (Sword + ChosenSkill);
	}
	return 0;
}

int TheKing::HealthRemaining(int DamageTaken, int OpponentPower)
{
	Character character;
	MageItemsAndPowers magespells;

	int ChosenSpellDMG = DamageTaken - character.DamageCalculation(OpponentPower);
	
	if (IsVulnerableToLightning && ChosenSpellDMG == magespells.LightningBlast || ChosenSpellDMG == magespells.ElectricSurge)
	{
		cout << "The water and lightning magic immobilise the king, even though the king can still attack, your next spell is sure to hit." << endl;
		IsStuned = true;
		return Vitality;
	}
	else if (!IsVulnerableToLightning && ChosenSpellDMG == magespells.LightningBlast || ChosenSpellDMG == magespells.ElectricSurge)
	{
		cout << "The king dodges the lightning attack. This is unexpected, immpossible even. The king really is not like the others." << endl;
		return Vitality;
	}

	if (ChosenSpellDMG == magespells.WaterWave) 
	{
		cout << "The king finds your attack funny and tells you he already had a bath today." << endl;
		IsVulnerableToLightning = true;
		return Vitality;
	}

	if (IsStuned)
	{
		if (HaveOpportunityForKill && IsStuned)
		{
			if (ChosenSpellDMG == magespells.WindStrike)
			{
				Vitality = 0;
				return Vitality;
			}
		}
		cout << "Your hit shakes the king and he regains his mobility. The battle betwen you and the soaked king continues." << endl;
		Vitality -= DamageTaken;
	}
	else if (!IsStuned)
	{
		cout << "The king dodges the attack with ease. You see his agility and it is limitless." << endl;
		cout << "You better find a way to stun him." << endl;
	}

	if (Vitality <= 1) 
	{
		cout << "The king is pushed back on the top of the hill. He starts gathering his strenght" << endl;
		HaveOpportunityForKill = true;
		Vitality = 1;
	}

	IsStuned = false;
	cout << "King's Remaining Health: " << Vitality << endl;
	return Vitality;
}

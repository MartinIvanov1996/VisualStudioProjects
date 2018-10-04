#include "stdafx.h"
#include "Story.h"
#include <iostream>
#include <string>

using namespace std;


//MAGE STORY
void MageStory::ElementalChainsExplanation()
{
	cout << "Spells can be chained together for more damage depending on the element that is used." << endl;
	cout << "If the target is affected by ice magic, Fire magic will deal additional damage to him." << endl;
	cout << "If the target is affected by water magic, Lighting magic will deal additional damage to him." << endl;
	cout << "If the target is knocked back by wind, Earth magic will deal additional damage to him." << endl;
	cout << "Reversed elements work as well first fire then ice etc." << endl;
	return;
}

void MageStory::StoryLeadingToFirstFight()
{
	system("pause");
	system("cls");
	cout << "The flames can be seen in the distance. The flames burning your village." << endl;
	cout << "The kings knights attacked your home and lit a fire before returning with laughter to the castle." << endl;
	cout << "The reason for the attack is unknown but you are going to find out, it is the only thing that is left." << endl;
	cout << "While running away in the forest you encounter a wolf, or atleast what traits are left of it." << endl;
	cout << "Vile alchemy plages the land and the forest inhabitance are infected" << endl;
	cout << "You prepare for battle." << endl;
	return;
}

int MageStory::WitchHutStory()
{
	const int WitchSpellBook = 10;
	system("pause");
	system("cls");
	cout << "You continue trough the forest after dealing with the mutated wolf. In the distance you see shimmering light." << endl;
	cout << "Folks in your village would say that a witch dwells withing the forest, she is not aggressive and has vast knowledge." << endl;
	cout << "If you want to find out why your village was attacked by the very soldiers that were suposed to protect it she could help." << endl;
	cout << "You enter her little house but she is nowhere to be found. You see a book on the table and start reading it." << endl;
	cout << "The book provides much information on drawing energy and using it more efficient. You recieven + 10 on your inteligence." << endl;
	cout << "The witch enters with herbs in her hand. You apoligize for reading the book to which she just waves her hand." << endl;
	cout << "She provides the information on why the village was attacked, it seems the king wants even more gold and though the taxes are paid" << endl;
	cout << "an attack was ordered not only on this viilage with the intension of pillaging everything." << endl;
	cout << "This can not go unpunished the king must die. To these intentions the witch smiles and offeres even further aid" << endl;
	cout << "She is no friend to the king nor does she agree to his decisions on poisoning the land for no reason other than experimenting." << endl;
	cout << "The king is out on a journey alone, he is the most powerful man in the kingdom and you must face him alone because everyone is scared of him." << endl;
	cout << "The witch gives you information on 4 of his paladins each wielding equipment or knowledge which will help you." << endl;
	cout << "You now know the location of the paladins and the end point of the journey. Your quest is about to beggin." << endl;
	cout << "Before leaving the witch wishes you luck and gives you a staff on the wall." << endl;
	cout << "You feel its power and can drane energies from it which regenarets to inflict more damage to your enemies." << endl;
	return WitchSpellBook;
}

void MageStory::FirstPaladinBattle()
{
	system("pause");
	system("cls");
	cout << "You reach the first destination , the smell is terrible, smell of death." << endl;
	cout << "There are corpses all around the paladin, you waste no time you need to fight him now when he is weakened." << endl;
	cout << "The paladin sees you , he does not look strong but he is very attletic, carrying a bastard sword and a light vest." << endl;
	cout << "He can definitly land many blows." << endl;
	return;
}

int MageStory::AfterFPaladinBattle()
{
	const int SpiritualBook = 20;
	cout << "The paladin falls and on his waist you see a book. It contains valuable information regarding spiritual enlightenment." << endl;
	cout << "Intelligence + 20. You continue on your journey" << endl;
	cout << "You continue along side the road searching for the next paladin ot kill." << endl;
	cout << "Finding him was not as difficult as you thought. Strong, high, wielding a massive shield." << endl;
	cout << "He casts a defensive spell on himself, lifts up his hammer and prepares to attack." << endl;
	return SpiritualBook;
}

bool MageStory::FirstTombPuzzle()
{
	int Response;
	const int PuzzleAnswer = 1025;
	cout << "The paladin was too strong, his last hit misses your head and hits the ground shatering it" << endl;
	cout << "You bohth fall down. You get up and start to run creating distance betwen you and the paladin." << endl;
	cout << "You take the high ground and create a small light, the paladin looks up, sees you, and continues to repair his shield" << endl;
	cout << "Escape is now inevitable and you know that if you face him you will die. The best course of action is to explore" << endl;
	cout << "and see if you can find anything to help you win againts him." << endl;
	cout << "If the previous paladin was at his full strenght the outcome would have been the same." << endl;
	cout << "What hope is there to defeat the king if you cannot even defeat the weakest paladins." << endl;
	cout << "The tomb you are in is mentioned in few myths, it holds powerfull artifacts but is filled with traps." << endl;
	cout << "You need to be carefull when exploring it. After half an hour of exploring you find a stone with a text on it." << endl;
	cout << "'In order to go forward you must place your hand on the stone for the right amount of seconds before you may pass' " << endl;
	cout << " '1,1 = 21		2,2 = 44		3,3 = 69		4,4 = 816		5,5'" << endl;
	cout << "how many seconds will you spend with your hand on the stone? : ";
	cin >> Response;
	if (Response != PuzzleAnswer)
	{
		cout << "While crossing the walls sudenly crush in less than a second. The paladin hears your scream, short as it is." << endl;
		cout << "You are dead." << endl;
		return false;
	}
	cout << "Patients rewards as you cross over to a room with a staff." << endl;
	cout << "The staff of the netherworld." << endl;
	cout << "Along with the staff you find a robe, gloves and shoes with magical runes on each." << endl;
	cout << "The moment you put them on you feel the power in the runes enhancing the power of your abilities." << endl;
	cout << "You read the runes and find interesting information, the runes state: " << endl;
	ElementalChainsExplanation();
	cout << "Unlocked passive ability: Elemental Chain Damage Bonus." << endl;
	cout << "The robe allows you to see enemies aura.(Ability to see agility unlocked)" << endl;
	cout << "You continue along the pillars looking for a way out." << endl;
	system("pause");
	system("cls");
	return true;
}

void MageStory::RematchInfrontOfTheTomb()
{
	cout << "Following the the brightest ligt you can find you find a way out." << endl;
	cout << "Right infront of the tomb the paladin awaits you. Aditional armor and a strange glow from his shield catch your attention." << endl;
	cout << "The shield is enhanced this time. The eyes of the paladin confirm that this time he wont hold back." << endl;
	cout << "You both prepare for battle." << endl;
	return;
}

int MageStory::SecondPaladinDeath()
{
	const int PaladinSpellBook = 30;
	cout << "Much harder than before you finally manage to kill the paladin and pick up the spell book on his waist." << endl;
	cout << "You read the book." << endl;
	cout << "The next paladins will be much stronger, you will need more power in order to beat them." << endl;
	cout << "In the area there are more hidden tombs, you begin searching for them." << endl;
	cout << "The energy from the equipment helps you find the nearest tomb and although its entrance is hidden you find it easily." << endl;
	cout << "While approaching the entrance the very earth begins to assemble." << endl;
	cout << "The Earth Guardian stares at you. One step closer and it will engage in combat." << endl;
	return PaladinSpellBook;
}

bool MageStory::SecondTombPuzzle()
{
	const string Answer = "rope";
	string Response = "";
	cout << "The guardian shatters from your last spell. You enter the tomb leaving broken rocks behind you." << endl;
	cout << "Much like the previous tomb you find a stone with righting on it. It says:" << endl;
	cout << "What has two ends but no beggining?" << endl;
	cout << "You carve into the stone: " << endl;
	cin >> Response;
	cout << " and continue forward." << endl;
	for (int i = 0; i < Response.length(); i++)
	{
		Response[i] = tolower(Response[i]);
	}
	if (Response != Answer)
	{
		cout << "While crossing the floor shatters and you fall on spikes." << endl;
		return false;
	}
	cout << "You enter the chamber and find leggings with runes and you put them on." << endl;
	cout << "While searching for an exit you see an extremely large fire elemental." << endl;
	cout << "It is probably guarding one of the other entrances." << endl;
	cout << "While heading towards it you are shocked to see a stone with another riddle." << endl;
	cout << "The trap didnt activate. It is incredible that the mechanism knows to not activate" << endl;
	cout << "for those who have already solved another riddle." << endl;
	cout << "It gets hotter and hotter, you stop reading the inscription and see that a fire elemental is attacking you" << endl;
	cout << "There is no time for defensive spells." << endl;
	return true;
}

void MageStory::ReachingThirdPaladin()
{
	cout << "After defeating the fire elemental you continue you way down the path." << endl;
	cout << "While searching for another tomb you find out that the hunter has become the prey." << endl;
	cout << "The paladin silently appears and shouts to get your attention." << endl;
	cout << "Much like the first paladin you fought he does not look very muscular. You know he is athleatic." << endl;
	cout << "Another interesting thing is his armor." << endl;
	cout << "The armor of the forgoten. Elemental damage is negated by this armor." << endl;
	cout << "The paladin carries a small dagger for a weapon." << endl;
	cout << "The battle will be hard since this paladin is in a better shape than the first one." << endl;
	system("pause");
	system("cls");
	return;
}

int MageStory::ThirdPaladinDeath()
{
	const int SpellBook = 40;
	cout << "The paladin falls on the ground. The fight was much harder than you thought." << endl;
	cout << "You need to hurry and find another tomb before the final paladin catches you." << endl;
	cout << "From the corpse you pick up a book and read trough it." << endl;
	cout << "In addition you find the energy orb, it increases the vitality of all who wear it." << endl;
	cout << "You continue forward. An hour passes and you start sensing strong energy near you." << endl;
	cout << "Walking towards it the sky goes grey. Instead of rain 5 lightning strikes form the guardian." << endl;
	cout << "Unlike the others this guardian was not an elemental but something more." << endl;
	cout << "A tall knight with two diferent swords wearing the ice armor granting ice magic knowledge to the wielder." << endl;
	cout << "Trough the ice you see the amulet of fire imunity which also grants fire magic knowledge hanging from his neck" << endl;
	cout << "and if that isnt enough the Guardian also caries the ring of earth granting eart magic knowledge. The ring is made of dried mud." << endl;
	cout << "The Guardian is immune to elemental chain damage as well." << endl;
	cout << "The tomb of the ancients stood before you, taking down this guardian will grant you passage" << endl;
	cout << "to the most dangerous tomb in the land." << endl;
	system("pause");
	system("cls");
	return SpellBook;
}

bool MageStory::ThirdTombPuzzle()
{
	const int CorrectAnswer = 2;
	int DoorAnswer, FirstFourSteps, SecondSevenSteps;
	cout << "The battle was exhausting. You rest for a few minutes before continuing forward." << endl;
	cout << "You enter the tomb and find 3 doors, an inscription on the floor and text above each door." << endl;
	cout << "You read what you see on the floor: One of the doors will lead you a step closer to the grand chamber. ";
	cout << "Each door points to another or itself saying which is the correct door, two of the texts are true the third one is false.\n" << endl;
	cout << "The doors read as followed: " << endl;
	cout << "(1)I will lie to you, the correct door is door number 3" << endl;
	cout << "(2)The correct door is door number 1" << endl;
	cout << "(3)The correct door is door number 2" << endl;
	cout << "Which door do you choose: ";
	cin >> DoorAnswer;
	if (DoorAnswer != CorrectAnswer) 
	{
		cout << "You chose wrong, the door and hallway collapse on you." << endl;
		return false; 
	}
	cout << "You continue and reach another room. The floor infront of has a number on each block." << endl;
	cout << "A stone tablet infront of it reads: Step on the correct tile and you will pass.";
	cout << "The first four tiles are the number which solved the riddle of the tomb containing the robe of magic." << endl;
	cout << "The last 7 tiles are the answer to the tomb containing the leggings of magic." << endl;
	cout << "Good luck traveler." << endl;
	cout << "Enter the first four steps you will take: " << endl;
	cin >> FirstFourSteps;
	if (FirstFourSteps != 1025)
	{
		cout << "One of the tiles gives in and you fall to your death." << endl;
		return false;
	}
	cout << "Enter the second seven steps you wil ltake: " << endl;
	cin >> SecondSevenSteps;
	if (SecondSevenSteps != 1815165) 
	{
		cout << "One of the tiles gives in and you fall to your death." << endl;
		return false;
	}
	cout << "You manage to solve the riddle and pass trough to the main chamber." << endl;
	cout << "In there you find a tome which you read. After finishing the tome you leave the staff of the netherworld right next to" << endl;
	cout << " The staff of the Ancients. This weapons is legendary." << endl;
	cout << "Also you put on the aditional armor you find. A mitryl vest, two armguards and a helm all containing runes on them." << endl;
	cout << "Fully equiped you leave the room and start looking for the exit. You are not suprised to find the final paladin waiting for you at the exit." << endl;
	cout << "He looks like the previous paladin but instead of a dagger he uses a hammer. His armor also looks much more durable but " << endl;
	cout << "elemental chain damage is not negated by it." << endl;
	system("pause");
	system("cls");
	return true;
}

int MageStory::FinalPaladinDeath()
{
	const int Buffs = 30;
	cout << "Falling down on his knees the paladin looks at you with hate in his eyes." << endl;
	cout << "Despite all the spells you threw at him the armor is intact. You pick up the hammer from the ground and smash the paladin's head." << endl;
	cout << "Recognizing the runes on the armor you put your hands on it and absorb the magical power from it." << endl;
	cout << "You pick up and read the tome attached to his waist." << endl;
	cout << "Now all that is left is to find the king and kill him or die trying." << endl;
	system("pause");
	system("cls");
	return Buffs;
}

void MageStory::FacingTheKing()
{
	cout << "Overlooking his empire from a hill The King patiently waits for you." << endl;
	cout << "When you reach him he does not say anything and does nothing." << endl;
	cout << "The king is wearing the strongest armor in the land. It is light and durable." << endl;
	cout << "On his back you see a hammer and a sword, on his side there is a dagger." << endl;
	cout << "He has no ancient artifacts on him no amulets no protection from magic." << endl;
	cout << "This is it, the final battle. Now is the time to exact your revenge." << endl;
	cout << "You have the oppurtunity to cast two defensive spells on yourself and to attack first." << endl;
	system("pause");
	system("cls");
	return;
}

void MageStory::Ending()
{
	cout << "The king is thrown from the hill by your last spell and falls on his neck." << endl;
	cout << "The battle is finally over. The tyrant is down. Your quest is over." << endl;
	cout << "Congratulations on finishing the Mage campaign." << endl;
	return;
}

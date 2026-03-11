#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
using namespace std;

struct OrkStats { // This is used to define what the type of stats the Ork has
	int Health;
	int Damage;
	int DamageReduction;
};

struct OrkMoves { // This is used to define what the type of options the Ork has when it's their turn
	string MeleeAttack;
	string DodgeAttack;
	string ThrowWeapon;
};

struct HumanStats { // This is used to define what the type of stats the Human has
	int Health;
	int Damage;
	int DamageReduction;
	int MagicDamage; // This is a stat unique to the human, since the Ork wouldn't be smart enough to be able to use magic attacks
};

struct HumanMoves { // This is used to define what the type of options the Human has when it's their turn
	string MeleeAttack;
	string DodgeAttack;
	string MagicRanged;
};

int main() {
	srand((unsigned)time(NULL)); // This is used as a randomiser for the damage reduction stats for both mobs
	int numberfodder = 1 + (rand() % 29); // This is just here to make sure the other randomisers actually randomise correctly and isn't anywhere else

	OrkStats orkBaseStats; // This uses the integers in OrkStats to define the value for each of them
	orkBaseStats.Health = 110;
	orkBaseStats.Damage = 40;
	orkBaseStats.DamageReduction = 0 + (rand() % 30); // This uses the srand at the top to get a random number between 0 and 30 for reducing the amount of damage dealt

	HumanStats humanBaseStats; // Like the Ork, this is used to define the values for the human's base stats
	humanBaseStats.Health = 100;
	humanBaseStats.Damage = 35;
	humanBaseStats.DamageReduction = 0 + (rand() % 25); // This does the same thing as the Ork DR, but has a lower max value since a human probably wouldn't have as good armour
	humanBaseStats.MagicDamage = 40;

	OrkMoves orkTurnOptions;
	// The option for the Ork to do a melee attack, with its damage being reduced by the random amount selected by the randomiser
	orkTurnOptions.MeleeAttack = orkBaseStats.Damage - humanBaseStats.DamageReduction;
	// The option to dodge the next attack from the human by just minusing the value of the damage/magic damage so no health is lost
	orkTurnOptions.DodgeAttack = humanBaseStats.Damage - 35 or humanBaseStats.MagicDamage - 40;
	// This is the ranged option for the Ork so that both mobs have some sort of ranged option, and uses the same formula as the melee attack
	orkTurnOptions.ThrowWeapon = orkBaseStats.Damage - humanBaseStats.DamageReduction;

	HumanMoves humanTurnOptions;
	// This is essentially the same as the Ork melee attack
	humanTurnOptions.MeleeAttack = humanBaseStats.Damage - orkBaseStats.DamageReduction;
	// This is essentially the same as the Ork dodge, but with only one damage removal formula since the Ork only has one
	humanTurnOptions.DodgeAttack = orkBaseStats.Damage - 40;
	// This is for the human's magic ranged attack, but isn't affected by the Ork's DR since a magic attack would be able to penetrate any armour
	humanTurnOptions.MagicRanged = humanBaseStats.MagicDamage;
}
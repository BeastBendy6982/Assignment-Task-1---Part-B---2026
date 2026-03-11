#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
using namespace std;

struct OrkStats {
	int Health;
	int Damage;
	int Speed;
	int DamageReduction;
};

struct OrkMoves {
	string MeleeAttack;
	string DodgeAttack;
	string ThrowWeapon;
	string Move;
};

struct HumanStats {
	int Health;
	int Damage;
	int Speed;
	int DamageReduction;
	int MagicDamage;
};

struct HumanMoves {
	string MeleeAttack;
	string DodgeAttack;
	string MagicRanged;
	string Move;
};

int main() {
	srand((unsigned)time(NULL));
	int numberfodder = 1 + (rand() % 29);

	OrkStats orkBaseStats;
	orkBaseStats.Health = 150;
	orkBaseStats.Damage = 40;
	orkBaseStats.Speed = 15;
	orkBaseStats.DamageReduction = 0 + (rand() % 30);

	HumanStats humanBaseStats;
	humanBaseStats.Health = 100;
	humanBaseStats.Damage = 35;
	humanBaseStats.Speed = 30;
	humanBaseStats.DamageReduction = 0 + (rand() % 25);
	humanBaseStats.MagicDamage = 40;

	OrkMoves orkTurnOptions;
	orkTurnOptions.MeleeAttack = orkBaseStats.Damage - humanBaseStats.DamageReduction;
	orkTurnOptions.DodgeAttack = humanBaseStats.Damage - 20 or humanBaseStats.MagicDamage - 40;
	orkTurnOptions.ThrowWeapon = orkBaseStats.Damage - humanBaseStats.DamageReduction;
	orkTurnOptions.Move = orkBaseStats.Speed;

	HumanMoves humanTurnOptions;
	humanTurnOptions.MeleeAttack = humanBaseStats.Damage - orkBaseStats.DamageReduction;
	humanTurnOptions.DodgeAttack = orkBaseStats.Damage - 40;
	humanTurnOptions.MagicRanged = humanBaseStats.MagicDamage;
	humanTurnOptions.Move = humanBaseStats.Speed;
}
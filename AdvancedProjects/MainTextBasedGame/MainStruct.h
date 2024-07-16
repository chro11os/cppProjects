#ifndef MAINSTRUCT_H
#define MAINSTRUCT_H
#include <string>
using namespace std;

struct setting
{
	char loc[2][10] = {"canyon", "forest"};
	char climate[4][30] = {"spring", "summer", "winter", "fall"};
};

struct object
{
	string tree;
	string plant;
};

struct animal
{ /// animal float = hp
	float bear;
	float deer;
};

struct weapons
{ /// weapon float = damage
	float gun = 20.0;
	float dagger = 10.0;
};

struct defense
{ /// defense float = armor
	float woodenArmor = 20.0;
	float steelArmor;
	float militaryArmor;
};

struct rule
{ /// mechanics
	/// damage
	float baseDamage = 10.0;
	float GunDamage;
	float DaggerDamage;
	bool damaged;
	bool critical;
	bool stunned;
	bool LifeSteal;
	bool missed;
};

struct MoveChoice
{
	bool attack;
	bool run;
};

#endif

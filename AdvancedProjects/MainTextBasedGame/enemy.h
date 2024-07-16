#ifndef ENEMY_H
#define ENEMY_H
using namespace std;

struct enemySkeleton
{
	float skeletonHp;
	int skeletonArrows;
};

struct enemyZombie
{
	const float zombieHP = 100.0;
	const float zombieArmor = 20.0;
};

struct enemyCreeper
{
	float boomDamage;
	float creeperHp;
};

#endif

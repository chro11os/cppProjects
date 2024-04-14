#ifndef ENEMY_H
#define ENEMY_H
using namespace std;

struct enemySkeleton {
	float skeletonHp;
	int skelArrows;
};

struct enemyZombie {
	float zombieHP;
	float zombieArmor;
};

struct enemyCreeper {
	float boomDamage;
	float creeperHp;
};


#endif
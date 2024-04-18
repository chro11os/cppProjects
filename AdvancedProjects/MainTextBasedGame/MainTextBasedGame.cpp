#include <iostream>
#include <cmath>
#include <cstring>
#include <random>
#include "MainStruct.h"
#include "player.h"
#include "enemy.h"
using namespace std;

// Game rule x Settings
char choice; // move decision

MoveChoice move;
setting set;
object obj;
animal anim;
weapons ItemDamage;
defense def;
rule rl;

// EnemyMobs
enemySkeleton skeleton;
enemyZombie zombie;
enemyCreeper creeper;

void DamageRatioGun()
{
    rl.GunDamage = ItemDamage.gun + rl.baseDamage - zombie.zombieArmor;
}

void DamageRatioDagger()
{
    rl.DaggerDamage = ItemDamage.dagger + (rl.baseDamage - zombie.zombieArmor) - 10;
}

void AttackGun()
{
    DamageRatioGun();
    cout << "Gun Damage Done: " << zombie.zombieHP - rl.GunDamage << endl;
    ;
}

void AttackDagger()
{
    DamageRatioDagger();
    cout << "Dagger Damage Done: " << zombie.zombieHP - rl.DaggerDamage << endl;
}

void Run()
{
    cout << "Successfully escaped" << endl;
}

int main()
{
    /*

    █▀▄▀█ ▄▀█ █ █▄░█
    █░▀░█ █▀█ █ █░▀█

    */
    cout << "You Encounter an enemy, What do you do? (1.Attack with a Gun. / 2.Attack with a Dagger. / 3. Ruuuunnnnn!";
    cin >> choice;

    /*i think its better to use functions instead of switch for easy switching and modularity*/
    switch (choice)
    {
    case '1':
        AttackGun();
        break;

    case '2':
        AttackDagger();
        break;

    case '3':
        Run();

    default:
        cout << "Invalid choice" << endl;
        break;
    }
}

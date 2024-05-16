﻿#include <iostream>
#include <cmath>
#include <cstring>
#include <random>
#include <vector>
#include "MainStruct.h"
#include "player.h"
#include "enemy.h"
using namespace std;

// Game rule x Settings
char choice; // move decision

// player structure
player mainPlayer;
playerInv inventory;

// EnemyMobs
enemySkeleton skeleton;
enemyZombie zombie;
enemyCreeper creeper;

// MoveSet
MoveChoice move;
setting set;
object obj;
animal anim;
weapons ItemDamage;
defense def;
rule rl;

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

/*==========================================Class Cotton Field============================*/
class Item
{
public:
    string name;
    int quantity;

    Item(string name, int quantity) : name(name), quantity(quantity) {}
};

class Inventory
{

private:
    vector<Item> items;

public:
    void addItem(string name, int quantity)
    {

    }
};

/*========================================================================================*/
int main()
{
    /*

    █▀▄▀█ ▄▀█ █ █▄░█
    █░▀░█ █▀█ █ █░▀█

    */
   while (true)
   {

   

    cout << "You Encounter an enemy, What do you do? (1.Attack with a Gun. / 2.Attack with a Dagger. / 3. Ruuuunnnnn!): ";
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
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

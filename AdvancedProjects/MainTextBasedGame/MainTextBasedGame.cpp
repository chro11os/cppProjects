#include <iostream>
#include <cmath>
#include <cstring>
#include <random>
#include "MainStruct.h"
#include "player.h"
#include "enemy.h"
using namespace std;

// Game rule x Settings
char choice; //move decision

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

void DamageRatio(){
    rl.GunDamage = ItemDamage.gun + rl.baseDamage - zombie.zombieArmor;
    rl.DaggerDamage = ItemDamage.dagger + rl.baseDamage - zombie.zombieArmor;
}

void Attack(){
    cout << "Damage Done: "<< zombie.zombieHP - ItemDamage.gun << endl;;
}
void Run(){
    cout << "Successfully escaped" << endl;
}

void weapon(){
    ItemDamage.gun;
    ItemDamage.dagger;
    char choice;
    cout << "Choose a weapon (Gun/Dagger): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Bang Bang Bang" << endl;
                
        break;
    case 2:

        break;
    
    default:
        break;
    }
}



int main() { 
/*

█▀▄▀█ ▄▀█ █ █▄░█
█░▀░█ █▀█ █ █░▀█ 

*/
    cout << "You Encounter an enemy, What do you do? (1.Attack / 2.Run): ";
    cin >> choice;

    /*i think its better to use functions instead of switch for easy switching and modularity*/
    switch (choice) {
        case '1':
            Attack();
        break;
        
        case '2':
            Run();
        break;
        
        case '3':
            weapon();

        default:
            cout << "Invalid choice" << endl;
        break;
    }
}


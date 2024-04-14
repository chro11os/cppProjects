#include <iostream>
#include <cmath>
#include <cstring>
#include "MainStruct.h"
#include "player.h"
#include "enemy.h"
using namespace std;




/*

█▀▄▀█ ▄▀█ █ █▄░█
█░▀░█ █▀█ █ █░▀█ 

*/
// Game rule x Settings
string choice; //move decision

MoveChoice move;
setting set;
object obj;
animal anim;
weapons weap;
defense def;
rule rl;

// EnemyMobs
enemySkeleton skeleton;
enemyZombie zombie;
enemyCreeper creeper;

int main() {
    
    cout << "You Encounter an enemy, What do you do? (Attack / Run) " << endl;
    cin >> choice;

    switch (choice) {
        case "Attack":
            cout << "You attacked the enemy, you did " << rl.damaged << "damage." << endl;
    }
}


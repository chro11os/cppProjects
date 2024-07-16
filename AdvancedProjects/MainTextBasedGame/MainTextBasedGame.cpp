#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <random>
#include <vector>
#include "MainStruct.h"
#include "player.h"
#include "enemy.h"

using namespace std;

// Game rule x Settings
char choice; // move decision

// player structure
user mainPlayer;

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

void DamageRatioGun() {
    rl.GunDamage = ItemDamage.gun + rl.baseDamage - zombie.zombieArmor;
}

void DamageRatioDagger() {
    rl.DaggerDamage = ItemDamage.dagger + (rl.baseDamage - zombie.zombieArmor) - 10;
}

void AttackGun() {
    DamageRatioGun();
    cout << "Gun Damage Done: " << zombie.zombieHP - rl.GunDamage << endl;
}

void AttackDagger() {
    DamageRatioDagger();
    cout << "Dagger Damage Done: " << zombie.zombieHP - rl.DaggerDamage << endl;
}

bool Run() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    int chance = dis(gen);
    if (chance <= 70) { // 70% chance to successfully escape
        cout << "Successfully escaped" << endl;
        return true; // Indicate successful escape
    } else {
        cout << "Failed to escape. The enemy attacks!" << endl;
        // Add logic for enemy attack or health reduction if needed
        return false; // Indicate failed escape
    }
}

class Item {
public:
    string name;
    int quantity;

    Item(string name, int quantity) : name(name), quantity(quantity) {}
};


/*----------------------------------class cotton field-----------------------------------------*/
class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const string& name, int quantity) {
        bool found = false;
        for (auto& item : items) {
            if (item.name == name) {
                item.quantity += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            items.push_back(Item(name, quantity));
        }
    }

    void viewInventory() const {
        for (const auto& item : items) {
            cout << item.name << ": " << item.quantity << endl;
        }
    }
};
/*---------------------------------------------Do not Enter!------------------------------------*/


int main() {
    Inventory myInventory;
    myInventory.addItem(string("arrows"), 32);
    myInventory.addItem(string("water"), 64);
    myInventory.addItem(string("TestWeapon"), 1);
    myInventory.addItem(string("Card of Death"), 3);
    myInventory.addItem(string("Nami"), 32);

    bool escaped = false;

    while (true) {
        cout << "You encounter an enemy, What do you do? (1.Attack with a Gun. / 2.Attack with a Dagger. / 3.Inventory /4. Run!): ";
        cin >> choice;

        switch (choice) {
        case '1':
            AttackGun();
            break;
        case '2':
            AttackDagger();
            break;
        case '3':
            myInventory.viewInventory();
            break;
        case '4':
            escaped = Run();
            if (escaped) {
                cout << "Game Over. You have escaped successfully!" << endl;
                return 0;
            }
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

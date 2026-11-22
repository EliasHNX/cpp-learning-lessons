#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;

class Character {
    private:
    string name;
    int health;
    int maxHealth;

    public:
    Character(string n, int h) : name(n), health(h), maxHealth(h) {
        cout << name << " created\n";
    }

    ~Character() {
        cout << name << " destroyed\n";
    }

    string getName() const {return name;}
    int getHealth() const {return health;}

    void takeDamage(int amount) {
        if (amount <= 0) {
            return;
        }
        else if (health == 0) {
            return;
        }
        else if (amount >= health) {
            health = 0;
        }
         else {
            health -= amount;
        }
    }

    void heal(int amount) {
        if (amount <=0) {
            return;
        }
        else if (health + amount >= maxHealth) {
            health = maxHealth;
        }
        else {
            health += amount;
        }
    }

    void attack(Character& target, int amount) {
        target.takeDamage(amount);
    }
    
};

void showHealth(const Character& player) {
        cout << player.getName() << " health: " << player.getHealth() << endl;
    }

class Gun {
    private:
    int ammo = 3;
    int capacity = 8;
    int reserveAmmo = 16;

    public:
    void shoot(Character& target) {
        if (ammo <= 0) {
            cout << "no ammo\n";
            return;
        }
        else if (target.getHealth() == 0) {
            cout << "target is already defeated" << endl;
            return;
        }
        else {
            ammo--;
            target.takeDamage(30);
            cout << "Ammo left: " << ammo << '\n';
        }
    }

    void reload() {
        int needed = capacity - ammo;
        int toLoad = std::min(needed, reserveAmmo);
        ammo += toLoad;
        reserveAmmo -= toLoad;
        cout << "Loaded: " << ammo << ", in reserve: " << reserveAmmo << '\n';
    }
};

int main() {

    auto hero = std::make_unique<Character>("Alex", 100);
    Character enemy("Goblin", 40);

    Gun gun;
    for (int i = 0; i < 4; i++) {
        gun.shoot(enemy);
    }
    gun.reload();
    gun.shoot(enemy);

    cout << "Goblin health: " << enemy.getHealth() << '\n';

    cout << enemy.getName() << " has " << enemy.getHealth() << " health" << endl;
    hero->attack(enemy, 10);
    cout << enemy.getName() << " has " << enemy.getHealth() << " health" << endl;
    cout << hero->getName() << " has " << hero->getHealth() << " health" << endl;
    hero->takeDamage(60);
    cout << hero->getName() << " has " << hero->getHealth() << " health" << endl;
    hero->heal(70);
    cout << hero->getName() << " has " << hero->getHealth() << " health" << endl;

    auto owner = std::move(hero);
    owner->takeDamage(20);
    cout << owner->getName() << " has " << owner->getHealth() << " health" << endl;

    enemy.attack(*owner, 10);
    showHealth(*owner);

    owner.reset();
    cout << "After reset\n";

    return 0;
}


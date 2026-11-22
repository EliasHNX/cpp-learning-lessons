#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

enum class GunAction {
    Shoot, 
    Reload, 
    Inspect

};

int main() {

    GunAction action;

    int ammo = 3;
    int reserveAmmo = 6;
    int capacity = 6;
    int choice = 0;

    while (true) {

        cout << "Options:\n 0. quit\n 1. shoot\n 2. reload\n 3. inspect" << '\n';
        cin >> choice;

        if (cin.fail()) {
             if (cin.eof()) {
                break;
            }
            cout << "Please enter a number." << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            action = GunAction::Shoot;
        }
        else if (choice == 2) {
            action = GunAction::Reload;
        }
        else if (choice == 3){
            action = GunAction::Inspect;
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "invalid choice." << '\n';
            continue;
        }

        if (action == GunAction::Reload) {
            cout << "reloading..." << '\n';
            if (ammo == capacity) {
                cout << "no need to reload" << '\n';
            }

            else {
                int needed = capacity - ammo;
                int toLoad = min(needed, reserveAmmo);
                ammo += toLoad;
                reserveAmmo -= toLoad;
                cout << "ammo: " << ammo << ", reserve ammo: " << reserveAmmo << '\n' << '\n';
            }
        }
        if (action == GunAction::Shoot) {
            if (ammo > 0) {
                ammo --;
                cout << "bam!" << " remaining ammo: " << ammo << ", " << reserveAmmo << '\n' << '\n';
            }
            else {
            cout << "no ammo" << '\n';
            }
        }

        if (action == GunAction::Inspect) {
            cout << "ammo: " << ammo << ", reserveAmmo: " << reserveAmmo << ", capactiy: " << capacity << '\n' << '\n';
        }
    }
    return 0;
}
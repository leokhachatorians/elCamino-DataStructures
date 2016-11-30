#include <iostream>
#include <string>
#include "Pet.h"

using namespace std;

void reportStatus(const Pet *p) {
    cout << p->name() << " has health level " << p->health();
    if (!p->alive()) {
        cout << ", so has died";
    }
    cout << endl;
}

void careFor(Pet *p, int d) {
    if (!p->alive()) {
        cout << p->name() << " is still dead" << endl;
        return;
    }

    if (d % 3 == 0) {
        cout << "You forgot to feed " << p->name() << endl;
    }
    else {
        p->eat(1);
        cout << "You fed " << p->name() << endl;
    }
    p->play();
    reportStatus(p);
}

int main () {
    Pet *myPets[2];
    myPets[0] = new Pet("Fluffy", 2);
    myPets[1] = new Pet("Fluffy", 4);
    for (int day = 1; day <= 9; day++) {
        cout << "======= Day " << day << endl;
        for(int k = 0; k < 2; k++) {
            careFor(myPets[k], day);
        }
    }
    cout << "=======" << endl;
    for (int k = 0; k < 2; k++) {
        if (myPets[k]->alive()) {
            cout << "Animal Control has come to rescue" 
                << myPets[k]->name() << endl;
        }
        delete myPets[k];
    }
}


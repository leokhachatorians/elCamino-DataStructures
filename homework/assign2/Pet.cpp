#include <string>
#include "Pet.h"

using namespace std;

Pet::Pet(string nm, int initialHealth) {
    m_name = nm;
    m_health = initialHealth;
}

void Pet::eat(int amt) {
    m_health += amt;
}

void Pet::play() {
    m_health -= 1;
}

string Pet::name() const {
    return m_name;
}

int Pet::health() const {
    return m_health;
}

bool Pet::alive() const {
    if (m_health >= 1) {
        return true;
    }
    return false;
}

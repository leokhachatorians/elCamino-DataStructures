#include <string>

using namespace std;

class Pet {
    private:
        string m_name;
        int m_health;
    public:
        Pet(string nm, int initialHealth);
        void eat(int amt);
        void play();
        string name() const;
        int health() const;
        bool alive() const;
};


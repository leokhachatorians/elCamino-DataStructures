#include <iostream>
using namespace std;

int main() {
    const int MAXCHARS = 81;
    char message[MAXCHARS];

    cout << "Enter a string: " << endl;

    cin.getline(message, MAXCHARS, '\n');

    cout << message << endl;

    cin.ignore();
}

#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Input character: ";
    cin >> ch;

    if (isalpha(ch)) {
        cout << ch << " is an alphabetic character." << endl;
    }

    if (isdigit(ch)) {
        cout << ch << " is a digit." << endl;
    }

    if (islower(ch)) {
        cout << ch << " is a lowercase character." << endl;
    }
    
    if (isupper(ch)) {
        cout << ch << " is a uppercase character." << endl;
    }
}

#include <iostream>
using namespace std;

int main() {
    int *numaddr;
    int miles, dist;

    dist = 58;
    miles = 22;

    numaddr = &miles;
    cout << numaddr << endl;
    cout << *numaddr << endl;

    numaddr = &dist;
    cout << numaddr << endl;
    cout << *numaddr << endl;

    *numaddr += 1;
    cout << *numaddr << endl;

    return 0;
}

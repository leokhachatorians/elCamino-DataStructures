#include <iostream>
using namespace std;

int main() {
    int arr[3] = {5, 10, 15};
    int *ptr = arr;

    *ptr = 10;
    *(ptr + 1) = 20;
    *(ptr + 2) = 30;
    ptr = &arr[2];

    while (ptr >= arr) {
        cout << " " << *ptr--;
    }
    cout << endl;
}

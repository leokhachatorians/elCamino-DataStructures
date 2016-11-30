#include <iostream>
using namespace std;

void f();
int* compute_squares(int &);

int main() {
    int m;
    int *ptr = compute_squares(m);
    f();
    for (int i=0; i<m; i++) {
        cout << ptr[i] << "";
    }
}

void f() {
    int junk[100];
    for (int k=0; k < 100; k++) {
        junk[k] = 1234000000 + k;
    }
}

int* compute_squares(int &n) { // returns an int pointer
    int arr[10];
    n = 10;
    for (int k = 0; k < n; k++) {
        arr[k] = (k+1) * (k+1);
    }
    return arr;
}

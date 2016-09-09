#include <iostream>
using namespace std;

void swap(double *, double *);

int main() {
    double num1 = 20.5, num2 = 19.4;
    cout << num1 << endl;
    cout << num2 << endl;

    swap(&num1, &num2);

    cout << num1 << endl;
    cout << num2 << endl;


    return 0;
}

void swap(double *num1, double *num2) {
    double temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

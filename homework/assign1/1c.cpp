#include <iostream>
#include <cmath>

using namespace std;

void hypotenuse(double, double, double *);

int main() {
    double p;
    double *p_ptr = &p;
    hypotenuse(1.5, 2.0, p_ptr);
    cout << "The hypotenuse is " << p << endl;
    return 0;
}

void hypotenuse(double leg1, double leg2, double *result_ptr) {
    *result_ptr = sqrt(leg1*leg1 + leg2*leg2);
}


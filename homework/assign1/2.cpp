#include <iostream>
using namespace std;

void iter(string[]);

int main() {
    string *fp;

    string fish[5] = {"1", "2", "3", "4", "5"};

    fp = &fish[4];

    *fp = "yellowtail";
    iter(fish);

    *(fish + 3) = "mackeral"; 
    //fp = fp - 3;
    fp = &fish[1];

    iter(fish);

    //fp = &fish[0];
    fp[1] = "cod";
    fp[0] = "eel";
    iter(fish);

    bool d = *fp == fish[0] ? true : false;
    bool b = *fp == *(fp + 1) ? true : false;

    cout << d << false << true << endl;
    cout << b << false << true << endl;

    return 0;
}

void iter(string a[]) {
    for (int i=0; i<5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

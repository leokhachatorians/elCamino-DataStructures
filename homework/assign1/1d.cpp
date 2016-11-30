#include <iostream>
using namespace std;

bool match(const char *, const char *);
bool match2(const char[], const char[]);

int main() {
    char a[10] = "pointy";
    char b[10] = "pointy";

    if (match2(a, b)) {
        cout << "They're the same!" << endl;
    }
}

bool match(const char *s1, const char *s2) {
    while (*s1 != 0) {
        if (*s2 == 0) {
            return false;
        }
        if (*s1 != *s2) {
            return false;
        }
       // if (*s2 > *s1) {
       //     return false;
       // }
       // if (*s1 > *s2) {
       //     return false;
       // }
        *s1++;
        *s2++;
    }
    if (*s2 != 0) {
        return false;
    }
    return true;
}

bool match2(const char s1[], const char s2[]) {
    cout << s1 << endl;
    cout << *s1 << endl;
    while (*s1 != 0 && *s2 != 0) {
        if (*s1 != *s2) {
            return false;
        }
        *s1++;
        *s2++;
    }
    return *s1 == *s2;
}

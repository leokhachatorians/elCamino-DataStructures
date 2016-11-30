#include <iostream>
#include <cstring>

using namespace std;

void delete_g(char *);

int main() {

    char msg[100] = "I recall the glass gate next to Gus in Lagos, near the gold bridge.";
    delete_g(msg);
    cout << msg << endl;
    return 0;
}

void delete_g(char *src) {
    char *temp = src;
    while (*src != 0) {
        if ( *src != 'g' && *src != 'G') {
            *temp = *src;
            *temp++;
        }
        *src++;
    }
    *temp = '\0';
}

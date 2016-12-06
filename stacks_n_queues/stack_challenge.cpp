#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> istack;

    istack.push(6);
    for (int i=0; i < 2; i++) {
        int n = istack.top();
        istack.pop();
        istack.push(i);
        istack.push(n*2);
        cout << "n: " << n << endl;
        cout << "i: " << i << endl;
        cout << "n*2: " << n*2 << endl;
    }
}

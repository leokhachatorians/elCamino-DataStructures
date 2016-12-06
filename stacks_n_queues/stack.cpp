#include <iostream>
using namespace std;

const int SIZE = 100;

class Stack {
    public:
        Stack() { // constructor
            m_top = 0;
        };

        void push(int val) {
            if (m_top >= SIZE) { // check if overflow
                return;
            }
            m_stack[m_top] = val;
            m_top += 1;
        };

        int pop() {
            if (m_top == 0) { // check if underflow
                return -1;
            }
            m_top -= 1;
            return m_stack[m_top];
        };
        bool is_empty(void);
        int peek_top();
    private:
        int m_stack[SIZE];
        int m_top;
};

int main(void) {
    Stack is;
    int a;

    is.push(5);
    is.push(10);
    a = is.pop();
    cout << a << endl;
    is.push(7);
    return 0;
}

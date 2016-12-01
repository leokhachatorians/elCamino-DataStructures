#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool check_if_empty(stack<char> &);
bool check_if_in_string_or_block_comment(stack<char> &);
void push_to_stack_flow(stack<char> &, char);

int main() {
    char c;
    vector<char> v;
    stack<char> char_stack;
    stack<char> balance_stack;
    stack<int> line_stack;
    //int newline_count = 1;
    
    // open file and populate vector
    ifstream file("testing.txt");
    while (file.get(c)) {
        v.push_back(c);
    }
    file.close();

    for (vector<char>::iterator it = v.begin(); it != v.end(); ++it) {
        if (*it == '(') { push_to_stack_flow(balance_stack, *it); }
        else if (*it == '[') { push_to_stack_flow(balance_stack, *it); }
        else if (*it == '{') { push_to_stack_flow(balance_stack, *it); }
        else if (*it == '"') { 
            if (balance_stack.size() > 0 && *it == balance_stack.top()) {
                balance_stack.pop();
            }
            else {
                push_to_stack_flow(balance_stack, *it);
            }
        }
        else if (*it == '\'') {
            if (balance_stack.size() > 0 && *it == balance_stack.top()) {
                balance_stack.pop();
            }
            else {
                push_to_stack_flow(balance_stack, *it);
            }
        }
        else if (*it == '/') { 
            it++;
            if (*it == '*') { push_to_stack_flow(balance_stack, 'B'); }
            it--;
        }

        else if (*it == ')') {
            if (balance_stack.top() != '(') {
                cout << "error unbalanced ()" << endl;
            }
            else
                balance_stack.pop();
        }
        else if (*it == '}') {
            if (balance_stack.top() != '{') {
                cout << balance_stack.top() << endl;
                cout << "error unbalanced {}" << endl;
            }
            else
                balance_stack.pop();
        }
        else if (*it == ']') {
            if (balance_stack.top() != '[') {
                cout << balance_stack.top() << endl;
                cout << "error unbalanced []" << endl;
            }
            else
                balance_stack.pop();
        }
        else if (*it == '"') {
            if (balance_stack.top() != '"') {
                cout << "error unbalanced \"" << endl;
            }
            else
                balance_stack.pop();
        }
        else if (*it == '\'') {
            if (balance_stack.top() != '\'') {
                cout << "error unbalanced ''" << endl;
            }
            else
                balance_stack.pop();
        }
        else if (*it == '*') {
            it++;
            if (*it == '/') {
                if (balance_stack.top() != 'B') {
                    cout << "error unbalanced /* */" << endl;
                }
                balance_stack.pop();
            }
            it--;
        }
    }

    cout << balance_stack.size() << endl;

    while (!balance_stack.empty()) {
        cout << balance_stack.top() << endl;
        balance_stack.pop();
    }

    cout << endl;
    return 0;
}


bool check_if_empty(stack<char> &stack) {
    if (stack.size() < 1) {
        return true;
    }
    return false;
}

bool check_if_in_string_or_block_comment(stack<char> &stack) {
    if (stack.top() == '"' || stack.top() == 'B' || stack.top() == '\'') {
        return true;
    }
    return false;
}

void push_to_stack_flow(stack<char> &stack, char c) {
    if (check_if_empty(stack)) {
        stack.push(c);
        cout << "EMPTY STACK PUSHING: " << c << "\n" << endl;
    }
    else {
        cout << "CURRENT TOP OF STACK: " << stack.top() << endl;
        if (!check_if_in_string_or_block_comment(stack)) {
            stack.push(c);
            cout << "PUSHED: " << c << endl << endl;
        }
        else {
            cout << "Was in a string" << endl;
        }
    }
}

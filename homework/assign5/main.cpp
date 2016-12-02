#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool check_if_empty(stack<char> &);
bool check_if_in_string_or_block_comment(stack<char> &);
void push_to_stack_flow(stack<char> &, char);
void pop_flow_parens(stack<char> &, char);
void handle_quotes(stack<char> &, char);

int main() {
    char c;
    vector<char> v;
    stack<char> char_stack;
    stack<char> balance_stack;
    stack<int> line_stack;
    
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
        else if (*it == ']' || *it == '}' || *it == ')') {
            pop_flow_parens(balance_stack, *it);
        }
        else if (*it == '"' || *it == '\'') {
            handle_quotes(balance_stack, *it);
        }
        else if (*it == '/') { 
            it++;
            if (*it == '*') { push_to_stack_flow(balance_stack, 'B'); }
            it--;
        }
        else if (*it == '*') {
            it++;
            if (*it == '/') {
                if (balance_stack.size() < 1) {
                    cout << "Error: Stack is empty." << endl;
                }
                else if (balance_stack.top() != 'B') {
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

void push_to_stack_flow(stack<char> &stack, char c) {
    if (check_if_empty(stack)) {
        stack.push(c);
    }
    else {
        if (!check_if_in_string_or_block_comment(stack)) {
            stack.push(c);
        }
    }
}

void pop_flow_parens(stack<char> &stack, char c) {
    char r;
    if (c == ']') {
        r = '[';
    }
    else if (c == ')') {
        r = '(';
    }
    else if (c == '}') {
        r = '{';
    }

    if (check_if_empty(stack)) {
        cout << "Error: Stack is empty" << endl;
    }
    else if (
        stack.top() != r &&
            (stack.top() != '"'  ||
             stack.top() != '\'' ||
             stack.top() != 'B')) {
                cout << "Was in string/comment" << endl;
    }
    else {
        stack.pop();
    }
}

void handle_quotes(stack<char> &stack, char c) {
    if (stack.size() > 0 && c == stack.top()) {
        stack.pop();
    }
    else {
        push_to_stack_flow(stack, c);
    }
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

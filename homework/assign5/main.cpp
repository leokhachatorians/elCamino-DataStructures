#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct Data {
    char value;
    int line_num;
};

bool check_if_empty(stack<Data> &);
bool check_if_in_string_or_block_comment(stack<Data> &);
void push_to_stack_flow(stack<Data> &, Data);
void pop_flow_parens(stack<Data> &, Data);
void handle_quotes(stack<Data> &, Data);
void handle_block_comments(stack<Data> &, vector<Data>::iterator);

int main() {
    int line_num = 1;
    string line;
    vector<Data> v;
    stack<Data> balance_stack;
    
    // open file and populate vector
    ifstream file("testing.txt");
    Data data;
    while (getline(file, line)) {
        for (unsigned long i = 0; i < line.length(); i++) {
            data.value = line[i];
            data.line_num = line_num;
            v.push_back(data);
        }
        line_num++;
    }

    line_num = 1;
    file.clear();
    file.seekg(0);
    while(getline(file, line)) {
        cout << setw(3) << left << line_num++ << line << endl;
    }
    file.close();

    for (vector<Data>::iterator it = v.begin(); it != v.end(); ++it) {
        if (it->value == '(' || it->value == '{' || it->value == '[') {
            push_to_stack_flow(balance_stack, *it);
        }
        else if (it->value == ')' || it->value == '}' || it->value == ']') {
            pop_flow_parens(balance_stack, *it);
        }
        else if (it->value == '"' || it->value == '\'') {
            handle_quotes(balance_stack, *it);
        }
        else if (it->value == '/' || it->value == '*') {
            handle_block_comments(balance_stack, it);
        }
    }

    cout << balance_stack.size() << endl;

    while (!balance_stack.empty()) {
        cout << balance_stack.top().value << endl;
        balance_stack.pop();
    }

    cout << endl;
    return 0;
}

void push_to_stack_flow(stack<Data> &stack, Data d) {
    if (check_if_empty(stack)) {
        stack.push(d);
    }
    else {
        if (!check_if_in_string_or_block_comment(stack)) {
            stack.push(d);
        }
    }
}

void pop_flow_parens(stack<Data> &stack, Data d) {
    char r;
    if (d.value == ']') {
        r = '[';
    }
    else if (d.value == ')') {
        r = '(';
    }
    else if (d.value == '}') {
        r = '{';
    }

    if (check_if_empty(stack)) {
        cout << "Unbalanced: " << r << d.value << " on line " << d.line_num << endl;
    }
    else if (stack.top().value == r && (!check_if_in_string_or_block_comment(stack))) {
        stack.pop();
    }
    else if (stack.top().value != r && (!check_if_in_string_or_block_comment(stack))) {
        cout << "Error: unbalanced 2" << stack.top().value << " on line " << stack.top().line_num << endl;
        cout << "Error: unbalanced 2" << d.value << " on line " << d.line_num << endl;
    }
}

void handle_quotes(stack<Data> &stack, Data d) {
    if (stack.size() > 0 && d.value == stack.top().value) {
        stack.pop();
    }
    else {
        push_to_stack_flow(stack, d);
    }
}

void handle_block_comments(stack<Data> &stack, vector<Data>::iterator it) {
    Data placeholder;
    placeholder.value = 'B';
    if (it->value == '/') {
        it++;
        if (it->value == '*') {
            placeholder.line_num = it->line_num;
            push_to_stack_flow(stack, placeholder);
        }
        it--;
    }
    else if (it->value == '*') {
        it++;
        if (it->value == '/') {
            if (stack.size() < 1) {
                cout << "Error: Stack is empty." << endl;
            }
            else if (stack.top().value != placeholder.value) {
                cout << "Error: unbalanced /* */ on line "<< stack.top().line_num << endl;
            }
            else {
                stack.pop();
            }
        }
        it--;
    }
}

bool check_if_empty(stack<Data> &stack) {
    if (stack.size() < 1) {
        return true;
    }
    return false;
}

bool check_if_in_string_or_block_comment(stack<Data> &stack) {
    if (stack.top().value == '"' || stack.top().value == 'B' || stack.top().value == '\'') {
        return true;
    }
    return false;
}

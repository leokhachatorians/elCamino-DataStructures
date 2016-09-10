#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input;
    fstream file;

    file.open("num_file.txt", ios::in);

    if (file) {
        getline(file, input);
        while (file) {
            cout << input << endl;
            getline(file, input);
        }
        file.close();
    }
    else {
        cout << "Cannot open file" << endl;
    }
    return 0;
}

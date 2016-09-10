#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

bool open_file_in(fstream &, string);
void show_contents(fstream &);

int main() {
    fstream data_file;

    if (open_file_in(data_file, "num_file.txt")) {
        cout << "File opened successfully" << endl;
        cout << "Reading data..." << endl;
        show_contents(data_file);
        data_file.close();
        cout << endl << "Finished" << endl;
    }
    else {
        cout << "Error opening the file!" << endl;
    }
    
    return 0;
}

bool open_file_in(fstream &file, string name) {
    file.open(name.c_str(), ios::in);
    if (file.fail()) {
        return false;
    }
    return true;
}

void show_contents(fstream &file) {
    string line;

    while (file >> line) {
        cout << line << endl;
    }
}

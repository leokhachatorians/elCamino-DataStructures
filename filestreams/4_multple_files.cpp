#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string file_name;
    char ch;
    ifstream in_file;
    ofstream outfile("out.txt");

    cout << "Enter a file name: ";
    cin >> file_name;

    in_file.open(file_name.c_str());

    if (in_file) {
        in_file.get(ch);

        while (in_file) {
            outfile.put(toupper(ch));
            in_file.get(ch);
        }
        in_file.close();
        outfile.close();
        cout << "conversion done" << endl;
    }
    else {
        cout << "couldnt open file <" << file_name << ">" << endl;
    }
    return 0;
}

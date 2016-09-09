#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream data_file;
    double num = 17.232345;

    data_file.open("num_file.txt", ios::out);

    data_file << fixed;
    data_file << num << endl;

    data_file << setprecision(4);
    data_file << num << endl;

    data_file << setprecision(3);
    data_file << num << endl;

    data_file << setprecision(2);
    data_file << num << endl;

    data_file << setprecision(1);
    data_file << num << endl;

    cout << "Done." << endl;

    data_file.close();
    return 0;
}

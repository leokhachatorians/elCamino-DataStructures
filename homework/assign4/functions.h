#pragma once
#include <fstream>
using namespace std;

void gather_words(ifstream *, string *, string *, int &, string);
void sorty(string &, int, int, int);
void sorting_loop(int, int, string &);
void displayer(int, int, string, string *, string *, bool);
void run();
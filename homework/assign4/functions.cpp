#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 25143;

void run() {
    string word;
    int count = 0;
    cout << "Please enter a string for an anagram search (!exit to quit): ";
    getline(cin, word);
    if (word == "!exit") {
        return;
    }
    else {
        sorting_loop(0, word.length(), word);
        string sorted_words[MAX];
        string not_sorted_words[MAX];
        ifstream file("words.txt");
        gather_words(&file, sorted_words, not_sorted_words, count, word);
        displayer(0, count, word, sorted_words, not_sorted_words, false);
        cout << endl;
        run();
    }
}

void sorting_loop(int i, int max, string &word) {
    if (i >= max) {
        return;
    }
    sorty(word, i, 0, max);
    sorting_loop(i+1, max, word);
}

void sorty(string &word, int index, int iter, int max) {
    if (iter >= max) {
        return;
    }
    if (tolower(word[index]) < tolower(word[iter])) {
        char temp = tolower(word[iter]);
        word[iter] = tolower(word[index]);
        word[index] = temp;
        sorty(word, index, iter+1, max);
    }
    else {
        sorty(word, index, iter+1, max);
    }
}

void gather_words(ifstream *file, string *arr, string *arr2, int &count, string user_word) {
    if (file->eof()) {
        return;
    }
    else {
        string line, line2;
        *file >> line;
        line2 = line;
        if (line.length() == user_word.length()) {
            *(arr2 + count) = line2;
            sorting_loop(0, line.length(), line);
            *(arr + count++) = line;
        }
        gather_words(file, arr, arr2, count, user_word);
    }
}

void displayer(int i, int max, string word, string *arr1, string *arr2, bool found) {
    if (i >= max) {
        if (!found) {
            cout << "No anagrams found for <" << word << ">" << endl;
        }
        return;
    }
    if (word == arr1[i]) {
        cout << "Matching word " << arr2[i] << endl;
        found = true;
    }
    displayer(i+1, max, word, arr1, arr2, found);
}
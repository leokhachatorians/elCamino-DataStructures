// Leo Khachatorians
// CS 2, Section #149
// Assignment 1, Problemn 6
//
// Takes in user input of how many students were surveyed,
// dynamically allocates array of size n, and loops 
// through n times to gather inputted data. When completed,
// determines the mode, mean, and median and displays 
// results to end user.


#include <iostream>
using namespace std;

void get_movie_amount(int *, int);
double get_average(int *, int);
double get_median(int *, int);
int get_mode(int *, int);
void quick_sort(int *, int, int);

int main() {
    int surveyed;
    double average, median, mode;

    cout << "How many students did you survey?: ";
    cin >> surveyed;
    int *students = new int[surveyed];
    get_movie_amount(students, surveyed);
    average = get_average(students, surveyed);

    quick_sort(*&students, 0, surveyed);

    cout << "Average: " << average << endl;

    median = get_median(students, surveyed);
    cout << "Median: " << median << endl;

    mode = get_mode(students, surveyed);
    cout << "Mode: " << mode << endl;

    delete [] students;

    return 0;
}

void get_movie_amount(int *students, int surveyed) {
    int movie_count;

    for (int i = 0; i < surveyed; i++) {
        cout << "Movies watched: ";
        cin >> movie_count;
        if (movie_count < 0) {
            cout << "Value must be positive" << endl;
            i--;
        }
        else {
            *students++ = movie_count;
        }
    }
}

double get_average(int *students, int surveyed) {
    double total = 0;
    int count = 0;
    while (count != surveyed) {
        count++;
        total += *students++;
    }
    return total / surveyed;
}

void quick_sort(int *students, int left, int right) {
    int temp;
    int i = left;
    int j = right;
    int pivot = students[(left + right) / 2];

    while ( i <= j) {
        while (students[i] < pivot) {
            i++;
        }
        while (students[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = students[i];
            students[i] = students[j];
            students[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quick_sort(students, left, j);
    }
    if (i < right) {
        quick_sort(students, i, right);
    }
}

double get_median(int *students, int surveyed) {
    if (surveyed % 2 == 0) {
        double first = students[(surveyed / 2) - 1];
        double second = students[(surveyed / 2)];
        return (first + second) / 2;
    }
    return (double) students[(surveyed / 2) + 1];
}

int get_mode(int *students, int surveyed) {
    int count = 1;
    int highest = 0;
    int mode = 0;

    for (int i = 0; i < surveyed; i++) {
        if (i == 0) {
            count += 1;
        }
        else {
            if (students[i] == students[i - 1]) {
                count += 1;
                if (count > highest) {
                    highest = count;
                    mode = students[i];
                }
            }
            else {
                count = 1;
            }
        }
    }
    return mode;
}

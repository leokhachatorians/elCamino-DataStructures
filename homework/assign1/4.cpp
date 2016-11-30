#include <iostream>

using namespace std;

int *mini_mart(int *, int *);
void swap1(int *, int *);
void swap2(int *, int *);
void print(int *);

int main() {
    int array[6] = {5,3,4,17,22,19};
    //print(array);
    int *ptr = mini_mart(array, &array[2]);
    ptr[1] = 9;
    //print(array);
    ptr += 2;
    *ptr = -1;
    //print(array);
    *(array + 1) = 79;
    //print(array);
    //
    cout << array[5] << " " << *ptr << endl;

    cout << "diff=" << &array[5] - ptr << endl;

    //cout << "Going into first swap" << endl;
    swap1(&array[0], &array[1]);
    //cout << "Out first swap" << endl;
    //print(array);
    swap2(array, &array[2]);
    print(array);
}

void print(int a[]) {
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int *mini_mart(int *a, int *b) {
    if (*a < *b) {
        return a;
    }
    return b;
}

void swap1(int *a, int *b) {
    //cout << "In first swap" << endl;
    int *temp = a;
    //cout << temp << " " << *temp << endl;
    a = b;
    //cout << "A: " << a << " " << *a << endl;
    b = temp;
    //cout << "B: " << b << " " << *b << endl;
    //cout << "Leaiving first swap" << endl;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

#include <iostream>
using namespace std;

void find_disorder(int [], int, int *&);

int main() {
    int nums[6] = { 10, 20, 20, 40, 30, 50 };
    int *ptr;


    find_disorder(nums, 6, ptr);
    if (ptr == nullptr) {
        cout << "The array is ordered" << endl;
    }
    else {
        cout << "The disorder is at address " << ptr << endl;
        cout << "It's at index " << ptr - nums << endl;
        cout << "The item's value is " << *ptr << endl;
    }
}

void find_disorder(int arr[], int n, int *&p) {
    for (int k = 1; k < n; k++) {
        if (arr[k] < arr[k - 1]) {
            p = &arr[k];
            return;
        }
    }
    p = nullptr;
}

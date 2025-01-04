#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);
void print(int a[], int size);
bool checkIncreasingArray(int a[], int size);

int main() {
    cout << "\n\nWorking with array.";

    int a[MAX_SIZE];
    int size = 0;

    // Input array
    enter(a, size);

    // Print array
    cout << "\nArray: ";
    print(a, size);

    // Check if the array is increasing
    bool isIncreasingArray = checkIncreasingArray(a, size);
    if (isIncreasingArray) {
        cout << "\nThe array is non-decreasing (increasing or equal elements).";
    }else {
        cout << "\nThe array is not non-decreasing.";
    }

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
    do {
        cout << "\nEnter size of the array (1 and " << MAX_SIZE << "): ";
        cin >> size;

        if (size <= 0
        || size > MAX_SIZE) {
            cout << "\nInvalid size! Size must be between 1 and " << MAX_SIZE << ".";
        }
    }while (size <= 0 || size > MAX_SIZE);

    cout << "\nEnter " << size << " elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cout << " Enter a[" << i << "]: ";
        cin >> a[i];
    }
}

void print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

bool checkIncreasingArray(int a[], int size) {
    for (int i = 1; i < size; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }

    return true;
}
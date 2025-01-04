#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);
void print(int a[], int size);
void removePosK(int a[], int& size, int k);

int main() {
    cout << "\n\nWorking with array.";

    int a[MAX_SIZE];
    int size = 0;

    // Input array
    enter(a, size);

    // print Original Array
    cout << "\nOriginal array: ";
    print(a, size);

    int k = 0;
    do {
        cout << "\nEnter position k(0 <= k <= " << size - 1 << ") to delete: ";
        cin >> k;

        if (k < 0
        || k >= size) {
            cout << "\nInvalid k! k must be between 0 and " << size - 1 << ".";
        }
    }while (k < 0 || k >= size);

    // remove element at position k
    removePosK(a, size, k);

    // print array after removing element at position k
    cout << "\nArray after deleting element at position " << k << ": ";
    print(a, size);

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
    do {
        cout << "\nEnter size of the array(1 <= size " << MAX_SIZE << "): ";
        cin >> size;

        if (size <= 0
        || size > MAX_SIZE) {
            cout << "\nInvalid size! Size must be between 1 and " << MAX_SIZE << ".";
        }
    }while (size <= 0 || size > MAX_SIZE);

    cout << "\nEnter " << size << " elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cout << "Enter a[" << i << "]: ";
        cin >> a[i];
    }
}

void print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

void removePosK(int a[], int& size, int k) {
    // shift elements to the left starting from position l
    for (int i = k; i < size; i++) {
        a[i] = a[i + 1];
    }

    // decrease array size
    size--;
}
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);
void print(int a[], int size);
void addElementAtPosK(int a[], int& size, int value, int k);

int main() {
    cout << "\n\nWorking with array.";

    int a[MAX_SIZE];
    int size = 0;

    // Input array
    enter(a, size);

    // print original array
    cout << "\nOriginal array: ";
    print(a, size);

    // Input value to add
    int value = 0;
    cout << "\nEnter value to add: ";
    cin >> value;

    // Input position to add the value
    int k = 0; // position to add value
    do {
        cout << "Enter k(position to add and 0 <= k <= " << size << "): ";
        cin >> k;

        if (k < 0
        || k > size) {
            cout << "\nInvalid size! Size must be between 0 and " << size << ".";
        }
    }while (k < 0 || k > size);

    // Add value to position k
    addElementAtPosK(a, size, value, k);

    // print array after adding value to position k
    cout << "\nArray after adding value to position " << k << ": ";
    print(a, size);

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
    do {
        cout << "\nEnter size of the array(1 <= size <= " << MAX_SIZE << "): ";
        cin >> size;

        if (size < 1
        || size > MAX_SIZE) {
            cout << "\nInvalid size! Size must be between 1 and " << MAX_SIZE << ".";
        }
    }while (size < 1 || size > MAX_SIZE);

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

void addElementAtPosK(int a[], int& size, int value, int k) {
    // Shift elements to the right starting from position k
    for (int i = size; i > k; i--) {
        a[i] = a[i - 1];
    }

    // Increase the size of the array
    size++;

    // Insert the new value at position k
    a[k] = value;
}


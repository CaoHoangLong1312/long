#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void enter(float a[], int& size);
void print(float a[], int size);

void reverseArray(float a[], int size);

int main() {
    cout << "\n\nWorking with array.";

    float a[MAX_SIZE];
    int size = 0;

    enter(a, size);

    cout << "\nOriginal array: \n";
    print(a, size);

    reverseArray(a, size);
    
    cout << "\nArray after reversing is: \n";
    print(a, size);

    cout << "\n\n";
    return 0;
}

void enter(float a[], int& size) {
    do {
        cout << "\nEnter size of the array: ";
        cin >> size;

        if (size <= 0
        || size > MAX_SIZE) {
            cout << "\nInvalid size! Size must be between 1 and 100. \n";
        }
    }while (size <= 0 || size > MAX_SIZE);

    cout << "\nEnter " << size << " elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cout << "Enter a[" << i << "]: ";
        float number;
        cin >> number;
        a[i] = number;
    }
}

void print(float a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

void reverseArray(float a[], int size) {
    for (int i = 0; i < size / 2; i++) {
        float temp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = temp;
    }
}
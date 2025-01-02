#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);
void print(int a[], int size);

bool checkSymmetricArray(int a[], int size);

int main() {
    cout << "\n\nWorking with array.";

    int a[MAX_SIZE];
    int size = 0;
    
    enter(a, size);

    cout << "\nArray: \n";
    print(a, size);

    bool isSymmetricArray = checkSymmetricArray(a, size);
    if (isSymmetricArray) {
        cout << "\nThis array is symmetric.";
    }else {
        cout << "\nThis array isn't symmetric.";
    }

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
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
        cin >> a[i];
    }
}

void print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

bool checkSymmetricArray(int a[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (a[i] != a[size - 1 - i]) {
            return false;
        }
    }

    return true;
}
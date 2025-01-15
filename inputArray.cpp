#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/// @brief Enter the value of elements in the array
/// @param a array 
/// @param n size of the array
void inputArray(int* &a, int &n);

int main() {
    cout << "\n\nWorking with dynamic array.";

    int* a = nullptr;
    int n = 0; // number of elements in the array

    // Enter the value of elements in the array
    inputArray(a, n);

    // Output array
    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }

    // free the allocated array
    delete[] a;

    cout << "\n\n";
    return 0;
}

void inputArray(int* &a, int &n) {
    const int INITIAL_SIZE = 10;
    int sizeArray = INITIAL_SIZE;
    n = 0;
    a = new int[sizeArray];

    cout << "\n\nEnter elements (type -1 to stop): \n";
    while(true) {
        string input;
        cout << " Enter a[" << n + 1 << "]: ";
        cin >> input;

        stringstream ss(input);
        int value;
        char extra;
        if (! (ss >> value) || ss >> extra) {
            cout << "\nInvalid input! Please enter again (enter an integer). \n";
            continue;
        }

        if (value == -1) {
            break;
        }

        if (n == sizeArray) {
            sizeArray *= 2;
            int* newArray = new int[sizeArray];

            // Copy the value of elements in the old array
            for (int i = 0; i < n; i++) {
                newArray[i] = a[i];
            }

            // free the old array
            delete[] a;
            a = newArray;
        }

        a[n] = value;
        n++;
    }
}

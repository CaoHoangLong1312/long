#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/// @brief Enter the value of elements in the array
/// @param a Pointer to the integer array
/// @param n size of the array
void inputArray(int* &a, int &n);
/// @brief Print elements in the array
/// @param a Pointer to the integer array
/// @param n size of the array
void printArray(int* a, int n);
/// @brief Find the longest ascending subarray 
/// @param a Pointer to the integer array
/// @param n size of the array
/// @param length the length of the longest ascending subarray
/// @return Pointer to the start of the longest ascending subarray
int* findLongestAscendingSub(int* a, int n, int& length);

int main() {
    cout << "\n\nWorking with pointer array.";

    int* a = nullptr;
    int n = 0;

    // Enter elements in the array
    inputArray(a, n);

    // Print the array
    cout << "\nOriginal array: ";
    printArray(a, n);

    // Find longest ascending sub
    int length = 0;
    int* longestSubarray = findLongestAscendingSub(a, n, length);

    // Print the result
    if (length == 0) {
        cout << "\n\nThe array is empty.";
    }else {
        cout << "\n\nLength of longest ascending subarray: " << length;
        cout << "\nLongest ascending subarray: ";
        for (int i = 0; i < length; i++) {
            cout << longestSubarray[i] << " ";
        }
    }
    
    // free dynamic array
    delete[] a;

    cout << "\n\n";
    return 0;
}

void inputArray(int* &a, int &n) {
    const int INITIAL_SIZE = 10;
    int sizeArray = INITIAL_SIZE;
    a = new int[sizeArray];
    n = 0;

    cout << "\n\nEnter elements (type -1 to stop). \n";
    while (true) {
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

            for (int i = 0; i < n; i++) {
                newArray[i] = a[i];
            }

            delete[] a;
            a = newArray;
        }

        a[n] = value;
        n++;
    }
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
}

int* findLongestAscendingSub(int* a, int n, int& length) {
    if (n == 0) {
        length = 0;
        return nullptr;
    }

    length = 1;
    int maxLen = 1;
    int startIndex = 0;
    int maxStartIndex = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            length++;
        }else {
            if (length > maxLen) {
                maxLen = length;
                maxStartIndex = startIndex;
            }

            length = 1;
            startIndex = i;
        }
    }

    if (length > maxLen) {
        maxLen = length;
        maxStartIndex = startIndex;
    }

    length = maxLen;
    return &a[maxStartIndex];
}
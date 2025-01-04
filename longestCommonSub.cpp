#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);

void print(int a[], int size);

void printLongestCommonSubsequence(int a[], int size);

int main() {
    cout << "\n\nWorking with array.";

    int a[MAX_SIZE];
    int size = 0;

    enter(a, size);

    cout << "\nArray: ";
    print(a, size);

    // Subsequence contains same elements
    cout << "\n\nLongest common subsequences are: ";
    printLongestCommonSubsequence(a, size);

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
    do {
        cout << "\nEnter size of the array(1 <= size <= " << MAX_SIZE << "): ";
        cin >> size;

        if (size <= 0 || size > MAX_SIZE) {
            cout << "\nInvalid size! Size must be between 1 and " << MAX_SIZE << ".";
        }
    }while (size <=0 || size > MAX_SIZE);

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

void printLongestCommonSubsequence(int a[], int size) {
    int count = 1;
    int maxCount = 1;
    int startIndices[MAX_SIZE];
    int startIndexCount = 0;

    // Find maxCount and start indices (same elements)
    for (int i = 1; i < size; i++) {
        if (a[i] == a[i - 1]) {
            count++;

            if (count > maxCount) {
                maxCount = count;
                startIndexCount = 0; // remove all old index
                startIndices[startIndexCount] = i - maxCount + 1;
                startIndexCount++;
            }else if (count == maxCount) {
                startIndices[startIndexCount] = i - maxCount + 1;
                startIndexCount++;
            }
        }else {
            count = 1;
        }
    }

    // print longest common subsequence (same elements)
    if (maxCount > 1) {
        for (int i = 0; i < startIndexCount; i++) {
            cout << "{";

            for (int j = 0; j < maxCount; j++) {
                cout << a[startIndices[i] + j];

                if (j < maxCount - 1) {
                    cout << ", ";
                }
            }

            cout << "}";
            
            if (i < startIndexCount - 1) {
                cout << ", ";
            }
        }
    }else {
        cout << "\nNo repeating subsequences found.";
    }
}
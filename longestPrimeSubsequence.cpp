#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);
void print(int a[], int size);
bool checkPrime(int num);
void printLongestPrimeSub(int a[], int size);

int main() {
    cout << "\n\nWorking with array.";

    int a[MAX_SIZE];
    int size = 0;

    // input array
    enter(a, size);

    // print original array
    cout << "\nOriginal array: ";
    print(a, size);

    // print longest prime subsequence
    printLongestPrimeSub(a, size);

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
    do {
        cout << "\nEnter size of the array(1 <= size <= " << MAX_SIZE << "): ";
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

bool checkPrime(int num) {
    if (num < 2) {
        return false;
    }

    if (num == 2) {
        return true;
    }

    if (num % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void printLongestPrimeSub(int a[], int size) {
    int count = 0;
    int maxCount = 0;
    int startIndices[MAX_SIZE];
    int startIndexCount = 0;

    for (int i = 0; i < size; i++) {
        bool isPrime = checkPrime(a[i]);
        if (isPrime) {
            count++;

            if (count > maxCount) {
                maxCount = count;       
                startIndexCount = 0; // remove all old indices
                startIndices[startIndexCount] = i - maxCount + 1;
                startIndexCount++;
            }else if (count == maxCount) {
                startIndices[startIndexCount] = i - maxCount + 1;
                startIndexCount++;
            }
        }else {
            count = 0; // Reset count when encountering a non-prime number
        }
    }

    // Print longest prime subsequence
    if (maxCount > 0) {
        cout << "\nLongest prime subsequence length is: " << maxCount;
        cout << "\nLongest prime subsequences are: ";

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
        cout << "\nNo prime numbers found in the array.";
    }
}
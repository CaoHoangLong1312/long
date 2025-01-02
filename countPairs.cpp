#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

int generateRandomInteger(int min, int max);

void printRandomArray(int a[], int n);

void listPairsSumEqualK(int a[], int n, int& k);

bool checkPrime(int num);
void listPrimePairs(int a[], int n);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // Seed for random number

    int n = generateRandomInteger(1, 30); // generate random size
    cout << "\nSize of the random array is: " << n;

    int a[MAX_SIZE];
    cout << "\n\nRandom array: ";
    printRandomArray(a, n); // Generate and print random array

    // List pairs whose sum equals k
    int k = 0;
    listPairsSumEqualK(a, n, k);

    // List prime pairs
    cout << "\nCoprime pairs in an array are: ";
    listPrimePairs(a, n);

    cout << "\n\n";
    return 0;
}

int generateRandomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printRandomArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = generateRandomInteger(1, 100); // Assign random values
        cout << a[i] << " ";
    }
}

void listPairsSumEqualK(int a[], int n, int& k) {
    cout << "\n\nEnter value to check: ";
    cin >> k;

    bool found = false;
    cout << "Pairs whose sum is k are: ";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) {
                cout << " (" << a[i] << ", " << a[j] << ") ";
                found = true;
            }
        }
    }

    if (! found) {
        cout << "\nNo paris whose sum is " << k << ". ";
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

void listPrimePairs(int a[], int n) {
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (checkPrime(a[i])) {
                if (checkPrime(a[j])) {
                    cout << " (" << a[i] << ", " << a[j] << ") ";
                    found = true;
                }
            }
        }
    }

    if (! found) {
        cout << "\nNo prime pairs found.";
    }
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

int generateRandomInteger(int min, int max);

void generateRandomArray(int a[], int size);
void printRandomArray(int a[], int size);

void calcSumKElements(int a[], int size, int k);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // seed for random number

    int a[MAX_SIZE];

    int size = generateRandomInteger(5, 15);
    cout << "\n\nSize of the array is: " << size;

    generateRandomArray(a, size);
    cout << "\n\nRandom array is: ";
    printRandomArray(a, size);

    int k = 0;
    do {
        cout << "\nEnter k to calculate(0 < k <= " << size << "): ";
        cin >> k;

        if (k <= 0 || k > size) {
            cout << "\nInvalid k! k must be between 1 and " << size << ".";
        }
    }while (k <= 0 || k > size);

    calcSumKElements(a, size, k);

    cout << "\n\n";
    return 0;
}

int generateRandomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = generateRandomInteger(1, 50);
    }
}

void printRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

void calcSumKElements(int a[], int size, int k) {
    // sliding window technique 
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += a[i];
    }

    cout << "\nThe subsequence sum starts from index 0 is: " << sum;

    for (int i = 1; i <= size - k; i++) {
        sum = sum - a[i - 1] + a[i + k - 1];
        cout << "\nThe subsequence sum starts from index " << i << " is: " << sum;
    }
}
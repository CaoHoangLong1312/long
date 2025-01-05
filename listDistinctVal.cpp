#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 101;

int generateRandomInteger(int min, int max);
void generateRandomArray(int a[], int size);
void printRandomArray(int a[], int size);
void listDistinctVal(int a[], int size);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // seed for random number

    int a[15];
    
    int size = generateRandomInteger(5, 15);
    cout << "\n\nSize of the array: " << size;

    generateRandomArray(a, size);
    cout << "\n\nRandom array: ";
    printRandomArray(a, size);

    listDistinctVal(a, size);

    cout << "\n\n";
    return 0;
}

int generateRandomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = generateRandomInteger(0, 100);
    }
}

void printRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

void listDistinctVal(int a[], int size) {
    int fre[MAX_SIZE] = {0};
    int maxVal = 0;

    for (int i = 0; i < size; i++) {
        fre[a[i]] = 1;

        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }

    cout << "\nDifferent values in the array are: ";
    for (int i = 0; i <= maxVal; i++) {
        if (fre[i] == 1) {
            cout << i << " ";
        }
    }
}
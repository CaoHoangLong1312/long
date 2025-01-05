#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 101;

int generateRandomInteger(int min, int max);
void generateRandomArray(int a[], int size);
void printRandomArray(int a[], int size);
void printFrequencyElements(int a[], int size);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // seed for random number

    int size = generateRandomInteger(20, 50);
    cout << "\n\nSize of the array: " << size;

    int a[size];

    generateRandomArray(a, size);
    cout << "\nRandom array: ";
    printRandomArray(a, size);

    printFrequencyElements(a, size);

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

void printFrequencyElements(int a[], int size) {
    int fre[MAX_SIZE] = {0};

    for (int i = 0; i < size; i++) {
        fre[a[i]]++;
    }

    cout << "\nThe frequency of elements in the array are: ";
    for (int i = 0; i < MAX_SIZE; i++) {
        if (fre[i] > 0) {
            cout << "\n " << i << " appears " << fre[i] << " time(s).";
        }       
    }
}
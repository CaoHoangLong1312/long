#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 101;

int generateRandomInteger(int min, int max);
void generateRandomArray(int a[], int size);
void printRandomArray(int a[], int size);
void printFrequencyElements(int a[], int size);
void printMostFrequentElements(int a[], int size);
void listValues(int a[], int b[], int size);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // seed for random number

    int size = generateRandomInteger(20, 50);
    cout << "\n\nSize of the array: " << size;

    int a[size];
    generateRandomArray(a, size);
    cout << "\nRandom array(a): ";
    printRandomArray(a, size);

    printFrequencyElements(a, size);

    printMostFrequentElements(a, size);

    int b[size];
    generateRandomArray(b, size);
    cout << "\nRandom array(b): ";
    printRandomArray(b, size);

    cout << "\nThe values that belong to either of the two arrays: ";
    listValues(a, b, size);

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
            cout << "\n - " << i << " appears " << fre[i] << " time(s).";
        }       
    }
}

void printMostFrequentElements(int a[], int size) {
    int fre[MAX_SIZE] = {0};
    int maxFre = 1;

    for (int i = 0; i < size; i++) {
        fre[a[i]]++;

        if (fre[a[i]] > maxFre) {
            maxFre = fre[a[i]];
        }
    }

    cout << "\nThe highest frequency of occurrence in the array: " << maxFre;
    cout << "\nElements with the most frequent in the array: ";
    for (int i = 0; i <= 100; i++) {
        if (fre[i] == maxFre) {
            cout << i << " ";
        }
    } 
}

void listValues(int a[], int b[], int size) {
    int fre[MAX_SIZE] = {0};

    for (int i = 0; i < size; i++) {
        fre[a[i]] = 1;
        fre[b[i]] = 1;
    }

    bool first = true;
    for (int i = 0; i <= MAX_SIZE - 1; i++) {
        if (fre[i] == 1) {
            if (! first) {
                cout << ", ";
            }

            cout << i;
            first = false;
        }
    }
}
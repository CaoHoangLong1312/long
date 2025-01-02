#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

int generateRandomInteger(int min, int max);

void generateRandomArray(int a[], int size);
void printRandomArray(int a[], int size);

void listFrequencies(int a[], int size);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // seed for random number

    int a[MAX_SIZE];

    int size = generateRandomInteger(10, 30);
    cout << "\n\nSize of the array is: " << size;

    generateRandomArray(a, size);
    cout << "\n\nRandom array: "; 
    printRandomArray(a, size);

    cout << "\n\nThe frequency of each elements in the array is: ";
    listFrequencies(a, size);

    cout << "\n\n";
    return 0;
}

int generateRandomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = generateRandomInteger(1, 100);
    }
}

void printRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

void listFrequencies(int a[], int size) {
    int fre[MAX_SIZE] = {0};

    for (int i = 0; i < size; i++) {
        if (fre[i] == 0) {
            int count = 1;

            for (int j = i + 1; j < size; j++) {
                if (a[j] == a[i]) {
                    fre[j] = 1;
                    count++;
                }   
            }

            cout << "\n " << a[i] << " appears " << count << " time(s).";
        }
    }
}
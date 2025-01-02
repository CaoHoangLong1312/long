#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomInteger(int min, int max);

void generateRandomArray(int a[], int size);
void printRandomArray(int a[], int size);

void listDistincts(int a[], int size);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // seed for random number

    const int MAX_SIZE = 100;
    int a[MAX_SIZE];

    int size = generateRandomInteger(10, 30); // generate random size
    cout << "\n\nSize of the array is: " << size;

    generateRandomArray(a, size);
    cout << "\n\nRandom array: ";
    printRandomArray(a, size); // print random array

    cout << "\nDistinct elements in the array are: ";
    listDistincts(a, size);

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

void listDistincts(int a[], int size) {
    for (int i = 0; i < size; i++) {
        bool isUnique = true;

        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            cout << a[i] << " ";
        }
    }
}
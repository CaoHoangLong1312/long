#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomInteger(int min, int max);

void printRandomArray(int a[], int size);

int countDistincts(int a[], int size);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0));

    const int MAX_SIZE = 100;
    int a[MAX_SIZE];

    int size = generateRandomInteger(10, 50);
    cout << "\nSize of the array is: " << size;

    cout << "\nRandom array: ";
    printRandomArray(a, size);

    int distinctCount = countDistincts(a, size);
    cout << "\nThere are " << distinctCount << " distinct elements in the array.";

    cout << "\n\n";
    return 0;
}

int generateRandomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = generateRandomInteger(10, 100);
        cout << a[i] << " ";
    }
}

int countDistincts(int a[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        bool isUnique = true;

        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            count++;
        }
    }

    return count;
}
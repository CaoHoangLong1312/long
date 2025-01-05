#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

int generateRandomInteger(int min, int max);
void generateSortedRandomArray(int a[], int n);
void printRandomArray(int a[], int n);
void removeDuplicates(int a[], int& n);
void shiftLargestNumberToBeginning(int a[], int n);
bool checkEven(int num);
void reverseEvens(int a[], int n);
bool checkPrime(int num);
int findNearestPrime(int num);
void convertIntoPrimeArray(int a[], int num);

int main() {
    cout << "\n\nWorking with random array.";

    srand(time(0)); // seed for random number

    int a[MAX_SIZE];

    int n = generateRandomInteger(10, 30); // size of the array
    cout << "\n\nSize of the array: " << n;

    generateSortedRandomArray(a, n);
    cout << "\nRandom array: ";
    printRandomArray(a, n);

    removeDuplicates(a, n);
    cout << "\nRandom array after removing duplicate elements: ";
    printRandomArray(a, n);

    shiftLargestNumberToBeginning(a, n);
    cout << "\nRandom array after shifting the largest number to beginning: ";
    printRandomArray(a, n);

    reverseEvens(a, n);
    cout << "\nRandom array after reversing even elements in the array: ";
    printRandomArray(a, n);

    convertIntoPrimeArray(a, n);
    cout << "\nRandom array after converting into prime array: ";
    printRandomArray(a, n);

    cout << "\n\n";
    return 0;
}

int generateRandomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateSortedRandomArray(int a[], int n) {
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value = generateRandomInteger(15, 35);

        a[size] = value;
        size++;

        for (int j = size - 1; j > 0 && a[j] < a[j - 1]; j--) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
        }
    }
}   

void printRandomArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void removeDuplicates(int a[], int& n) {
    int newSize = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            a[newSize] = a[i];
            newSize++;
        }
    }

    n = newSize;
}

void shiftLargestNumberToBeginning(int a[], int n) {
    int largestVal = a[n - 1];

    for (int i = n - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }

    a[0] = largestVal;
}

bool checkEven(int num) {
    if (num % 2 == 0) {
        return true;
    }

    return false;
}

void reverseEvens(int a[], int n) {
    // int evens[MAX_SIZE];
    // int evenSize = 0;

    // for (int i = 0; i < n; i++) {
    //     bool isEven = checkEven(a[i]);

    //     if (isEven) {
    //         evens[evenSize] = a[i];
    //         evenSize++;
    //     }
    // }

    // for (int i = 0; i < evenSize / 2; i++) {
    //     int temp = evens[i];
    //     evens[i] = evens[evenSize - 1 - i];
    //     evens[evenSize - 1 - i] = temp;
    // }

    // int val = 0;
    // for (int i = 0; i < n; i++) {
    //     bool isEven = checkEven(a[i]);

    //     if (isEven) {
    //         a[i] = evens[val];
    //         val++;
    //     }
    // }

    // Step 2: Use 2 pointer
    int left = 0;
    int right = n - 1;

    while (left < right) {
        while (left < n && a[left] % 2 != 0) {
            left++;
        }

        while (right >= 0 && a[right] % 2 != 0) {
            right--;
        }

        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }

        left++;
        right--;
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

int findNearestPrime(int num) {
    while (false == checkPrime(num)) {
        num++;
    }

    return num;
}

void convertIntoPrimeArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = findNearestPrime(a[i]);
    }
}
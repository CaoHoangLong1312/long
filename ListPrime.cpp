#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);
void print(int a[], int size);

bool checkPrime(int num);
void listPrime(int a[], int size);

int main() {
    cout << "\nWorking with array.";

    int a[MAX_SIZE];

    int size = 0;
    enter(a, size);

    cout << "\nArray: \n";
    print(a, size);

    cout << "\nPrime numbers in the array are: ";
    listPrime(a, size);

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
    do {
        cout << "\nEnter size of the array (1 -> 100): ";
        cin >> size;

        if (size <= 0
        || size > MAX_SIZE) {
            cout << "\nInvalid size. Please enter a size between 1 and 100.\n";
        }
    }while (size <= 0 || size > MAX_SIZE);

    cout << "\nEnter " << size << " elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cout << "Enter a[" << i << "]: ";
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

    if (num % 2 == 0) { // remove even numbers
        return false;
    }

    for (int i = 3; i <= sqrt(num); i+=2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void listPrime(int a[], int size) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        bool isPrime = checkPrime(a[i]);
        if (isPrime) {
            cout << a[i] << " ";
            found = true;
        }
    }

    if (! found) {
        cout << "\nNo prime numbers found.";
    }
}
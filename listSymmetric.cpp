#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void enter(int a[], int& size);
void print(int a[], int size);

bool checkSymmetric(int num);
int countSymmetrics(int a[], int size);
void listSymmetrics(int a[], int size);

int main() {
    cout << "\n\nWorking with array.";

    int a[MAX_SIZE];

    int size = 0;
    enter(a, size);

    cout << "\nArray: \n";
    print(a, size);

    int symmetricCount = countSymmetrics(a, size);
    if (symmetricCount == 0) {
        cout << "\nNo symmetric numbers found.";
    }else {
        cout << "\n\nThere are " << symmetricCount << " symmetric number(s) in the array. \n";
        cout << "List of symmetric numbers is: \n";
        listSymmetrics(a, size);
    }

    cout << "\n\n";
    return 0;
}

void enter(int a[], int& size) {
    do {
        cout << "\nEnter size of the array (1 -> 100): ";
        cin >> size;

        if (size <= 0 
        || size > MAX_SIZE) {
            cout << "\nInvalid size. Please enter a size between 1 and 100 inclusive. \n";
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

bool checkSymmetric(int num) {
    if (num < 0) {
        return false;
    }

    int symmetric = 0;
    int value = num;

    while (value > 0) {
        int lastDigit = value % 10;
        symmetric = symmetric * 10 + lastDigit;
        value /= 10;
    }

    return symmetric == num;
}

int countSymmetrics(int a[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        bool isSymmetric = checkSymmetric(a[i]);
        if (isSymmetric) {
            count++;
        }
    }

    return count;
}

void listSymmetrics(int a[], int size) {
    for (int i = 0; i < size; i++) {
        bool isSymmetric = checkSymmetric(a[i]);
        if (isSymmetric) {
            cout << a[i] << " ";
        }
    }
}
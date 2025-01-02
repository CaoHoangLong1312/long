#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void enter(float a[], int& size);
void print(float a[], int size);

float findMax(float a[], int size);
float findMin(float a[], int size);

int main() {
    cout << "\n\nWorking with array.";

    float a[MAX_SIZE];

    int size = 0;
    enter(a, size);

    cout << "\nArray: \n";
    print(a, size);


    float maxVal = findMax(a, size);
    cout << "\nThe largest value of the array is: " << maxVal;


    float minVal = findMin(a, size);
    cout << "\nThe smallest value of the array is: " << minVal;

    cout << "\n\n";
    return 0;
}

void enter(float a[], int& size) {
    do {
        cout << "\nEnter size of the array(1 -> 100): ";
        cin >> size;

        if (size <= 0
        || size > MAX_SIZE) {
            cout << "\nInvalid size! Size must be between 1 and 100. \n";
        }
    }while (size <= 0 || size > MAX_SIZE);

    cout << "\nEnter " << size << " elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cout << "Enter a[" << i << "]: ";
        float number;
        cin >> number;
        a[i] = number;
    }
}

void print(float a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

float findMax(float a[], int size) {
    float max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

float findMin(float a[], int size) {
    float min = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min;
}
#include <iostream>
using namespace std;

int* findMax(int* arr, int n);

int main() {
    cout << "\n\nWorking with pointer array.";

    int arr[] = {13, 12, 11, 2, 3, 5, 9, 6, 10, 78, 15};
    int n = sizeof(arr) / sizeof(arr[0]); // size of the array

    int* max = findMax(arr, n);
    cout << "\n\nThe largest value of the given array: " << *max;

    cout << "\n\n";
    return 0;
}

int* findMax(int* arr, int n) {
    int* largest = &arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > *largest) {
            *largest = arr[i];
        }
    }

    return largest;
}
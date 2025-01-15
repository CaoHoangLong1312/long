#include <iostream>
using namespace std;

void printArray(int* a, int n);

int main() {
    cout << "\n\nWorking with array.";

    int a[] = {13, 12, 11, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\nOriginal array: ";
    printArray(a, n);

    cout << "\n\n";
    return 0;
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
}
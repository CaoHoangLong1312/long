#include <iostream>
using namespace std;

/// @brief Concatenating two arrays
/// @param a Pointer to the array a
/// @param b Pointer to the array b
/// @param na Size of the array a
/// @param nb Size of the array b
/// @param nc Size of the array (Concatenating array a and array b)
/// @return Pointer to the newly concatenated array
int* concatenateTwoArray(int* a, int* b, int na, int nb, int& nc);
/// @brief Print the value of elements in the array
/// @param a Pointer to the integer array
/// @param n Size of the array 
void printArray(int* a, int n);

int main() {
    cout << "\n\nWorking with pointer array.";

    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int na = sizeof(a) / sizeof(a[0]);

    int b[] = {13, 12, 12, 11, 2, 3, 5, 9, 6, 10, 77, 14, 2};
    int nb = sizeof(b) / sizeof(b[0]);

    // Concatenate arrays
    int nc = 0;
    int* newArr = concatenateTwoArray(a, b, na, nb, nc);

    // Print the result
    cout << "\n\nTwo arrays after concatenating (nc = " << nc << "): ";
    printArray(newArr, nc);

    delete[] newArr;

    cout << "\n\n";
    return 0;
}

int* concatenateTwoArray(int* a, int* b, int na, int nb, int& nc) {
    int* newArr = new int[na + nb];
    nc = 0;

    for (int i = 0; i < na; i++) {
        newArr[nc] = a[i];
        nc++;
    }

    for (int i = 0; i < nb; i++) {
        newArr[nc] = b[i];
        nc++;
    }

    return newArr;
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
}
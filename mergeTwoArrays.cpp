#include <iostream>
using namespace std;

/// @brief Merges two ascending arrays into a new ascending array
/// @param a Pointer to the array a
/// @param b Pointer to the array b
/// @param na Size of the array a
/// @param nb Size of the array b
/// @param nc Size of the merged array
/// @return Pointer to the newly allocated merged array
int* merge2Arrays(int* a, int* b, int na, int nb, int& nc);
/// @brief Print the value of elements in the array
/// @param a Pointer to the integer array
/// @param n Size of the array
void printArray(int* a, int n);

int main() {
    cout << "\n\nWorking with pointer array.";

    int a[] = {2, 3, 5, 6, 9, 10, 11, 12, 13};
    int na = sizeof(a) / sizeof(a[0]);

    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int nb = sizeof(b) / sizeof(b[0]);

    // Merges two ascending arrays into a new ascending array
    int nc = 0;
    int* c = merge2Arrays(a, b, na, nb, nc);

    // Print the result
    cout << "\n\nMerged array: ";
    printArray(c, nc);

    delete[] c;

    cout << "\n\n";
    return 0;
}

int* merge2Arrays(int* a, int* b, int na, int nb, int& nc) {
    int* newArr = new int[na + nb];

    int i = 0;
    int j = 0;
    nc = 0;

    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            newArr[nc] = a[i];
            i++;
        }else {
            newArr[nc] = b[j];
            j++;
        }

        nc++;
    }

    while (i < na) {
        newArr[nc] = a[i];
        i++;
        nc++;
    }

    while (j < nb) {
        newArr[nc] = b[j];
        j++;
        nc++;
    }

    return newArr;
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
}
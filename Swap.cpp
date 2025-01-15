#include <iostream>
using namespace std;

void swap(int* a, int* b);

int main() {
    cout << "\n\nWorking with pointer (swap 2 integers).";

    int m = 13; // first integer
    int n = 12; // second integer

    int* a = &m;
    int* b = &n;

    // swap 2 given integers
    swap(a, b);

    // print the swapped values
    cout << "\nThe value of m after swapping: " << m;
    cout << "\nThe value of n after swapping: " << n;

    cout << "\n\n";
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
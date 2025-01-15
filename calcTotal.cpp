#include <iostream>
using namespace std;

int* sum(int* a, int* b);

int main() {
    int x = 13;
    int y = 12;

    int* result = sum(&x, &y);

    // print the sum of x and y
    cout << "\nThe sum of " << x << " and " << y << " is: " << *result;

    // free the dynamically allocated memory
    delete result;

    cout << "\n\n";
    return 0;
}

int* sum(int* a, int* b) {
    // Dynamically allocate memory for the result
    int* result = new int;
    *result = *a + *b;
    return result;   
}
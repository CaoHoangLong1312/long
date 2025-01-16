#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void inputArray(int* &a, int &n);
void printArray(int* a, int n);
void swapArrays(int* &a, int &na, int* &b, int &nb);

int main() {
    cout << "\n\nWorking with pointer array.";

    int* a = nullptr;
    int na = 0;
    
    // Enter the value of elements in the array a
    inputArray(a, na);

    int* b = nullptr;
    int nb = 0;

    // Enter the value of elements in the array b
    inputArray(b, nb);

    if (na == 0 && nb == 0) {
        cout << "\nBoth arrays are empty.";
    }else if (na == 0) {
        cout << "\nArray a is empty.";

        // Print the array b
        cout << "\nOriginal array b: ";
        printArray(b, nb);
    }else if (nb == 0) {
        cout << "\nArray b is empty.";

        // Print the array a
        cout << "\n\nOriginal array a: ";
        printArray(a, na);
    }else {
        // Print the original array
        cout << "\n\nOriginal array a: ";
        printArray(a, na);

        cout << "\nOriginal array b: ";
        printArray(b, nb);

        // Swap 2 arrays
        swapArrays(a, na, b, nb);

        // Print the result
        cout << "\n\nArray a after swapping: ";
        printArray(a, na);

        cout << "\nArray b after swapping: ";
        printArray(b, nb); 
    } 
               

    delete[] a;
    delete[] b;

    cout << "\n\n";
    return 0;
}

void inputArray(int* &a, int &n) {
    const int INITIAL_SIZE = 10;
    int sizeArray = INITIAL_SIZE;
    a = new int[sizeArray];
    n = 0;

    cout << "\n\nEnter elements (type -1 to stop). \n";
    while(true) {
        string input;
        cout << " Enter a[" << n + 1 << "]: ";
        cin >> input;

        stringstream ss(input);
        int value;
        char extra;

        if (! (ss >> value) || ss >> extra) {
            cout << "\nInvalid input! Please enter again (enter an integer). \n";
            continue;
        }

        if (value == -1) {
            break;
        }

        if (n == sizeArray) {
            sizeArray *= 2;
            int* newArr = new int[sizeArray];

            for (int i = 0; i < n; i++) {
                newArr[i] = a[i];
            }

            delete[] a;
            a = newArr;
        }

        a[n] = value;
        n++;
    }
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
}

void swapArrays(int* &a, int &na, int* &b, int &nb) {
    // Swap pointers
    int* tempPtr = a;
    a = b;
    b = tempPtr;

    // Swap sizes 
    int temp = na;
    na = nb;
    nb = temp;
}

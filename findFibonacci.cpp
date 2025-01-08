#include <iostream>
#include <limits>
using namespace std;

const int MAX_SIZE = 100;
const int MAX_FIB = 46; // Since F(46) is the largest number in the Fibonacci sequence

void enter(int a[][MAX_SIZE], int& rows, int& cols);
void print(int a[][MAX_SIZE], int rows, int cols);
void generateFibonacci(int F[], int& sizeFib);
bool checkFibonacci(int num, int F[], int sizeFib);
void printFibonacci(int a[][MAX_SIZE], int rows, int cols, int F[], int sizeFib);

// Dãy Fibonacci: F(n) = F(n - 1) + F(n - 2) với F(0) = 0 và F(1) = 1;

int main() {
    cout << "\n\nWorking with matrix.";

    int a[MAX_SIZE][MAX_SIZE];

    int rows = 0;
    int cols = 0;

    // Enter matrix
    enter(a, rows, cols);

    // print Original Matrix
    cout << "\nOriginal matrix: \n";
    print(a, rows, cols);

    // generate Fibonacci array
    int F[MAX_FIB];
    int sizeFib = 0;
    generateFibonacci(F, sizeFib);

    // print values belonging to the Fibonacci sequence
    cout << "\nValues belonging to the Fibonacci sequence in a matrix: ";
    printFibonacci(a, rows, cols, F, sizeFib);

    cout << "\n\n";
    return 0;
}

void enter(int a[][MAX_SIZE], int& rows, int& cols) {
    do {
        cout << "\nEnter the number of row(1 <= rows <= " << MAX_SIZE << "): ";
        cin >> rows;

        if (rows <= 0
        || rows > MAX_SIZE) {
            cout << "\nInvalid rows! Rows must be between 1 and " << MAX_SIZE << ".";
        }
    }while (rows <= 0 || rows > MAX_SIZE);

    do {
        cout << "\nEnter the number of col(1 <= cols <= " << MAX_SIZE << "): ";
        cin >> cols;

        if (cols < 1
        || cols > MAX_SIZE) {
            cout << "\nInvalid cols! Cols must be between 1 and " << MAX_SIZE << ".";
        }
    }while (cols < 1 || cols > MAX_SIZE);

    cout << "\nEnter matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            while (true) {
                cout << " Enter a[" << i << "][" << j << "]: ";

                if (cin >> a[i][j]) {
                    break;
                }else {
                    cout << "\nInvalid input! Please enter an integer. \n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
}

void print(int a[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

void generateFibonacci(int F[], int& sizeFib) {
    F[0] = 0;
    F[1] = 1;
    sizeFib = 2;

    while (true) {
        int next = F[sizeFib - 1] + F[sizeFib - 2];

        if (sizeFib == MAX_FIB) { // Stop when exceeding the limit of data type int
            break;
        } 

        F[sizeFib] = next;
        sizeFib++;
    }
}

bool checkFibonacci(int num, int F[], int sizeFib) {
    for (int i = 0; i < sizeFib; i++) {
        if (F[i] == num) {
            return true;
        }
    }

    return false;
}

void printFibonacci(int a[][MAX_SIZE], int rows, int cols, int F[], int sizeFib) {
    bool found = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isFibonacci = checkFibonacci(a[i][j], F, sizeFib);

            if (isFibonacci) {
                cout << a[i][j] << " ";
                found = true;
            }
        }
    }

    if (! found) {
        cout << "\nThere aren't any values belonging to the Fibonacci sequence in a matrix.";
    }
}
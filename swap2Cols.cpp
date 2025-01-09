#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

void enter(float a[][MAX_SIZE], int& rows, int& cols);
void print(float a[][MAX_SIZE], int rows, int cols);
void swapTwoCols(float a[][MAX_SIZE], int rows, int col1, int col2);

int main() {
    cout << "\n\n Matrix column swapper";

    float a[MAX_SIZE][MAX_SIZE];

    int rows = 0;
    int cols = 0;

    // Enter matrix
    enter(a, rows, cols);

    // Print matrix
    cout << "\nOriginal matrix: \n";
    print(a, rows, cols);

    // Enter two columns to swap
    int col1 = 0;
    int col2 = 0;

    do {
        cout << "\nEnter the first column to swap(0 <= col1 <= " << cols - 1 << "): ";
        cin >> col1;

        if (col1 < 0
        || col1 > cols - 1) {
            cout << "\nInvalid col1! Col1 must be between 0 and " << cols - 1 << ".";
        }
    }while (col1 < 0 || col1 > cols - 1);

    do {
        cout << "\nEnter the second column to swap(0 <= col2 <= " << cols - 1 << "): ";
        cin >> col2;

        if (col2 < 0
        || col2 > cols - 1) {
            cout << "\nInvalid col2! Col2 must be between 0 and " << cols - 1 << ".";
        }
    }while (col2 < 0 || col2 > cols - 1);

    if (col1 == col2) {
        cout << "\nThe column are the same. No swapped needed.\n";
    }else {
        // Swap 2 cols
        swapTwoCols(a, rows, col1, col2);
    
        // Print the result
        cout << "\nThe matrix after swapping two columns: \n";
        print(a, rows, cols);
    }

    cout << "\n=== Program Complete ===\n";
    return 0;
}

void enter(float a[][MAX_SIZE], int& rows, int& cols) {
    do {
        cout << "\nEnter the number of row(1 <= rows <= " << MAX_SIZE << "): ";
        cin >> rows;

        if (rows < 1
        || rows > MAX_SIZE) {
            cout << "\nInvalid rows! Rows must be between 1 and " << MAX_SIZE << ".";
        }
    }while (rows < 1 || rows > MAX_SIZE);

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
                    cout << "\nInvalid input! Please enter a number. \n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
}

void print(float a[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

void swapTwoCols(float a[][MAX_SIZE], int rows, int col1, int col2) {
    for (int i = 0; i < rows; i++) {
        float temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
    }
}
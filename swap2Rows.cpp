#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

void enter(float a[][MAX_SIZE], int& rows, int& cols);
void print(float a[][MAX_SIZE], int rows, int cols);
void swapTwoRows(float a[][MAX_SIZE], int cols, int row1, int row2);

int main() {
    cout << "\n\nWorking with matrix.";

    float a[MAX_SIZE][MAX_SIZE];

    int rows = 0;
    int cols = 0;

    // Enter matrix
    enter(a, rows, cols);

    // Print matrix
    cout << "\nOriginal matrix: \n";
    print(a, rows, cols);

    // Enter 2 rows to swap
    int row1 = 0; 
    int row2 = 0;

    do {
        cout << "\nEnter row1 to swap(0 <= row1 <= " << rows - 1 << "): ";
        cin >> row1;

        if (row1 < 0
        || row1 >= rows) {
            cout << "\nInvalid input! row1 must be between 0 and " << rows - 1 << ".";
        }
    }while (row1 < 0 || row1 >= rows);

    do {
        cout << "\nEnter row2 to swap(0 <= row2 <= " << rows - 1 << "): ";
        cin >> row2;

        if (row2 < 0
        || row2 >= rows) {
            cout << "\nInvalid input! row2 must be between 0 and " << rows - 1 << ".";
        }
    }while (row2 < 0 || row2 >= rows);

    // print matrix after swapping 2 rows
    swapTwoRows(a, cols, row1, row2);
    cout << "\nThe matrix after swapping row " << row1 << " and row " << row2 << ": \n";
    print(a, rows, cols); 

    cout << "\n\n";
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
        for (int  j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

void swapTwoRows(float a[][MAX_SIZE], int cols, int row1, int row2) {
    for (int j = 0; j < cols; j++) {
        float temp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = temp;
    }
}
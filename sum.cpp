#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

void enter(float a[][MAX_SIZE], int& rows, int& cols);
void print(float a[][MAX_SIZE], int rows, int cols);
float calcSumRow(float a[][MAX_SIZE], int cols, int row);
float calcSumCol(float a[][MAX_SIZE], int rows, int col);

int main() {
    cout << "\n\nWorking with matrix.";

    float a[MAX_SIZE][MAX_SIZE];

    int rows = 0;
    int cols = 0;

    // Enter matrix
    enter(a, rows, cols);

    // print matrix
    cout << "\nOriginal matrix: \n";
    print(a, rows, cols);

    // print sum of rows
    int row = 0;

    for (row = 0; row < rows; row++) {
        float rowSum = calcSumRow(a, cols, row);
        cout << "\nThe sum of elements in row " << row << ": " << rowSum;
    }

    // print sum of Cols
    int col = 0;

    for (col = 0; col < cols; col++) {
        float colSum = calcSumCol(a, rows, col);
        cout << "\nThe sum of elements in col " << col << ": " << colSum;
    }

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
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

float calcSumRow(float a[][MAX_SIZE], int cols, int row) {
    float rowSum = 0;

    for (int i = 0; i < cols; i++) {
        rowSum += a[row][i];
    }

    return rowSum;
}

float calcSumCol(float a[][MAX_SIZE], int rows, int col) {
    float colSum = 0;

    for (int i = 0; i < rows; i++) {
        colSum += a[i][col];
    }

    return colSum;
}
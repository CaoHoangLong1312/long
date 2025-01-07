#include <iostream>
#include <limits>
using namespace std;

const int MAX_SIZE = 100;

void enter(float a[][MAX_SIZE], int& rows, int& cols);
void print(float a[][MAX_SIZE], int rows, int cols);
float findMin(float a[][MAX_SIZE], int rows, int cols);
float findMax(float a[][MAX_SIZE], int rows, int cols);

int main() {
    cout << "\n\nWorking with matrix.";

    float a[MAX_SIZE][MAX_SIZE];

    int rows = 0;
    int cols = 0;

    enter(a, rows, cols);

    cout << "\nOriginal matrix: \n";
    print(a, rows, cols);

    float min = findMin(a, rows, cols);
    cout << "\nThe smallest value in the matrix: " << min;

    float max = findMax(a, rows, cols);
    cout << "\nThe largest value in the matrix: " << max;

    cout << "\n\n";
    return 0;
}

void enter(float a[][MAX_SIZE], int& rows, int& cols) {
    do {
        cout << "\nEnter the number of rows(1 <= rows <= " << MAX_SIZE << "): ";
        cin >> rows;

        if (rows < 1
        || rows > MAX_SIZE) {
            cout << "\nInvalid rows! Rows must be between 1 and " << MAX_SIZE << ".";
        }
    }while (rows < 1 || rows > MAX_SIZE);

    do {
        cout << "\nEnter the number of cols(1 <= cols <= " << MAX_SIZE << "): ";
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

float findMin(float a[][MAX_SIZE], int rows, int cols) {
    float minValue = a[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] < minValue) {
                minValue = a[i][j];
            }
        }
    }

    return minValue;
}

float findMax(float a[][MAX_SIZE], int rows, int cols) {
    float maxValue = a[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] > maxValue) {
                maxValue = a[i][j];
            }
        }
    }

    return maxValue;
}
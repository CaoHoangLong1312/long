#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

void enter(float matrix[][MAX_SIZE], int& rows, int& cols);
void print(float matrix[][MAX_SIZE], int rows, int cols);
void quickSort(float a[], int left, int right);
void sortRowOfMatrix(float matrix[][MAX_SIZE], int rows, int cols);

int main() {
    cout << "\n\n Sort row of matrix.(Quick sort)";

    float matrix[MAX_SIZE][MAX_SIZE];

    int rows = 0;
    int cols = 0;

    // Enter matrix
    enter(matrix, rows, cols);

    // Print original matrix
    cout << "\nOriginal matrix: \n";
    print(matrix, rows, cols);

    // Sort row of matrix (quickSort)
    sortRowOfMatrix(matrix, rows, cols);
    
    // Print the result
    cout << "\nMatrix after sorting rows: \n";
    print(matrix, rows, cols);

    cout << "\n\n";
    return 0;
}

void enter(float matrix[][MAX_SIZE], int& rows, int& cols) {
    do {
        cout << "\nEnter the number of row(1 <= rows <= " << MAX_SIZE << "): ";
        cin >> rows;

        if (rows < 1
        || rows > MAX_SIZE) {
            cout << "\nInvalid rows! Please try again (rows must be between 1 and " << MAX_SIZE << ").";
        }
    }while (rows < 1 || rows > MAX_SIZE);

    do {
        cout << "\nEnter the number of col(1 <= cols <= " << MAX_SIZE << "): ";
        cin >> cols;

        if (cols < 1
        || cols > MAX_SIZE) {
            cout << "\nInvalid cols! Please try again (cols must be between 1 and " << MAX_SIZE << ").";
        }
    }while (cols < 1 || cols > MAX_SIZE);

    cout << "\nEnter matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            while (true) {
                cout << " Enter a[" << i << "][" << j << "]: ";

                if (cin >> matrix[i][j]) {
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

void print(float matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void quickSort(float a[], int left, int right) {
    if (left >= right) {
        return;
    }

    float pivot = a[(left + right) / 2];

    int i = left;
    int j = right;

    while (i <= j) {
        while (a[i] < pivot) {
            i++; // Find the incorrect position
        }

        while (a[j] > pivot) {
            j--; // Find the incorrect position
        }

        if (i <= j) {
            float temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }

    // Recursively sort the two partitions
    if (left < j) {
        quickSort(a, left, j);
    }

    if (i < right) {
        quickSort(a, i, right);
    }
}

void sortRowOfMatrix(float matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        quickSort(matrix[i], 0, cols - 1);
    }
}
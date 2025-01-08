#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void enter(int a[][MAX_SIZE], int& rows, int& cols);
void print(int a[][MAX_SIZE], int rows, int cols);
bool checkPrime(int num);
int findRowsWithMostPrimeNumbers(int a[][MAX_SIZE], int rows, int cols, int rowsWithMostPrimes[], int& maxPrimeCount);

int main() {
    cout << "\n\nWorking with matrix.";

    int a[MAX_SIZE][MAX_SIZE];

    int rows = 0;
    int cols = 0;

    // Enter matrix
    enter(a, rows, cols);

    // Print matrix
    cout << "\nOriginal matrix: \n";
    print(a, rows, cols);

    // find the rows with the most prime numbers
    int rowsWithMostPrimes[MAX_SIZE];
    int maxPrimeCount = 0;
    int numRows = findRowsWithMostPrimeNumbers(a, rows, cols, rowsWithMostPrimes, maxPrimeCount);

    // print result
    if (maxPrimeCount == 0) {
        cout << "\nThere aren't any prime numbers in the matrix.";
    }else {
        cout << "\nThe highest number of prime numbers in a single row: " << maxPrimeCount;
        cout << "\nRows with the most prime numbers: ";

        for (int i = 0; i < numRows; i++) {
            cout << rowsWithMostPrimes[i] + 1 << " ";
        }
    }

    cout << "\n\n";
    return 0;
}

void enter(int a[][MAX_SIZE], int& rows, int& cols) {
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
        for (int j= 0; j < cols; j++) {
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

bool checkPrime(int num) {
    if (num < 2) {
        return false;
    }

    if (num == 2) {
        return true;
    }

    if (num % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int findRowsWithMostPrimeNumbers(int a[][MAX_SIZE], int rows, int cols, int rowsWithMostPrimes[], int& maxPrimeCount) {
    maxPrimeCount = 0;
    int numRows = 0;

    for (int i = 0; i < rows; i++) {
        int currentPrimeCount = 0;

        for (int j = 0; j < cols; j++) {
            bool isPrime = checkPrime(a[i][j]);

            if (isPrime) {
                currentPrimeCount++;
            }
        }

        if (currentPrimeCount > maxPrimeCount) {
            maxPrimeCount = currentPrimeCount;
            numRows = 0;
            rowsWithMostPrimes[numRows] = i;
            numRows++;
        }else if (currentPrimeCount == maxPrimeCount) {
            rowsWithMostPrimes[numRows] = i;
            numRows++;
        }
    }

    return numRows;
}
// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

// Helper: read an M x N matrix from the user
void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Helper: display a matrix in a neat aligned grid
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl;
    }
}

// PART A — Transpose a matrix
void transposeMatrix(int mat[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = mat[i][j];
        }
    }
}

// PART B — Add two matrices (same size)
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C — Multiply two matrices (A is M x N, B is N x P → result is M x P)
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX],
                      int m, int n, int p, int result[MAX][MAX]) {
    // Initialize result to zero
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "===== Matrix Operations =====" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        // ---------- PART A ----------
        int mat[MAX][MAX], trans[MAX][MAX];
        int rows, cols;

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter the matrix elements:" << endl;
        readMatrix(mat, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(mat, rows, cols);

        transposeMatrix(mat, rows, cols, trans);

        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(trans, cols, rows);   // rows and cols are swapped

    } else if (choice == 2) {
        // ---------- PART B ----------
        int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX];
        int rows, cols;

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter elements of first matrix:" << endl;
        readMatrix(a, rows, cols);

        cout << "\nEnter elements of second matrix:" << endl;
        readMatrix(b, rows, cols);

        cout << "\nFirst Matrix:" << endl;
        displayMatrix(a, rows, cols);

        cout << "\nSecond Matrix:" << endl;
        displayMatrix(b, rows, cols);

        addMatrices(a, b, rows, cols, sum);

        cout << "\nSum of the two matrices:" << endl;
        displayMatrix(sum, rows, cols);

    } else if (choice == 3) {
        // ---------- PART C ----------
        int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX];
        int m, n, p;

        cout << "\nEnter rows of Matrix A (M): ";
        cin >> m;
        cout << "Enter columns of Matrix A / rows of Matrix B (N): ";
        cin >> n;
        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        cout << "\nEnter elements of Matrix A (" << m << " x " << n << "):" << endl;
        readMatrix(a, m, n);

        cout << "\nEnter elements of Matrix B (" << n << " x " << p << "):" << endl;
        readMatrix(b, n, p);

        cout << "\nMatrix A:" << endl;
        displayMatrix(a, m, n);

        cout << "\nMatrix B:" << endl;
        displayMatrix(b, n, p);

        multiplyMatrices(a, b, m, n, p, product);

        cout << "\nProduct Matrix (A x B):" << endl;
        displayMatrix(product, m, p);

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}


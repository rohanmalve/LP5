
// MAT x VECTOR

#include <iostream>
#include <omp.h>

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void matrixVectorMultiplication(int matrix[MAX_ROWS][MAX_COLS], int vector[MAX_COLS], int result[MAX_ROWS], int rows, int cols) {
    #pragma omp parallel for
    for (int i = 0; i < rows; ++i) {
        result[i] = 0;
        for (int j = 0; j < cols; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int vector[MAX_COLS];
    int result[MAX_ROWS];
    int rows, cols;

    // Read matrix dimensions
    std::cout << "Enter the number of rows in the matrix: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns in the matrix: ";
    std::cin >> cols;

    // Read matrix elements
    std::cout << "Enter the elements of the matrix: \n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Read vector elements
    std::cout << "Enter the elements of the vector: \n";
    for (int i = 0; i < cols; ++i) {
        std::cin >> vector[i];
    }

    // Perform matrix-vector multiplication
    matrixVectorMultiplication(matrix, vector, result, rows, cols);

    // Display the result
    std::cout << "Result: ";
    for (int i = 0; i < rows; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

//SIZE OF MATRIX
#define SIZE 400

//MATRIX MULTIPLICATION OPERATION
void matrixMultiply(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

//TAKING RANDOM INPUTS
void fillMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    fillMatrix(A);
    fillMatrix(B);

    //TIME TAKEN CALCULATION
    double start = omp_get_wtime();
    matrixMultiply(A, B, C);
    double end = omp_get_wtime();

    // RESULT
    printf("OpenMP Parallel Matrix Multiplication Time: %lf seconds\n", end - start);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//SIZE OF MATRIX
#define SIZE 400


//MATRIX MULTIPLICATION OPERATION
void matrixMultiply(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
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
    clock_t start = clock();
    matrixMultiply(A, B, C);
    clock_t end = clock();

    // RESULT
    printf("Serial Matrix Multiplication Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

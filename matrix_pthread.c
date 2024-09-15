#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//SIZE OF MATRIX
#define SIZE 500
#define NUM_THREADS 4

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

typedef struct {
    int thread_id;
    int num_threads;
} thread_data;

//MATRIX MULTIPLICATION OPERATION
void* matrixMultiply(void* arg) {
    thread_data* data = (thread_data*)arg;
    int thread_id = data->thread_id;
    int num_threads = data->num_threads;

    int rows_per_thread = SIZE / num_threads;
    int start_row = thread_id * rows_per_thread;
    int end_row = (thread_id + 1) * rows_per_thread;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    pthread_exit(NULL);
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
    pthread_t threads[NUM_THREADS];
    thread_data thread_data_array[NUM_THREADS];

    fillMatrix(A);
    fillMatrix(B);

    //TIME TAKEN CALCULATION
    clock_t start = clock();

    for (int t = 0; t < NUM_THREADS; t++) {
        thread_data_array[t].thread_id = t;
        thread_data_array[t].num_threads = NUM_THREADS;
        pthread_create(&threads[t], NULL, matrixMultiply, (void*)&thread_data_array[t]);
    }

    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    clock_t end = clock();

    // RESULT
    printf("pthread Parallel Matrix Multiplication Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

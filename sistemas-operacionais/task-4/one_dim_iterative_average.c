#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


#include "one_dim_iterative_average.h"

#define N 10

long numThreads, numIterations;
long double old[N], new[N];
long slice;

static pthread_barrier_t barrier;

static void * Thread(void * data) {
    long tid = *((long *) data);
    long startIdx = tid * slice + 1;
    long endIdx = startIdx + slice - 1;
    endIdx = endIdx > (N - 2) ? N - 2 : endIdx;

    for (long x=0; x < numIterations; x++) {
        solveSlice(old, new, startIdx, endIdx);

        int s = pthread_barrier_wait(&barrier);

        if (s == PTHREAD_BARRIER_SERIAL_THREAD) {
            swapVectors(old, new, N);
        
        } else if (s == 0) {

        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("You must inform the number of threads and iterations!\n");
        printf("Usage: %s <num-threads> <num-iterations>\n", argv[0]);

        return 1;
    }

    for (long i=0; i < N; i++) {
        old[i] = 0;
        new[i] = 0;
    }

    old[N - 1] = 1;
    new[N - 1] = 1;


    numThreads = atoi(argv[1]);
    numIterations = atoi(argv[2]);

    pthread_t tid[numThreads];
    long threadIds[numThreads];
    int s = pthread_barrier_init(&barrier, NULL, numThreads);

    for (long i=0; i < numThreads; i++) {
        threadIds[i] = i;
    }

    // Calculate slice size
    slice = ceil((double) (N - 2) / (double) numThreads);

    // Compute average
    for (long idx=0; idx < numThreads; idx++) {
        pthread_create(&tid[idx], NULL, Thread, (void *) &threadIds[idx]);
    }
    
    for (long idx = 0; idx < numThreads; idx++) {
        pthread_join(tid[idx], NULL);
    }


    for (long i=0; i < N; i++) {
        printf("%Lf, ", new[i]);
    }
    printf("\n");

    return 0;
}

// 
void swapVectors(long double *vectorA, long double *vectorB, long size) {
    long double temp[size];
    for (long i=0; i < size; i++) {
        temp[i] = vectorA[i];
        vectorA[i] = vectorB[i];
        vectorB[i] = temp[i];
    }
}

//
void solveSlice(long double *old, long double *new, long startIdx, long endIdx) {
    for (long i=startIdx; i <= endIdx; i++) {
        new[i] = (old[i - 1] + old[i + 1]) / 2.0;
    }
}
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "utils.h"


#define MAX 10

int globalCounter = 0;
pthread_mutex_t countMutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  countCondition = PTHREAD_COND_INITIALIZER;

// Definition
void * thread1(void * data);
void * thread2(void * data);
void * thread3(void * data);


// Implementation
void * thread1(void * data) {
    while (1) {
        pthread_mutex_lock(&countMutex);
        
        if (globalCounter >= MAX) {
            pthread_mutex_unlock(&countMutex);
            pthread_cond_signal(&countCondition);
            break;
        }

        if (globalCounter % 3 != 0) {
            pthread_mutex_unlock(&countMutex);
            pthread_cond_signal(&countCondition);
        
        } else {
            printf(RED_BOLD "Thread 1: " RESET "%d\n", ++globalCounter);
            msleep(500);
            pthread_mutex_unlock(&countMutex);
        }
    }

    return NULL;
}

void * thread2(void * data) {
    while (1) {
        pthread_mutex_lock(&countMutex);
        pthread_cond_wait(&countCondition, &countMutex);

        if (globalCounter >= MAX) {
            pthread_mutex_unlock(&countMutex);
            break;
        }

        if (globalCounter % 3 != 1) {
            pthread_mutex_unlock(&countMutex);

        } else {
            printf(GREEN_BOLD "Thread 2: " RESET "%d\n", ++globalCounter);
            msleep(500);
            pthread_mutex_unlock(&countMutex);
        }
    }

    return NULL;
}

void * thread3(void * data) {
    while (1) {        
        pthread_mutex_lock(&countMutex);
        pthread_cond_wait(&countCondition, &countMutex);

        if (globalCounter >= MAX) {
            pthread_mutex_unlock(&countMutex);
            break;
        }

        if (globalCounter % 3 != 2) {
            pthread_mutex_unlock(&countMutex);

        } else {
            printf(BLUE_BOLD "Thread 3: " RESET "%d\n", ++globalCounter);
            msleep(500);
            pthread_mutex_unlock(&countMutex);
        }
    }

    return NULL;
}

int main(int argc, char const *argv[]) {
    pthread_t countThreads[3];

    // init

    pthread_create(
        &countThreads[0],
        NULL,
        thread1,
        NULL
    );

    pthread_create(
        &countThreads[1],
        NULL,
        thread2,
        NULL
    );

    pthread_create(
        &countThreads[2],
        NULL,
        thread3,
        NULL
    );

    // join threads
    for (int i=0; i < 3; i++) {
        pthread_join(countThreads[i], NULL);
    }

    printf(WHITE_BOLD "FINAL COUNT: " RESET "%d\n", globalCounter);

    return 0;
}

#include <pthread.h>
#include <semaphore.h>      
#include <stdio.h>
#include "utils.h"

#define MAX 10


int globalCounter = 0;
pthread_mutex_t countMutex = PTHREAD_MUTEX_INITIALIZER;
sem_t countSemaphores[3];


void * thread1(void * data);
void * thread2(void * data);
void * thread3(void * data);



void * thread1(void * data) {
    while (1) {
        sem_wait(&countSemaphores[0]);
        
        pthread_mutex_lock(&countMutex);
        if (globalCounter < MAX) {
            printf(RED_BOLD "Thread 1: " RESET "%d\n", ++globalCounter);
            pthread_mutex_unlock(&countMutex);
        } else {
            pthread_mutex_unlock(&countMutex);
            sem_post(&countSemaphores[1]);

            break;
        }

        msleep(500);

        sem_post(&countSemaphores[1]);
    }

    return NULL;
}

void * thread2(void * data) {
    while (1) {
        sem_wait(&countSemaphores[1]);

        pthread_mutex_lock(&countMutex);
        if (globalCounter < MAX) {
            printf(GREEN_BOLD "Thread 2: " RESET "%d\n", ++globalCounter);
            pthread_mutex_unlock(&countMutex);
        } else {
            pthread_mutex_unlock(&countMutex);
            sem_post(&countSemaphores[2]);
            
            break;
        }

        msleep(500);

        sem_post(&countSemaphores[2]);
    }

    return NULL;
}

void * thread3(void * data) {
    while (1) {        
        sem_wait(&countSemaphores[2]);
        
        pthread_mutex_lock(&countMutex);
        if (globalCounter < MAX) {
            printf(BLUE_BOLD "Thread 3: " RESET "%d\n", ++globalCounter);
            pthread_mutex_unlock(&countMutex);
        } else {
            pthread_mutex_unlock(&countMutex);
            sem_post(&countSemaphores[0]);
            break;
        }

        msleep(500);

        sem_post(&countSemaphores[0]);
    }

    return NULL;
}

// Semaphore used to tell which thread should execute.

int main(int argc, char const *argv[]) {
    pthread_t countThreads[3];

    // init
    for (int i=0; i < 3; i++) {
        sem_init(&countSemaphores[i], 0, 0);
    }
    sem_init(&countSemaphores[0], 0, 1);

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

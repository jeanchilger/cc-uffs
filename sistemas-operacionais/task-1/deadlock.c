#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED     "\e[0;31m"
#define RED_BOLD "\e[1;91m"
#define GREEN   "\e[0;32m"
#define GREEN_BOLD "\e[1;92m"
#define RESET   "\e[0m"

void *thread1(void *data);
void *thread2(void *data);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_t Thread1, Thread2;

int main(void) {
    pthread_create(&Thread1, NULL, thread1, NULL);
    pthread_create(&Thread2, NULL, thread2, NULL);

    // now join them
    pthread_join(Thread1, NULL);
    printf(GREEN "THREAD 1 id %ld returned\n" RESET, Thread1);

    pthread_join(Thread2, NULL);
    printf(RED "THREAD 2 id %ld returned\n" RESET, Thread2);

    return 1;
}

void *thread1(void *data) {
    unsigned long i, j;

    while (1) {
        if (pthread_mutex_trylock(&mutex1) == 0) {
            printf(GREEN "THREAD 1 (%ld) " RESET "got mutex1.\n", pthread_self());

            // Just for wasting some time
            printf("\tWait...\n");
            sleep(2);

            if (pthread_mutex_lock(&mutex2) == 0) {
                printf(GREEN "THREAD 1 (%ld) " RESET "got mutex2.\n", pthread_self());

                // Just for wasting some time
                printf("\tWait...\n");
                sleep(2);

                printf(RED "THREAD 1 (%ld) " RESET "consumed both.\n", pthread_self());

                pthread_mutex_unlock(&mutex2);
                pthread_mutex_unlock(&mutex1);
                
                break;

            } else {
                printf(GREEN "THREAD 1 (%ld) " RESET "did not get mutex2.\n", pthread_self());
                pthread_mutex_unlock(&mutex1);
            }

        } else {
            printf(GREEN "THREAD 1 (%ld) " RESET "did not get mutex1.\n", pthread_self());
        }
    }

    printf(GREEN_BOLD "THREAD 1 (%ld) COMPLETE.\n" RESET, pthread_self());

    pthread_exit(NULL);
}

void *thread2(void *data) {
    unsigned long i, j;

    while (1) {
        if (pthread_mutex_lock(&mutex2) == 0) {
            printf(RED "THREAD 2 (%ld) " RESET "got mutex2.\n", pthread_self());

            // Just for wasting some time
            printf("\tWait...\n");
            sleep(2);

            if (pthread_mutex_trylock(&mutex1) == 0) {
                printf(RED "THREAD 2 (%ld) " RESET "got mutex1.\n", pthread_self());

                // Just for wasting some time
                printf("\tWait...\n");
                sleep(2);

                printf(RED "THREAD 2 (%ld) " RESET "consumed both.\n", pthread_self());

                pthread_mutex_unlock(&mutex1);
                pthread_mutex_unlock(&mutex2);

                break;

            } else {
                printf(RED "THREAD 2 (%ld) " RESET "did not get mutex1.\n", pthread_self());
                pthread_mutex_unlock(&mutex2);
                sleep(2);

            }

        } else {
            printf(RED "THREAD 2 (%ld) " RESET "did not get mutex2.\n", pthread_self());
        }
    }

    printf(RED_BOLD "THREAD 2 (%ld) COMPLETE.\n" RESET, pthread_self());
    
    pthread_exit(NULL);
}

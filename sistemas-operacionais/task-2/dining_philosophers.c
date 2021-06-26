#include "dining_philosophers.h"

void * philosopherCycle(void *data) {
    int philosopherId = *((int *) data);
    int countCycles = 0;

    while (1) {
        eat(philosopherId);
        
        think(philosopherId);

        countCycles++;

        if (CYCLES > 0 && countCycles == CYCLES) {
            break;
        }
    }

    pthread_exit(NULL);
}

// Utility functions to fork acquisition.
//
int leftPhilosopher(int philosopherId) {
    return (philosopherId + N - 1) % N;
}

int rightPhilosopher(int philosopherId) {
    return (philosopherId + 1) % N;
}

void checkNeighbors(int philosopherId) {
    if (state[philosopherId] == HUNGRY &&
        state[leftPhilosopher(philosopherId)] != EATING &&
        state[rightPhilosopher(philosopherId)] != EATING
    ) {
        state[philosopherId] = EATING;
        printf(
            "Philosopher " WHITE_BOLD "%d " RESET "is" GREEN_BOLD " EATING\n\n" RESET,
            philosopherId
        );

        sem_post(&philosophers[philosopherId]);
    }
}

void getForks(int philosopherId) {
    sem_wait(&changeState);

    state[philosopherId] = HUNGRY;
    printf(
        "Philosopher " WHITE_BOLD "%d " RESET "is" RED_BOLD " HUNGRY\n" RESET,
        philosopherId
    );

    // Check if philosopher may eat based on neighbors' states
    checkNeighbors(philosopherId);

    sem_post(&changeState);

    // If philosopher couldn't eat, this down operation will set
    // his semaphore to 0.
    sem_wait(&philosophers[philosopherId]);
}

void putForks(int philosopherId) {
    sem_wait(&changeState);

    state[philosopherId] = THINKING;
    printf(
        "Philosopher " WHITE_BOLD "%d " RESET "is" BLUE_BOLD " THINKING\n" RESET,
        philosopherId
    );

    // Since `philosopherId` just ended eating, if any of his
    // neighbors are HUNGRY (and need only one of the forks 
    // used by `philosopherId`) the fork will be given to him.
    checkNeighbors(rightPhilosopher(philosopherId));
    checkNeighbors(leftPhilosopher(philosopherId));
    
    sem_post(&changeState);
}

// Phlosopher's cycle actions
//
void eat(int philosopherId) {

    // sleep(1);

    getForks(philosopherId);

    sleep(1);

    putForks(philosopherId);

    sleep(1);
}

void think(int philosopherId) {
    sleep(1);
}

int main() {
    pthread_t philosopherThreads[N];
    int philosopherIds[N];
    
    sem_init(&changeState, 0, 1);

    for (int i=0; i < N; i++) {
        sem_init(&philosophers[i], 0, 0);
        state[i] = THINKING;
        philosopherIds[i] = i;
    }

    // Initializes philosophers' life cycles.
    for (int i=0; i < N; i++) {
        pthread_create(
            &philosopherThreads[i],
            NULL,
            philosopherCycle,
            (void *)&philosopherIds[i]
        );
    }

    // Join threads
    for (int i=0; i < N; i++) {
        pthread_join(philosopherThreads[i], NULL);
    }

    return 0;
}
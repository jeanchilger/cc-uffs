//
// Exec:
//     gcc -o philosophers dining_philosophers.c -lpthread && ./philosophers 

#ifndef _H_DINING_PHILOSOPHERS_
#define _H_DINING_PHILOSOPHERS_

#include <pthread.h>
#include <semaphore.h>      
#include <stdio.h>
#include <unistd.h>

// Number of philosophers
#define N 5
// Number of cycles to be executed.
// Used a negative number for infinite cycles.
#define CYCLES 1

sem_t philosophers[N];
sem_t changeState;

enum {
    THINKING,
    EATING,
    HUNGRY
} state[N];

// Helpers for colorful printfs
#define RED          "\e[0;31m"
#define RED_BOLD     "\e[1;91m"
#define WHITE_BOLD   "\e[1;37m"
#define GREEN        "\e[0;32m"
#define GREEN_BOLD   "\e[1;92m"
#define BLUE_BOLD   "\e[1;94m"
#define RESET        "\e[0m"

/**
 * Represents a Philosopher's life cycle. 
 */
void * philosopherCycle(void *data);

/**
 * Phlosopher's cycle actions. Essentially, just a
 * sleep, to spend some time.
*/
void eat(int philosopherId);

void think(int philosopherId);

/**
 * Utility funcitons to obtain fork number based on
 * philosopher id.
 */
int leftPhilosopher(int philosopherId);

int rightPhilosopher(int philosopherId);

/**
 * Get both the forks for philosopher `philosopherId`. If only
 * one of them is available, set the philosopher as "HUNGRY".
 */
void getForks(int philosopherId);

/**
 * Put both forks on the table. If any neighboring philosopher
 * is "HUNGRY", the fork is given to him.
 */
void putForks(int philosopherId);

/**
 * Checks the states of `philosopherId`'s neighbors.
 *
 * If `philosopherId` is HUNGRY and it's neighbors are not
 * eating, then he may eat (e.g. the corresponding semaphore may
 * be "comsumed").
 */
void checkNeighbors(int philosopherId);

#endif
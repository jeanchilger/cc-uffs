#ifndef _H_UTILS_
#define _H_UTILS_

#include <time.h>
#include <errno.h>

// Helpers for colorful printfs
#define RED          "\e[0;31m"
#define RED_BOLD     "\e[1;91m"
#define WHITE_BOLD   "\e[1;37m"
#define GREEN        "\e[0;32m"
#define GREEN_BOLD   "\e[1;92m"
#define BLUE_BOLD   "\e[1;94m"
#define RESET        "\e[0m"

/*
 * Helper function to sleep the execution of
 * current thread for MSEC milliseconds.
 * 
 * Source: https://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds
 **/
int msleep(long msec);

#endif
#ifndef _H_ONE_DIM_ITERATIVE_AVERAGE_H_
#define _H_ONE_DIM_ITERATIVE_AVERAGE_H_

/*
 * Utility function for swapping 2 vectors.
 * The first and last positions are not changed.
 * */
void swapVectors(long double *vectorA, long double *vectorB, long size);

/*
 * Calculates the average for the given slice, 
 * starting at 'startIdx' and ending at 'endIdx'.
 * */
void solveSlice(long double *old, long double *new, long startIdx, long endIdx);

#endif
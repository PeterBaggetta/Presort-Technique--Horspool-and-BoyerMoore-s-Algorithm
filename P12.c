/* Assignment 3
* Pietro Baggetta
* 1092160
* March 14, 2022
* Question 1, Part 2 
*/

#include "myHeader.h"

/* This function swaps the elements to help sort the array */
void swap (int *x, int *y) {
    int temp = *x;

    *x = *y;
    *y = temp;
}

/* Used for sorting the arrays at the beginning */
void selectionSort (int array[40000], int size) {
    int i, j, min;

    /* Swap the minimum element with the first element in the array */
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap (&array[min], &array[i]);
    }
}

void P12 (int leftPoints[40000], int rightPoints[40000], int lines) {

    /* Sort the left points */
    selectionSort (leftPoints, lines);

    /* Sort the right points */
    selectionSort (rightPoints, lines);

    int totalLeft = 0, totalRight = 0, maxInterval = -99999, temp = 0, IntervalPoint;

    /* Go through from the smallest point to the largest point */
    for (int i = leftPoints[0]; i < rightPoints[lines - 1]; i++) {
        totalLeft = 0, totalRight = 0, temp = 0;
        /* Check how many points on the right of the leftPoints, and how many points on the left of the rightPoints */
        for (int j = 0; j < lines; j++) {
            if (i > leftPoints[j]) {
                totalLeft++;
            }
            if (i >= rightPoints[j]) {
                totalRight++;
            }
        }
        /* Check to see if the max interval has been found */
        temp = totalLeft - totalRight;
        if (maxInterval < temp) {
            maxInterval = temp;
            IntervalPoint = i;
        }
    }

    printf ("The maximum number of intervals: %d\n", maxInterval);
    printf ("The intervals include point: %d\n", IntervalPoint);
}

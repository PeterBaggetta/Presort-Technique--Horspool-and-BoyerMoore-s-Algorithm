/* Assignment 3
* Pietro Baggetta
* 1092160
* March 14, 2022
* Question 1, Part 1 
*/

#include "myHeader.h"

void P11 (int leftPoints[30000], int rightPoints[30000], int lines) {
    
    /* Find the leftmost point (smallest) */
    int smallest = 999999;

    for (int i = 0; i < lines; i++) {
        if (leftPoints[i] < smallest) {
            smallest = leftPoints[i];
        }
    }

    /* Find the rightmost point (biggest) */
    int largest = -999999;
    
    for (int i = 0; i < lines; i++) {
        if (rightPoints[i] > largest) {
            largest = rightPoints[i];
        }
    }

    /* Initialize the array to all zeros */
    int intervals[50000][2], k = 0;
    for (int i = 0; i < 50000; i++) {
        intervals[i][0] = 0;
        intervals[i][1] = 0;
    }

    /* Iterate through each number and keep track of the number of intervals that have the index */
    for (int i = smallest + 1; i < largest; i++) {
        intervals[k][0] = i;
        for (int j = 0; j < lines; j++) {
            if (i > leftPoints[j] && i < rightPoints[j]) {
                intervals[k][1] += 1;
            }
        }
        k++;
    }

    int maxInterval = -999999, IntervalPoint;
    /* Find the number that appears in most intervals */
    for (int i = 0; i < k; i++) {
        if (intervals[i][1] > maxInterval) {
            maxInterval = intervals[i][1];
            IntervalPoint = intervals[i][0];
        }
    }
    
    printf ("The maximum number of intervals: %d\n", maxInterval);
    printf ("The intervals include point: %d\n", IntervalPoint);
}

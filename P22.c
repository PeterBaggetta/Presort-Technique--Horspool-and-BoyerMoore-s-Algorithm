/* Assignment 3
* Pietro Baggetta
* 1092160
* March 14, 2022
* Question 2, Part 2 
* Citations
    * https://scanftree.com/programs/c/c-program-to-search-the-perticulur-pattern-in-the-string-using-horspool-method/
    * Inspiration was taken from this site to better understand and implement the Horspool Algorithm
    * TextBook
    * Class Lectures
*/

#include "myHeader.h"

int set (char c) {
    int value = 0;

    /* Check if the letter is a lower case or upper case and give the appropriate value
       I use the ASCII table to give and check the value */
    if (islower (c) != 0) {
        value = c - 'a';
    } else if (isupper (c) != 0) {
        value = c - 'A' + 26;
    } else {
        value = 52;
    }

    return value;
}

long *makeShiftTable (char *pattern, long patternLength) {
    long *shiftTable;

    /* Create room in memory for the table */
    shiftTable = (long *) malloc (53 * sizeof (long));

    /* Initialize table to be the length of the alphabet (upper and lower case included) */
    for (int i = 0; i < 53; i++) {
        shiftTable[i] = patternLength;
    }

    /* Set the shift table with the correct values */
    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable[set (pattern[i])] = patternLength - 1 - i;
    }

    return shiftTable;
}

void P22 (char *string, long stringLength, char *pattern, long patternLength) {

    long *shiftTable;
    int j;
    long occurrences = 0, numShifts = 0;

    /* Create the shift table used for Horspool's Algorithm */
    shiftTable = makeShiftTable (pattern, patternLength);

    int i = patternLength - 1;

    /* Loop through the entire text */
    while (i < stringLength) {
        j = 0;

        /* If the character matches increase counter */
        while (j <= patternLength - 1 && pattern[patternLength - 1 - j] == string[i - j]) {
            j++;
        }

        /* Pattern is found in the string of words from the text file */
        if (j == patternLength) {
            occurrences++;
            numShifts++;
            i += shiftTable[set (string[i])];
        } else {
            /* No match found, increase pointers */
            numShifts++;
            i += shiftTable[set (string[i])];
        }
    }

    printf ("The number of occurrences for %s: %ld\n", pattern, occurrences);
    printf ("The number of shifts taken by algorithm: %ld\n", numShifts);
}

/* Assignment 3
* Pietro Baggetta
* 1092160
* March 14, 2022
* Question 2, Part 1
*/

#include "myHeader.h"

void P21 (char *string, long stringLength, char *pattern, long patternLength) {

    long i;
    long occurrences = 0, numShifts = 0;
    
    char *section = (char *) malloc (patternLength * sizeof (char));
    long sectionLength = patternLength;

    /* Search through the string/file for the pattern */
    for (i = 0; i < stringLength; i++) {
        strncpy (section, &string[i], patternLength);
        section[sectionLength] = '\0';

        /* If a patter is found increase the number of occurences */
        if (strcmp (section, pattern) == 0) {
            occurrences++;
        }
        numShifts++;
    }

    printf ("The number of occurrences for %s: %ld\n", pattern, occurrences);
    printf ("The number of shifts taken by algorithm: %ld\n", numShifts);
}

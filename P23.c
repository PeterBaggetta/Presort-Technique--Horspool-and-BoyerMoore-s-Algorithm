/* Assignment 3
* Pietro Baggetta
* 1092160
* March 14, 2022
* Question 2, Part 3
* Citations
    * https://www.geeksforgeeks.org/boyer-moore-algorithm-good-suffix-heuristic/
    * Inspiration was taken from this site to better understand and implement the Boyer-Moore Algorithm
    * TextBook
    * Class Lectures
*/

#include "myHeader.h"

long calculateD2 (char *pattern, long patternLength, long k) {
    long i, max = 0, d2 = 0;

    /* Create room in memory for section */
    char *section = (char *) malloc (k * sizeof (char));

    /* Define k suffix */
    char *suffix = (char *) malloc (k * sizeof (char));
    long suffixLength = k;
    strncpy (suffix, &pattern[patternLength - k], k);
    suffix[k] = '\0';

    /* Move section from right to the left */
    for (i = (patternLength - k - 1); i >= 0; i--) {
        d2++;
        strncpy (section, &pattern[i], k);
        section[k] = '\0';

        /* Check if section and suffix are the same (if yes return d2) */
        if (strcmp (section, suffix) == 0) {
            return d2;
        }
    }

    char *prefix = (char *) malloc (0);

    /* Check every suffix and prefix of size i between 1 and k */
    for (i = 1; i < k; i++) {
        /* Make suffix and prefix of size i */
        prefix = (char *) realloc (prefix, i * sizeof (char));
        suffix = (char *) realloc (suffix, i * sizeof (char));

        strncpy (prefix, pattern, i);
        strncpy (suffix, &pattern[patternLength - i], i);

        prefix[i] = '\0';
        suffix[i] = '\0';

        /* Check if suffix and prefix are the same */
        if (strcmp (prefix, suffix) == 0) {
            max = i;
        }
    }

    /* No suffix or prefix that matches */
    if (max == 0) {
        d2 = patternLength;
    } else {
        /* Suffix and/or prefix matches */
        d2 = patternLength - max;
    }

    return d2;
}

long *makeGoodSuffixTable (char *pattern, long patternLength) {
    long k, *goodSuffixTable;

    /* Create room in memory for the table */
    goodSuffixTable = (long *) malloc ((patternLength - 1) * sizeof (long));

    /* Find the appropriate d2 value for the current index */
    for (k = 0; k < patternLength; k++) {
        goodSuffixTable[k - 1] = calculateD2 (pattern, patternLength, k);
    }

    return goodSuffixTable;
}

void P23 (char *string, long stringLength, char *pattern, long patternLength) {

    long *goodSuffixTable, *badSymbolShiftTable;
    int j;
    long dUse, d1, d2;
    long occurrences = 0, numShifts = 0;

    /* Create the shift table and suffix table */
    goodSuffixTable = makeGoodSuffixTable (pattern, patternLength);
    badSymbolShiftTable = makeShiftTable (pattern, patternLength);

    int i = patternLength - 1;

    /* Loop through the entire text */
    while (i < stringLength) {
        j = 0;

        /* If the character matches increase counter */
        while (j <= patternLength - 1 && pattern[patternLength - 1 - j] == string[i - j]) {
            j++;
        }

        /* If j >= 0, d1 comes from the table */
        if (badSymbolShiftTable[set (string[i - j])] - j > 1) {
            d1 = badSymbolShiftTable[set (string[i - j])] - j;
        } else {
            /* j !>= 0 therefore d1 is 1 to represent a positive integer */
            d1 = 1;
        }

        /* Get d2 from table if j > 0 */
        if (j > 0) {
            d2 = goodSuffixTable[j - 1];
        }

        /* Use d1 */
        if (j == 0) {
            dUse = d1;
        } else {
            /* Find the bigger number between d1 and d2 */
            if (d1 > d2) {
                dUse = d1;
            } else {
                dUse = d2;
            }
        }

        /* There is a match found between the text and the pattern */
        if (j == patternLength) {
            occurrences++;
            numShifts++;
            i += dUse;
        } else {
            /* No match found */
            numShifts++;
            i += dUse;
        }
    }

    printf ("The number of occurrences for %s: %ld\n", pattern, occurrences);
    printf ("The number of shifts taken by algorithm: %ld\n", numShifts);
}

/* Assignment 3
* Pietro Baggetta
* 1092160
* March 14, 2022
* Main File 
*/

#include "myHeader.h"

int main (int argc, char *argv[]) {

    int lines = 0, leftPoints[40000], rightPoints[40000];
    int lines2 = 0;
    double time1 = 0.0, time2 = 0.0, time3 = 0.0, time4 = 0.0, time5 = 0.0;
    char *string;

    printf ("*-------------------------------------------------------------------------------------------*\n");
    printf ("| Option 1: Find max intervals using Brute Force and Presort Technique.                     |\n");
    printf ("| Option 2: Search for string in text using Brute force, Horspool & Boyer-Moore's Algorithm.|\n");
    printf ("*-------------------------------------------------------------------------------------------*\n");
    
    printf ("\nChoose an option: ");
    int option;
    scanf ("%d", &option);

    if (option == 1) {
        printf ("Enter the name of the file: ");
        char fileName[200];
        scanf ("%s", fileName);

        FILE *file1 = fopen (fileName, "r");
        if (file1 == NULL) {
            printf ("ERROR opening file");
            exit (0);
        }

        /* Read in and set the array to be used */
        while ( (fscanf (file1, "%d    %d ", &leftPoints[lines], &rightPoints[lines])) != EOF) {
            lines++;
        }
        fclose (file1);

        /*********************************** Question 1 ***********************************/

        printf ("\n--------------- Question 1.1 / P11 ---------------\n\n");
        printf ("Brute force program for finding max number of intervals.\n\n");
        clock_t start1 = clock();               /* start the timer */

        P11 (leftPoints, rightPoints, lines);   /* run the program for Q1.1 */

        clock_t end1 = clock();
        time1 += (double)(end1 - start1) / CLOCKS_PER_SEC;  /* calculate time in seconds */

        printf ("Time for finding the maximum number: %f seconds\n", time1);


        printf ("\n--------------- Question 1.2 / P12 ---------------\n\n");
        printf ("A more efficient program for finding max number of intervals.\n\n");
        clock_t start2 = clock();               /* start the timer */

        P12 (leftPoints, rightPoints, lines);   /* run the program for Q1.1 */

        clock_t end2 = clock();
        time2 += (double)(end2 - start2) / CLOCKS_PER_SEC;  /* calculate time in seconds */

        printf ("Time for finding the maximum number: %f seconds\n", time2);

        printf ("\n");

    } else if (option == 2) {

        /* Open the second data file and store it into an array to be used */
        FILE *file2 = fopen ("data_A3_Q2.txt", "rb");
        if (file2 == NULL) {
            printf ("ERROR opening file2\n");
            exit (0);
        }

        /* Get number of bytes in file */
        fseek (file2, 0L, SEEK_END);
        long bytes = ftell (file2);

        /* Reset pointer to beginning of the file */
        fseek (file2, 0L, SEEK_SET);

        /* Get memory for storing the text */
        string = (char *) malloc (bytes * sizeof (char));
        if (string == NULL) {
            printf ("ERROR: Not enough memory\n");
            exit (0);
        }

        /* copy all of file to into the array */
        fread (string, sizeof (char), bytes, file2);
        fclose (file2);

        /*********************************** Question 2 ***********************************/
        char key[100], *pattern;
        printf ("\nEnter a pattern to search for. No spaces allowed.\nThe pattern entered will be used for the three different string search algorithms.\nSearch for: ");
        scanf ("%s", key);
        pattern = (char *) malloc (strlen (key) * sizeof (char));
        strcpy (pattern, key);

        printf ("\n--------------- Question 2.1 / P21 ---------------\n\n");
        printf ("A brute force algorithm to search for a string in text file.\n\n");

        clock_t start3 = clock();               /* start the timer */

        P21 (string, bytes, pattern, strlen(key));

        clock_t end3 = clock();
        time3 += (double)(end3 - start3) / CLOCKS_PER_SEC;  /* calculate time in seconds */

        printf ("Execution time = %f seconds\n", time3);

        printf ("\n--------------- Question 2.2 / P22 ---------------\n\n");
        printf ("Horspool's algorithm to search for a string in a text file.\n\n");

        clock_t start4 = clock();               /* start the timer */

        P22 (string, bytes, pattern, strlen(key));

        clock_t end4 = clock();
        time4 += (double)(end4 - start4) / CLOCKS_PER_SEC;  /* calculate time in seconds */

        printf ("Execution time = %f seconds\n", time4);

        printf ("\n--------------- Question 2.3 / P23 ---------------\n\n");
        printf ("Boyer-Moore's algorithm to search for a string in a text file.\n\n");
        clock_t start5 = clock();               /* start the timer */

        P23 (string, bytes, pattern, strlen(key));

        clock_t end5 = clock();
        time5 += (double)(end5 - start5) / CLOCKS_PER_SEC;  /* calculate time in seconds */

        printf ("Execution time = %f seconds\n", time5);

        fclose (file2);
        printf ("\n");

    } else {
        printf ("INVALID CHOICE\n");
        exit (0);
    }
    return 0;
}

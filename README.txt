Name:   Pietro Baggetta
ID:     1092160
CIS 3490 Assignment 3

To compile:
    - Type 'make all'.

To clean all object files and execuatbles:
    - Type 'make clean'.

To run the program:
    - First make sure the program is compiled with the command 'make all'.
    - Then run the program by typing './main'.

Before starting the program:
    - Ensure that there are two text files in the same directory as the main.c file, or else the
      program will not be able to execute.
    - data_A3_Q2.txt is a hardcoded file name into the program, so make sure for option 2, this
      file nameing is used.
    - Ensure the formatting of the option 1 text file is the same formatting as the text file 
      data_A3_Q1_1.txt or else the program will not run.

Program Files:
    - This program takes in two different sets of data, which it then computes and uses different
      algorithms to accomplish different tasks.

    - data_A3_Q1_1.txt  
        > This file contains two columns of numbers that span over 30,000 lines, that are not sorted
        > This file can be named anything, but it must be formatted so that the numbers only have
          four spaces between the two number of column 1 and 2, as well as a space before a new line
          character at the end of each line. (ie. "18534    37057 ")
    - data_A3_Q2.txt
        > This file contains a text that spans over 44050 lines. The name of this file must be the same
          as stated.

    - main.c
        > This C program file holds the main function which calls each respective algorithm depending if
          option 1 is chosen or option 2.

        > Option 1: Will prompt the user for a file name (the file must follow the same convention as
          data_A3_Q1_1.txt), and it will then proceed to then find the max interval of the data set using
          two different algorithms.

          - P11.c:
            > Contains the brute force algorithm that will find the max interval of the file that has
              been entered by the user. It will output the max number of intervals, and the interval number.

          - P12.c:
            > Contains a more efficient program due to the presorting technique. This program will find
              the max number of intervals and the interval number, by presorting the left and right points of
              each interval so that a simple calculation can be done.

        > Option 2: Will prompt the user to enter a word to be searched for that is case-sensitive, and must
          not contain any special characters. Only upper and lower case letters are allowed. The search will
          be done with three methods; brute force, Horspool's algorithm, and Boyer-Moore's algorithm.
          
          - P21.c: 
            > Contains the brute force algorithm that will find the number of occurences of the word that
              is entered by the user. This program will then output the number of occurences and number of shifts
              taken to go through the entire text. No special calculations or tables are used in this method.
           
          - P22.c: 
            > Contains Horspool's algorithm which will find the number of occurences of the word that is
              entered by the user. This algorithm uses a shift table which is created based on the word wanting
              to be found by the user. The table is then used to shift the pattern word by a certain amount to
              more efficiently find the number of occurences and use less shifts to go through the entire text.
          
          - P23.c: 
            > Contains Boyer-Moore's algorithm which will find the number of occurecnes of the word that is
              entered by the user. This algorithm uses the shift table like Horspool as well as a good suffix table.
              The suffix table gets the value of different patterns possible from the wanted word, and generates
              shift values to once again be more efficient. This is the most efficient algorithm of the three in
              regards to the number of shifts needed to scan the entire text, and execution time.

***************************************************** (2.4) *****************************************************
The following table is used to analyze the performance of the brute force and Horspool method for string search:

-------------------------------------------------------------------------------------------------------------------------------------------
|              | Brute force   |     Horspool    |   Brute Force /   |   Brute Force      |   Horspool         |  Brute Force / Horspool  |
|              | Run Time      |     Run Time    |   Horspool Run    |   Pattern Shifts   |   Pattern Shifts   |  Pattern Shift Raio      |
|              | (seconds)     |     (seconds)   |   Time Ratio      |                    |                    |                          |
|--------------|---------------|-----------------|-------------------|--------------------|--------------------|--------------------------|
| OAC          |   0.068898    |     0.014788    |       4.66        |      3296602       |      1105384       |          2.98            |
| History      |   0.071821    |     0.007722    |       9.30        |      3296602       |      559051        |          5.90            |
| Engineering  |   0.066175    |     0.005464    |       12.11       |      3296602       |      374724        |          8.80            |
| average      |   0.074335    |     0.007979    |       9.32        |      3296602       |      538344        |          6.12            |
| Amount       |   0.071612    |     0.008931    |       8.02        |      3296602       |      607556        |          5.43            |
| grand        |   0.070808    |     0.010563    |       6.70        |      3296602       |      732350        |          4.50            |
| Preference   |   0.067593    |     0.006000    |       11.27       |      3296602       |      395476        |          8.34            |
| apply        |   0.074657    |     0.009398    |       7.94        |      3296602       |      694493        |          4.75            |
| Graduating   |   0.069504    |     0.006170    |       11.26       |      3296602       |      436227        |          7.56            |
| Qualification|   0.067449    |     0.005194    |       12.99       |      3296602       |      328770        |          10.03           |
|--------------|---------------|-----------------|-------------------|--------------------|--------------------|--------------------------|
| Average      |               |                 |       9.36        |                    |                    |          6.44            |
-------------------------------------------------------------------------------------------------------------------------------------------

Analysis:

As seen by the table above, the brute force algorithm is about 9.36 times slower than the Horspool algorithm when comparing the execution times. 
Along with a slower execution time, mean that the number of shifts needed to execute the algorithm increases. The brute force algorithm has about 
6.44 times more shifts than the Horspool algorithm. Since this is the case, the more optimal algorithm to use in this case would be Horspool, since 
it takes less time to execute and performs the operation with less shifts, meaning it is more efficient.
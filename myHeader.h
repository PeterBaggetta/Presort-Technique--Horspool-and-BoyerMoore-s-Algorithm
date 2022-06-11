#ifndef _MYHEADER_H
#define _MYHEADER_H

/* Header files used in the program */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

/* Functions used in program */
void P11 (int leftPoints[40000], int rightPoints[40000], int lines);

void P12 (int leftPoints[40000], int rightPoints[40000], int lines);

void P21 (char *string, long stringLength, char *pattern, long patternLength);

int set (char c);
long *makeShiftTable (char *pattern, long patternLength);
void P22 (char *string, long stringLength, char *pattern, long patternLength);

long calculateD2 (char *pattern, long patternLength, long k);
long *makeGoodSuffixTable (char *pattern, long patternLength);
void P23 (char *string, long stringLength, char *pattern, long patternLength);

#endif

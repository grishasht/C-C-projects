#ifndef __Common_H__
#define __Common_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define p 2
#define n 15000
#define t 28 

int arr[p][n][n];
extern clock_t *res1, *res2, *res3, *res4;
int X, L, R, I;
int i, j, k;

void time_in (float a);
clock_t time_corr (clock_t *res);
clock_t end_1m(float a);
clock_t end_1s(float a);
clock_t end_2m(float a);
clock_t end_2s(float a);

#endif

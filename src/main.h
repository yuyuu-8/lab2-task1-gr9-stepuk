/* Author: Anastasiya Stepuk group 9 variant 29 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program calculates the number of days between 
two dates, considering leap years. */

/* Function to check if a year is a leap year */
int is_leap_year(int year);

/* Function to calculate the number of days in a year */
int days_since_1970(int day, int month, int year);

/* Function to calculate the number of days from 01.01.1970 to a given date */
int date_difference(int d1, int m1, int y1, int d2, int m2, int y2);

#endif /* MAIN_H */
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_leap_year(int year);
int days_since_1970(int day, int month, int year);
int date_difference(int d1, int m1, int y1, int d2, int m2, int y2);

#endif /* MAIN_H */
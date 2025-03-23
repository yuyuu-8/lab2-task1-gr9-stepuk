/* main.c */
#include <stdio.h>
#include "main.h"

const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_since_1970(int day, int month, int year) {
		if (year < 1970) return -1;

		int days = 0;

		for (int y = 1970; y < year; y++) {
				days += is_leap_year(y) ? 366 : 365;
		}

		for (int m = 1; m < month; m++) {
				days += days_in_month[m - 1];
				if (m == 2 && is_leap_year(year)) days += 1;
		}

		days += day - 1;

		return days;
}
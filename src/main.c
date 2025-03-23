/* Author: Anastasiya Stepuk group 9 variant 29 */
/* Program to calculate the number of days between two dates */

#include "main.h"

/* Array with the number of days in each month (normal year) */
const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_since_1970(int day, int month, int year) {
  if (year < 1970)
    return -1;

  int days = 0;

  for (int y = 1970; y < year; y++) {
    days += is_leap_year(y) ? 366 : 365;
  }

  for (int m = 1; m < month; m++) {
    days += days_in_month[m - 1];
    if (m == 2 && is_leap_year(year))
      days += 1;
  }

  days += day - 1;

  return days;
}

int date_difference(int d1, int m1, int y1, int d2, int m2, int y2) {
  int days1 = days_since_1970(d1, m1, y1);
  int days2 = days_since_1970(d2, m2, y2);
  if (days1 == -1 || days2 == -1)
    return -1;
  return abs(days2 - days1);
}

/* Main function */
int main(int argc, char *argv[]) {
  if (argc != 7) {
    fprintf(stderr, "Usage: %s day1 month1 year1 day2 month2 year2\n", argv[0]);
    return 1;
  }

  int d1 = atoi(argv[1]), m1 = atoi(argv[2]), y1 = atoi(argv[3]);
  int d2 = atoi(argv[4]), m2 = atoi(argv[5]), y2 = atoi(argv[6]);

  if (y1 < 1970 || y2 < 1970 || m1 < 1 || m1 > 12 || m2 < 1 || m2 > 12 ||
      d1 < 1 || d1 > 31 || d2 < 1 || d2 > 31) {
    fprintf(stderr, "Error: Invalid date.\n");
    return 1;
  }

  if ((m1 == 2 && d1 > 28 + is_leap_year(y1)) ||
      (m2 == 2 && d2 > 28 + is_leap_year(y2))) {
    fprintf(stderr, "Error: Invalid February date.\n");
    return 1;
  }

  if ((m1 != 2 && d1 > days_in_month[m1 - 1]) || (m2 != 2 &&d2 > days_in_month[m2 - 1])) {
    fprintf(stderr, "Error: Invalid date.\n");
    return 1;
  }

  int diff = date_difference(d1, m1, y1, d2, m2, y2);
  if (diff != -1) {
    printf("Days between: %d\n", diff);
  }
  return 0;
}

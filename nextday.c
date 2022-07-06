#include <stdio.h>
/* Computes the day following an entered date
 * but does not do any error checking
 * so always enter a valid date
 * line yyyy,mm,dd
 * 
 * John Selmys - 2007
 */

int isLeapYear(int year);
void nextday(int *, int *, int *);

int main() {
    int year, month, day;
    printf("Enter year,month,day separated by\n");
    printf("commas: eg. 2007,4,16 : ");
    scanf("%d,%d,%d", &year, &month, &day);
    printf("\nThe year is %d\nThe month is %d\nThe day is %d\n\n",
	   year, month, day);
    nextday(&year, &month, &day);
    printf("The year is %d\nThe month is %d\nThe day is %d\n\n",
	   year, month, day);
    return 0;
}

void nextday(int *y, int *m, int *d) {
    switch (*m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (*d < 31) {
                *d += 1;
            } else if (*m < 12) {
                *d = 1;
                *m += 1;
            } else {
                *d = 1;
                *m = 1;
                *y += 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (*d < 30) {
                *d += 1;
            } else if (*m < 12) {
                *d = 1;
                *m += 1;
            } else {
                *d = 1;
                *m = 1;
                *y += 1;
            }
            break;
        case 2:
            if (*d < (28 + isLeapYear(*y))) {
                *d += 1;
            } else {
                *d = 1;
                *m += 1;
            }
            break;
    }
    return;
}

int isLeapYear(int year) {
    int result = 0;
    if (year % 4 == 0) {
	if (year % 100 == 0)
	    if (year % 400 == 0)
		result = 1;
	    else;
	else
	    result = 1;
    }
    return result;
}

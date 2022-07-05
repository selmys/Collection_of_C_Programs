#include <stdio.h>
#include <stdbool.h>
/*
 * Determine if year is a leap year
 * John Selmys - 2007
 */
int main() {
	int year;
	bool result=false;
	printf("Please enter a year: ");
	scanf("%d",&year);
	if(year%4 == 0) {
		if(year%100 == 0)
			if(year%400 == 0)
				result=true;
			else ;
		else 
			result=true;
    }
	if(result)
		printf("%d is a leap year\n",year);
	else
		printf("%d is not a leap year\n",year);
} 

/* Drunkard's walk simulation 
 * works from a BASH terminal on Linux Mint
 * John Selmys
*/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
/*	X	Y
 *	1	0	0
 *	1	1	1
 *	1	-1	2
 *	-1	0	3
 *	-1	1	4
 *	-1	-1	5
 *	0	1	6
 *	0	-1	7
 */	
int main() {
	int i,d,x=40,y=12;
	// clear screen
	printf("\033[2J");
    // hide the cursor
    printf("\e[?25l");
    // initialize random number generator
    srand(time(0));
	for (i=0;i<100;i++) {
		printf("\033[%d;%df",y,x);
		printf(".");
		fflush(stdout);
		d=rand()%8;
		switch (d) {
			case 0: x++; 		break;	
			case 1: x++; y++; 	break;	
			case 2: x++; y--;	break;	
			case 3: x--; 		break;	
			case 4: x--; y++; 	break;	
			case 5: x--; y--; 	break;	
			case 6: y++; 		break;	
			case 7: y--; 		break;
		}
		// move to x and y (column, line)
		printf("\033[%d;%df",y,x);
		printf("*");
		fflush(stdout);
        // sleep for 100000 microseconds = 1/10 second
		usleep(100000);
	}
    // show the cursor
    printf("\e[?25h");
	return 0;
}

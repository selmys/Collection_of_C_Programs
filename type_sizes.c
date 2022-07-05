/*
* Print Sizes of C Types
*/
#include <stdio.h>
int main(void) {
        int *int_ptr;
        void *void_ptr;
        int (*funct_ptr)(void);
        printf("sizeof(char):         %ld bytes\n", sizeof(char));
        printf("sizeof(short):        %ld bytes\n", sizeof(short));
        printf("sizeof(int):          %ld bytes\n", sizeof(int));
        printf("sizeof(long):         %ld bytes\n", sizeof(long));
        printf("sizeof(long long):    %ld bytes\n", sizeof(long long));
        printf("------------------------------\n");
        printf("sizeof(float):        %ld bytes\n", sizeof(float));
        printf("sizeof(double):       %ld bytes\n", sizeof(double));
        printf("sizeof(long double):  %ld bytes\n", sizeof(long double));
        printf("------------------------------\n");
        printf("sizeof(*int_ptr):     %ld bytes\n", sizeof(int_ptr));
        printf("sizeof(*void_ptr):    %ld bytes\n", sizeof(void_ptr));
        printf("sizeof(*funct_ptr):   %ld bytes\n", sizeof(funct_ptr));
        return 0;
}

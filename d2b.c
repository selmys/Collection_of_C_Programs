/* Convert a fractional decimal number 
 * into binary
 * John Selmys
*/
#include <stdio.h>
#include <unistd.h>
#define FIRST 0.0000000000000
#define LAST  0.9999999999999 
int main() {
    float n;
    setbuf(stdout,NULL);
    printf("Enter a fraction from %f to %f: ",FIRST,LAST);
    scanf("%f",&n);
    while(n < FIRST || n > LAST) {
        printf("Enter a fraction from %f to %f: ",FIRST,LAST);
        scanf("%f",&n);
    }
    printf("."); // add a leading decimal to the output
    while(n>0.0) {
        n=n*2.0;
        if(n>=1.0) {
            printf("1");
            n=n-(int)n; // n becomes a fraction .xxx
        } else {
            printf("0");
        }
        sleep(0.1);
    }
    printf("\n");
    return 0;
}

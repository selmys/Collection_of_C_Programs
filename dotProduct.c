#include <stdio.h>
#include <stdlib.h>
/* 
 * Dot product using pointers
 * John Selmys - Seneca College
 *
 */

int  dotProd(int *A, int *B, int n);
void print(int *p, int n, char a);
void input(int *p, int n, char a);

int main(){
    int len; 
    printf("Enter length of vectors A and B <length>: ");
    scanf("%d",&len);
    int *A = malloc(4*len);
    int *B = malloc(4*len);
    input(A,len,'A');
    input(B,len,'B');
    print(A,len,'A');
    print(B,len,'B');
    printf("The dot product is %d\n",dotProd(A,B,len));
    free(A);
    free(B);
    return 0;
};
int dotProd(int *A, int *B, int len){
    int i,sum=0;
    for(i=0;i<len;i++)
        sum += *(A+i) * *(B+i);
    return sum;
};
void print(int *p, int len, char a){
    int i;
    printf("====== %c =======\n",a);
    for(i=0;i<len;i++)
        printf("%4d",*(p+i));
    printf("\n");
    return;
};
void input(int *p, int len, char a){
    int i;
    printf("Enter %c row: ",a); 
    for(i=0;i<len;i++)
        scanf("%d",p+i);
    return;
};

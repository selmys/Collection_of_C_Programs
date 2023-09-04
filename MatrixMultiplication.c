#include <stdio.h>
#include <stdlib.h>
/* 
 * Matrix multiplication using pointers
 * John Selmys - Seneca College
 *
 */

int * multAxB(int *A, int *B, int ai, int aj, int bi, int bj);
void print(int *p,int r,int c,char a);
void input(int *p,int r,int c,char a);

int main(){
    int ai,aj,bi,bj;
    printf("Enter dimensions of array A <row col>: ");
    scanf("%d %d",&ai,&aj);
    printf("Enter dimensions of array B <row col>: ");
    scanf("%d %d",&bi,&bj);
    // check if aj == bi
    if(aj != bi){
        printf("A and B are incompatible!\n");
        return 0;
    }
    int *A = malloc(4*ai*aj);
    int *B = malloc(4*bi*bj);
    int *C = calloc(ai*bj,4);
    input(A,ai,aj,'A');
    input(B,bi,bj,'B');
    print(A,ai,aj,'A');
    print(B,bi,bj,'B');
    C = multAxB(A,B,ai,aj,bi,bj);
    print(C,ai,bj,'C');
    free(A);
    free(B);
    free(C);
    return 0;
};
int * multAxB(int *A, int *B, int ai, int aj, int bi, int bj){
    int *C=calloc(ai*bj,4);
    int i,j,k;
    for(i=0;i<ai;i++)      
        for(j=0;j<bj;j++){  
            int sum = 0; 
            for(k=0;k<aj;k++)
                sum += *(A+i*bi+k) * *(B+k*bj+j);
            *(C+i*bj+j) = sum;
        }
    return C;
};
void print(int *p,int r,int c,char a){
    int i,j;
    printf("====== %c =======\n",a);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%4d ",*(p+i*c+j));
        printf("\n");
    }
    return;
};
void input(int *p,int r,int c,char a){
    int i,j;
    for(i=0;i<r;i++){
        printf("Enter %c row %d\n",a,i); 
        for(j=0;j<c;j++) 
           scanf("%d",p+i*c+j);
    }
    return;
};

/*
 * Determinant of a 3x3 Integer Matrix
 *
 * John Selmys - Feb 2023
 *
 */
#include <stdio.h>

int det(int m[3][3]){
    int d=0;
    int a=m[0][0];
    d=a*(m[1][1]*m[2][2] - m[2][1]*m[1][2]);
    int b=m[0][1];
    d=d-b*(m[1][0]*m[2][2] - m[2][0]*m[1][2]);
    int c=m[0][2];
    d=d+c*(m[1][0]*m[2][1] - m[2][0]*m[1][1]);
    return d;
}

int main(){
   int m[3][3] = {{0}};
   for(int row=0;row<3;row++){
       printf("Enter row %d here: ",row+1);
       for(int col=0;col<3;col++)
           scanf("%d",&m[row][col]);
   }
   printf("The determinant of\n");
   for(int row=0;row<3;row++){
       for(int col=0;col<3;col++)
           printf("\t%d",m[row][col]);
       printf("\n");
   }
   printf("is %d\n",det(m));
   return 0;
}

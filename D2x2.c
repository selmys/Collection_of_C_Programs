/*
 * Determinant of a 2x2 Integer Matrix
 *
 * John Selmys - Feb 2023
 *
 */
#include <stdio.h>

int det(int m[2][2]){
    return m[0][0]*m[1][1] - m[0][1]*m[1][0];
}

int main(){
   int m[2][2] = {{0}};
   for(int row=0;row<2;row++){
       printf("Enter row %d here: ",row+1);
       for(int col=0;col<2;col++)
           scanf("%d",&m[row][col]);
   }
   printf("The determinant of\n");
   for(int row=0;row<2;row++){
       for(int col=0;col<2;col++)
           printf("\t%d",m[row][col]);
       printf("\n");
   }
   printf("is %d\n",det(m));
   return 0;
}

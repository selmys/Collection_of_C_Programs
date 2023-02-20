/*
 * Transpose a 3x3 Integer Matrix
 *
 * John Selmys - Feb 2023
 *
 */
#include <stdio.h>

int main(){
   int m[3][3] = {{0}};
   for(int row=0;row<3;row++){
       printf("Enter row %d here: ",row+1);
       for(int col=0;col<3;col++)
           scanf("%d",&m[row][col]);
   }
   printf("The transpose of\n");
   for(int row=0;row<3;row++){
       for(int col=0;col<3;col++)
           printf("\t%d",m[row][col]);
       printf("\n");
   }
   printf("is\n");
   for(int row=0;row<3;row++){
       for(int col=0;col<3;col++)
           printf("\t%d",m[col][row]);
       printf("\n");
   }
   return 0;
}

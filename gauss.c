/*
 * Gaussian Elimination to form Upper Triangular Matrix
 * then compute determinant of a 3x3 Matrix
 *
 * John Selmys - Feb 2023
 *
 */
#include <stdio.h>
#include <stdlib.h>

void subtractRows(double m[3][3],double r,int i, int j){
    double temp[3];
    int k;
    for(k=0;k<3;k++)
        temp[k]=r*m[i][k];
    for(k=0;k<3;k++)
        m[j][k] = m[j][k] - temp[k];
    return;
}

void swapRows(double m[3][3],int i, int j){
    double temp[3];
    int k;
    for(k=0;k<3;k++)
        temp[k] = m[i][k];
    for(k=0;k<3;k++)
        m[i][k] = m[j][k];
    for(k=0;k<3;k++)
        m[j][k] = temp[k];
    return;
}

void display(double m[3][3]){
   int row, col;
   for(row=0;row<3;row++){
       for(col=0;col<3;col++)
           printf("\t%5.2f",m[row][col]);
       printf("\n");
   }
   printf("\n");
   return;
}

void upperTri(double m[3][3]){
    // Gaussian Elimination
    double err=0.00005;
    double r;
    int i,j,k;
    for (i = 0; i < 2; i++) {
       display(m);
       if ( m[i][i] > -err && m[i][i] < err){  //m[i][i] == 0
            for (j = i; j < 3; j++) {
                if ( ! (m[j][i] > -err && m[j][i] < err)){
                    swapRows(m,i,j);
                    break;
                } 
            }
            printf("Matrix is Singular\n");
            printf("Determinant is Zero\n");
            exit(0);
        }
        for (k = i+1; k < 3; k++){
            r = m[k][i]/m[i][i];
            subtractRows(m,r,i,k);
        }
    }
    return;
}

double det(double m[3][3]){
    upperTri(m);
    return m[0][0]*m[1][1]*m[2][2];
}

int main(){
   setbuf(stdout,NULL);
   double m[3][3] = {{0}};
   for(int row=0;row<3;row++){
       printf("Enter row %d here: ",row+1);
       for(int col=0;col<3;col++)
           scanf("%lf",&m[row][col]);
   }
   printf("The determinant of\n");
   display(m); 
   printf("is %5.2f\n",det(m));
   display(m); 
   return 0;
}

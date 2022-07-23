#include <stdio.h>
/* Determine array type
 *
 * John Selmys - July 2022
 *
 */
int Diagonal(int *p, int n){
    // aij = 0 whenever i < j
    int isDiagonal=1;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j && *(p+n*i+j) !=0)
                isDiagonal=0;
    return isDiagonal;
};
int UpperTriangular(int *p, int n){
    // aij = 0 whenever i < j
    int isUpperTriangular=1;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i<j && *(p+n*i+j) !=0)
                isUpperTriangular=0;
    return isUpperTriangular;
};
int Symmetric(int *p, int n){
    // a[i][j] = a[j][i] for all i,j
    int isSymmetric=1;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(*(p+n*i+j)!=*(p+n*j+i))
                isSymmetric=0;
    return isSymmetric;
};
void getData(int n){
    int array[n][n];
    int i,j;
    for(i=0;i<n;i++){
        printf("Enter %d integers: ",n);
        for(j=0;j<n;j++)
            scanf("%d",&array[i][j]);
    }
    printf("Here is your array:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf(" %d",array[i][j]);
        printf("\n");
    }
    if(Symmetric(array[0],n))
        printf("This array IS Symmetric!\n");
    else
        printf("This array is NOT Symmetric!\n");
    if(UpperTriangular(array[0],n))
        printf("This array IS Upper Triangular!\n");
    else
        printf("This array is NOT Upper Triangular!\n");
    if(Diagonal(array[0],n))
        printf("This array IS Diagonal!\n");
    else
        printf("This array is NOT Diagonal!\n");
    return;
};
int main(){
    int n;
    printf("Enter square array size: ");
    scanf("%d",&n);
    getData(n);
    return 0;
}

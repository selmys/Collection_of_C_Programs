/*
 * Factorial using C goto 
 * Max factorial is 20
 * use bc if you want larger factorials
 * John Selmys
 *
 */ 
#include <stdio.h>
int main() {
   long long n,m=1,f=1;
   printf("enter a number: ");
   scanf("%lld",&n);
   top:
   f=f*m;
   if(m==n)
      printf("The factorial is %lld\n",f);
   else {
      m=m+1;
      goto top;
   }
}

/* Determine if a binary number is a multiple 
 * of three.
 * Maximum size is 100 binary digits
 * See associated state diagram - multiples-of-3.png
 * John Selmys
*/
#include <stdio.h>
#include <string.h>

int  isMultiple3(char c[], int size) { 
    int state = 0; 
  
    for (int i = 0; i < size; i++) { 
  
        char digit = c[i]; 
  
        switch (state) { 
  
        case 0: 
            if (digit == '1') 
                state = 1; 
            break; 
        case 1: 
            if (digit == '0') 
                state = 2; 
            else
                state = 0; 
            break; 
        case 2: 
            if (digit == '0') 
                state = 1; 
            break; 
        } 
    } 
  
    return state; 
} 
  
int main() { 
    int size; 
    char c[101]; 
    printf("Enter a binary number [100 digits maximum]:\n");
    scanf("%s",c);
    size=strlen(c);

    if (isMultiple3(c, size)==0) 
        printf("is a multiple of 3\n"); 
    else
        printf("is not a multiple of 3\n"); 
  
    return 0; 
} 

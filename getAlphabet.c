#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getAlphabet(char *text){
    // get the list of unique characters from text string
    // assume ASCII so need space for max of 128 characters
    char chars[128] = {0};
    char *letters = calloc(128,1);
    int len = strlen(text);
    for(int i=0;i<len;i++)
        chars[(int)text[i]] = text[i];
    for(int i=0,j=0;i<128;i++)
        // append characters to letters string
        if(chars[i] != 0)
            letters[j++] = chars[i];
    return letters;
}

int main(){
    char text[1000];
    printf("Enter some text:\n");
    scanf("%[^\n]",text);
    printf("Your alphabet is:\n %s\n",getAlphabet(text));
    return 0;
}

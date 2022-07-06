/* Read a file and find the longest word
 * If there are several longest words then
 * only the first one is reported
 * 
 * try inputting this C program as a test
 *
 * John Selmys
 */ 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *f;
    char c, fn[30];
    char prev[100] = {};
    char word[100] = {};
    int n=0;
    printf("Enter file name: ");
    scanf("%s", fn);
    f = fopen(fn, "r");
    while (fscanf(f, "%c", &c) != EOF) {
        if (isalpha(c)) {
            word[n]=c;
            n++;
            word[n]=0;
        } else {
            if (strlen(word) > strlen(prev)){
                strcpy(prev,word);
            }
            n = 0;
        }
    }
    printf("The longest word is %s\n and it's %ld characters long.\n", prev,strlen(prev));
    fclose(f); /*abracadabra*/
}

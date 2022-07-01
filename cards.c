/* Display a bridge hand - 13 cards
 * used unicode playing card symbols with wide characters
 * John Selmys
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>

typedef struct {
    int spades[14];
    int hearts[14];
    int diamonds[14];
    int clubs[14];
} Hand; 

void displayHand(Hand hand){
    for(int i=0;i<13;i++)
        if(hand.spades[i] != 0) 
            printf("\033[30m%lc  ",(wchar_t)hand.spades[i]);
    printf("\n");
    for(int i=0;i<13;i++)
        if(hand.hearts[i] != 0)
            printf("\033[31m%lc  ",(wchar_t)hand.hearts[i]);
    printf("\n");
    for(int i=0;i<13;i++)
        if(hand.diamonds[i] != 0)
            printf("\033[31m%lc  ",(wchar_t)hand.diamonds[i]);
    printf("\n");
    for(int i=0;i<13;i++)
        if(hand.clubs[i] != 0)
            printf("\033[30m%lc  ",(wchar_t)hand.clubs[i]);
    printf("\033[0m\n");
    return;
}

int dealOne(int d[], int *n){
    int card;
    int p = rand()%(*n);
    *n = *n - 1;
    card = d[p];
    d[p] = d[*n];
    return card;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    Hand hand = { {0},{0},{0},{0} };
    int suit, card, size = 52, index;
    int deck[52] = 
        {
        127137,127138,127139,127140,127141,127142,127143,127144,127145,127146,127147,127149,127150,
        127153,127154,127155,127156,127157,127158,127159,127160,127161,127162,127163,127165,127166,
        127169,127170,127171,127172,127173,127174,127175,127176,127177,127178,127179,127181,127182,
        127185,127186,127187,127188,127189,127190,127191,127192,127193,127194,127195,127197,127198 
        };
    for(int i=0;i<13;i++){
        card = dealOne(deck,&size);
        if(card > 127136) {
            suit = 0; index = card - 127137;
            if(card > 127152) {
                suit = 1; index = card - 127153; 
                if(card > 127168) {
                    suit = 2; index = card - 127169;
                    if(card > 127184) {
                        suit = 3; index = card - 127185;
                    }
                 }
            }
        }
        if(index > 11) index--;
        switch (suit) {
            case 0: hand.spades[index]=card;break;
            case 1: hand.hearts[index]=card;break;
            case 2: hand.diamonds[index]=card;break;
            case 3: hand.clubs[index]=card;break;
        }
    }
    displayHand(hand);
    return 0;
}

#include "shuffle.h"

int main() {
    const char *suits[SUITS] =
        {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *faces[FACES] =
        {"Ace", "Deuce", "Three", "Four",
         "Five", "Six", "Seven", "Eight",
         "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[CARDS] = {0};
    for (int i = 0; i < CARDS; i++) {
        deck[i] = i;
    }
    shuffle(deck);
    for (int i = 0; i < CARDS; i++) {
        printf("%5s of %-8s%c", faces[deck[i] % 13], suits[deck[i] / 13], " \n"[i % 2]);
    }
}
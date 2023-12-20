// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition
struct card {
    const char *face;  // define pointer face
    const char *suit;  // define pointer suit
};

typedef struct card Card;  // new type name for struct card

// prototypes
void fillDeck(Card *const wDeck, const char *wFace[],
              const char *wSuit[]);
Card *Faro_Shuffle(Card *const wDeck, int times);
void deal(const Card *const wDeck);

int main(void) {
    Card deck[CARDS];  // define array of Cards

    // initialize array of pointers
    const char *face[] = {"Ace", "Deuce", "Three", "Four", "Five",
                          "Six", "Seven", "Eight", "Nine", "Ten",
                          "Jack", "Queen", "King"};

    // initialize array of pointers
    const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    srand(time(NULL));  // randomize

    int times = 0;
    printf("Times of In-Faro shuffle: ");
    scanf("%d", &times);
    fillDeck(deck, face, suit);       // load the deck with Cards
    deal(Faro_Shuffle(deck, times));  // deal all 52 Cards
}

// place strings into Card structures
void fillDeck(Card *const wDeck, const char *wFace[],
              const char *wSuit[]) {
    // loop through wDeck
    for (size_t i = 0; i < CARDS; ++i) {
        wDeck[i].face = wFace[i % FACES];  // 0 1 2--12,0 1 2 12,
        wDeck[i].suit = wSuit[i / FACES];  // 0 0 0 0--,1 1 1 ,
    }
}

// shuffle cards
Card *Faro_Shuffle(Card *const wDeck, int times) {
    if (times <= 0) {
        return wDeck;
    }
    Card *sol = (Card *)malloc(sizeof(Card) * CARDS);  // malloc a new array for shuffle
    for (size_t i = 0; i < CARDS; ++i) {               // mathematical solution
        int index = (i + 1) * 2 - 1;
        if (index > 52) {
            index -= 53;
        }
        sol[index] = wDeck[i];
    }
    return Faro_Shuffle(sol, times - 1);
}

// deal cards
void deal(const Card *const wDeck) {
    // loop through wDeck
    for (size_t i = 0; i < CARDS; ++i) {
        // printf("%5s of %-8s\n", wDeck[i].face, wDeck[i].suit);
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
               (i + 1) % 4 ? "  " : "\n");
    }
}
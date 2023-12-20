// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
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
Card *Random_Shuffle(Card *const wDeck);
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

    fillDeck(deck, face, suit);  // load the deck with Cards
    deal(Random_Shuffle(deck));  // shuffle and deal all 52 Cards
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

// Shuffle cards
Card *Random_Shuffle(Card *const wDeck) {
    // loop through sol and randomly take wDeck to sol
    Card *sol = (Card *)malloc(sizeof(Card) * CARDS);
    for (int i = 0; i < CARDS; i++) {
        int j = rand() % (CARDS - i);              // Pick random number
        sol[i] = wDeck[j];                         // Put in sol
        for (int k = j; k < CARDS - i - 1; k++) {  // Remove used value
            wDeck[k] = wDeck[k + 1];
        }
    }
    return sol;
}

// deal cards
void deal(const Card *const wDeck) {
    // loop through wDeck
    for (size_t i = 0; i < CARDS; ++i) {
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
               (i + 1) % 4 ? "  " : "\n");
    }
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5
typedef struct cards {
    int suit, face;
} cards;

void shuffle(cards *);
void swap(cards *, cards *);
int compare(const void *, const void *);
void judge(cards *);
bool flush(cards *);
bool straight(cards *);

const char *suits[SUITS] =
    {"Spades", "Hearts", "Diamonds", "Clubs"};
const char *faces[FACES] =
    {"Deuce", "Three", "Four",
     "Five", "Six", "Seven", "Eight",
     "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

int main() {
    cards deck[52] = {0};
    cards hand[5] = {0};
    for (int i = 0; i < SUITS; i++) {  // input card's type into deck
        for (int j = 0; j < FACES; j++) {
            deck[i * 13 + j].suit = i;
            deck[i * 13 + j].face = j;
        }
    }
    shuffle(deck);
    qsort(deck, HAND, sizeof(cards), compare);  // sort hand deck
    for (int i = 0; i < HAND; i++) {
        printf("%s of %s\n", faces[deck[i].face], suits[deck[i].suit]);
        hand[i] = deck[i];  // put deck into hand
    }
    judge(hand);
}

void shuffle(cards *deck) {
    srand(time(NULL) + getpid());  // random than random
    for (int i = 0; i < CARDS; i++) {
        swap(&deck[i], &deck[rand() % CARDS]);  // swap cards with random position
    }
}

void swap(cards *a, cards *b) {
    cards temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {  // qsort's compare function
    cards a_ = *(cards *)a;
    cards b_ = *(cards *)b;
    if (a_.face == b_.face) {
        return a_.suit - b_.suit;
    }
    return a_.face - b_.face;
}

void judge(cards *hand) {
    if (!flush(hand))
        if (!straight(hand))
            ;  // printf("You have high cards\n")
}

bool flush(cards *hand) {
    int temp = hand[0].suit;
    for (int i = 1; i < HAND; i++) {  // judge if every suits are the same
        if (hand[i].suit != temp) {
            return false;
        }
    }
    printf("You have a flush of %s\n", suits[temp]);
    return true;
}

bool straight(cards *hand) {
    if (hand[4].face == 12) {  // judge if there's A2345
        for (int i = 0; i < HAND - 1; i++) {
            if (hand[i].face != i) {
                break;
            }
            if (i == HAND - 2) {
                printf("You have a straight from %s to %s\n", faces[hand[HAND - 1].face], faces[hand[HAND - 2].face]);
                return true;
            }
        }
    }
    int temp = hand[0].face;
    for (int i = 1; i < HAND; i++) {  // count up with the first card
        if (++temp != hand[i].face) {
            return false;
        }
    }
    printf("You have a straight from %s to %s\n", faces[hand[0].face], faces[hand[HAND - 1].face]);
    return true;
}
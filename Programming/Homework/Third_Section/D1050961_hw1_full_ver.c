#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5
typedef struct cards {  // struct cards type
    int suit, face;
} cards;

void shuffle(cards *);
void swap(cards *, cards *);
int compare(const void *, const void *);
bool judge(cards *);
bool straight_flush(cards *);
bool four_of_a_kind(int *);
bool full_house(int *);
bool flush(cards *);
bool straight(cards *);
bool three_of_a_kind(int *);
bool two_pairs(int *);
bool one_pair(int *);

const char *suits[SUITS] =  // suits name
    {"Clubs", "Diamonds", "Hearts", "Spades"};
const char *faces[FACES] =  // faces name
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
    while (1) {
        shuffle(deck);
        qsort(deck, HAND, sizeof(cards), compare);  // sort hand deck
        for (int i = 0; i < HAND; i++) {
            printf("%s of %s\n", faces[deck[i].face], suits[deck[i].suit]);
            hand[i] = deck[i];  // put deck into hand
        }
        if (!judge(hand)) {  // stop when finding what I want
            break;
        }
        puts("");
    }
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

bool judge(cards *hand) {
    int frequency[13] = {0};
    for (int i = 0; i < HAND; i++) {  // find face frequency
        frequency[hand[i].face]++;
    }
    if (!straight_flush(hand)) {                                      // judge straight flush
        if (!four_of_a_kind(frequency)) {                             // judge four of a kind
            if (!full_house(frequency)) {                             // judge full house
                if (!flush(hand)) {                                   // judge flush
                    if (!straight(hand)) {                            // judge straight
                        if (!three_of_a_kind(frequency)) {            // judge three of a kind
                            if (!two_pairs(frequency)) {              // judge two pairs
                                if (!one_pair(frequency)) {           // judge one pair
                                    printf("You have high cards\n");  // high cards only
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // else {
    //     return false;
    // }
    // return true // combine with else above to find what I want
    return false;
}

bool straight_flush(cards *hand) {
    int temp_suit = hand[0].suit;
    int temp_face = hand[0].face;
    for (int i = 1; i < HAND; i++) {
        if (hand[i].face != ++temp_face) {  // count up with the first card
            return false;
        }
        if (hand[i].suit != temp_suit) {  // judge if every suits are the same
            return false;
        }
    }
    printf("You have a %s straight flush from %s to %s\n", suits[temp_suit], faces[hand[0].face], faces[hand[4].face]);
    return true;
}

bool four_of_a_kind(int *frequency) {
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 4) {  // judge if any frequency is four
            printf("You have four of %s\n", faces[i]);
            return true;
        }
    }
    return false;
}

bool full_house(int *frequency) {
    int two = 0, three = 0, flag_two = 0, flag_three = 0;
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 3) {
            three = i;
            flag_three = 1;
        } else if (frequency[i] == 2) {
            two = i;
            flag_two = 1;
        }
    }
    if (flag_two && flag_three) {
        printf("You have a full house of %s with %s pair\n", faces[three], faces[two]);
        return true;
    }
    return false;
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

bool three_of_a_kind(int *frequency) {
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 3) {  // judge if any frequency is three
            printf("You have three of %s\n", faces[i]);
            return true;
        }
    }
    return false;
}

bool two_pairs(int *frequency) {
    int first_pair = 0, second_pair = 0, flag = 0;
    for (int i = 0; i < FACES; i++) {  // judge if there's two frequencies are two
        if (frequency[i] == 2 && flag == 0) {
            first_pair = i;
            flag++;
        } else if (frequency[i] == 2 && flag == 1) {
            second_pair = i;
            flag++;
            break;
        }
    }
    if (flag == 2) {
        printf("You have two pairs of %s and %s\n", faces[first_pair], faces[second_pair]);
        return true;
    }
    return false;
}

bool one_pair(int *frequency) {
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 2) {  // judge if any frequency is two
            printf("You have a pair of %s\n", faces[i]);
            return true;
        }
    }
    return false;
}
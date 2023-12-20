#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 5
#define BLACK "\x1b[%d;%dm", 30, 100
#define YELLOW "\x1b[%d;%dm", 30, 43
#define GREEN "\x1b[%d;%dm", 30, 42
#define RESETCOLOR "\x1b[0m"
FILE *word;
FILE *history;
typedef struct {
    int count;
    char **data;
} type;
void scan_word(type *);             // scan word from file
void scan_history(type *);          // scan history from file
void delete_words(type *, type *);  // delete words from history
void print_words(type *);           // print words
void check_words(type *);           // check words

int main() {
    type *words = (type *)malloc(sizeof(type));      // words
    type *histories = (type *)malloc(sizeof(type));  // histories
    scan_word(words);                                // scan word from file
    scan_history(histories);                         // scan history from file
    delete_words(words, histories);                  // delete words from history
    print_words(words);                              // print words
}

void scan_word(type *words) {
    if ((word = fopen("words.txt", "r")) == NULL) {  // open words file
        printf("Error: Cannot open word.txt\n");
    } else {
        printf("word.txt opened successfully\n");
    }
    while (fscanf(word, "%*s") != EOF) {  // count words
        words->count++;
    }

    words->data = (char **)malloc(words->count * sizeof(char *));  // malloc words data array
    for (int i = 0; i < words->count; i++) {                       // malloc words data array
        words->data[i] = (char *)malloc((length + 1) * sizeof(char));
    }

    rewind(word);  // rewind back to beginning

    int index = 0;
    while (fscanf(word, "%s", words->data[index++]) != EOF)  // scan words into array
        ;
}

void scan_history(type *histories) {
    if ((history = fopen("history.txt", "r")) == NULL) {  // open history file
        printf("Error: Cannot open history.txt\n");
    } else {
        printf("history.txt opened successfully\n");
    }
    fscanf(history, "%*s%*s%*s");                  // ignore the first line
    while (fscanf(history, "%*s%*s%*s") != EOF) {  // count histories
        histories->count++;
    }

    rewind(history);  // rewind back to beginning

    histories->data = (char **)malloc(histories->count * sizeof(char *));  // malloc history's data
    for (int i = 0; i < histories->count; i++) {                           // malloc history's data
        histories->data[i] = (char *)malloc((length + 1) * sizeof(char));
    }

    int index = 0;
    fscanf(history, "%*s%*s%*s");                                         // ignore the first line
    while (fscanf(history, "%*s%*s%s", histories->data[index++]) != EOF)  // scan history into array
        ;
}

void delete_words(type *words, type *histories) {
    for (int i = 0; i < histories->count; i++) {
        for (int j = 0; j < length; j++) {
            histories->data[i][j] = tolower(histories->data[i][j]);  // turn history data to lower case
        }
        for (int j = 0; j < words->count; j++) {
            if (strcmp(histories->data[i], words->data[j]) == 0) {  // compare history data with words data
                strcpy(words->data[j], "");                         // make it a void string
                break;
            }
        }
    }
    free(histories->data);  // free history's data
}

void print_words(type *words) {
    int count = 0;
    for (int i = 0; i < words->count; i++) {
        if (strcmp(words->data[i], "") != 0) {  // print if the word is not a void string
            printf("%s%c", words->data[i], ((count++ + 1) % 10) ? ' ' : '\n');
        }
    }
    if (count % 10) {
        printf("\n");
    }
    check_words(words);  // call function
}

void check_words(type *words) {
    char input[6], result[6];
    int alphabet[27] = {0};       // alphabet frequency
    printf("Input your word: ");  // the word you type in wordle
    scanf("%s", input);
    printf("Input your result: ");  // the result after you type in wordle
    scanf("%s", result);
    printf("Your word is : ");
    for (int i = 0; i < length; ++i) {
        switch (result[i]) {
            case 'b': {
                printf(BLACK);
                printf("[%c]", input[i]);
                break;
            }
            case 'y': {
                printf(YELLOW);
                printf("[%c]", input[i]);
                break;
            }
            case 'g': {
                printf(GREEN);
                printf("[%c]", input[i]);
                break;
            }
        }
    }
    printf(RESETCOLOR);
    printf("\n");

    for (int i = 0; i < length; i++) {
        input[i] = tolower(input[i]);    // turn input into lower case
        result[i] = toupper(result[i]);  // turn result into upper case
    }

    if (strcmp(result, "GGGGG") == 0) {  // the case that stops
        fclose(word);
        fclose(history);
        return;
    }

    for (int i = 0; i < length; i++) {
        if (result[i] == 'G' || result[i] == 'Y') {  // if the result is G or Y
            alphabet[input[i] - 'a']++;              // count frequency of G case and Y case
        }
    }
    for (int i = 0; i < words->count; i++) {  // check if the word is in the word array
        int temp_alphabet[27] = {0};
        for (int j = 0; j < length; j++) {
            temp_alphabet[words->data[i][j] - 'a']++;  // count frequency of every words
        }
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == 1) {                    // if the frequency of the word is 1
                if (alphabet[j] < temp_alphabet[j]) {  // when temp's frequency is greater than the word's
                    int temp_wrong = 0;
                    for (int k = 0; k < length; k++) {
                        if (result[k] == 'B' && input[k] == j + 'a') {  // if the result is B and the input is the same
                            temp_wrong++;
                        }
                    }
                    if (temp_wrong > 0) {
                        if (alphabet[j] != temp_alphabet[j]) {  // if the frequency of the word is not the same
                            strcpy(words->data[i], "");         // make it a void string
                        }
                    }
                } else if (alphabet[j] != temp_alphabet[j]) {  // when temp's frequency is less than the word's
                    strcpy(words->data[i], "");                // make it a void string
                }
                continue;
            }
            if (alphabet[j] > 1) {                     // if the frequency of the word is greater than 1
                if (alphabet[j] > temp_alphabet[j]) {  // judge if the frequency is correct
                    strcpy(words->data[i], "");        // make it a void string
                }
            }
        }
    }

    for (int i = 0; i < length; i++) {
        switch (result[i]) {
            case 'G':
                for (int j = 0; j < words->count; j++) {
                    if (words->data[j][i] != input[i]) {  // if the character is not same as the input
                        strcpy(words->data[j], "");       // make it a void string
                    }
                }
                break;
            case 'B':
                for (int j = 0; j < words->count; j++) {
                    if (words->data[j][i] == input[i]) {  // delete if the character is same as the input
                        strcpy(words->data[j], "");
                    }
                }
                if (alphabet[input[i] - 'a'] == 0) {  // if no other same characters
                    for (int j = 0; j < words->count; j++) {
                        for (int k = 0; k < length; k++) {
                            if (words->data[j][k] == input[i]) {  // if exist characters that should not
                                strcpy(words->data[j], "");       // make it a void string
                            }
                        }
                    }
                }
                break;
            case 'Y':
                for (int j = 0; j < words->count; j++) {
                    if (words->data[j][i] == input[i]) {  // if the character is same as the input
                        strcpy(words->data[j], "");
                    }
                }
                break;
            default:
                break;
        }
    }
    print_words(words);  // call function
}
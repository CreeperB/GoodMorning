#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);
void print_array(int[], int);
void print_best_case(int[], int);
void print_worst_case(int[], int);

int main(void) {
    int length = 0;
    scanf("%d", &length);  // scan the length of score
    int score[100000] = {0};
    for (int i = 0; i < length; i++) {
        scanf("%d", &score[i]);  // scan score into array
    }
    qsort(score, length, sizeof(int), compare);  // use qsort to sort
    print_array(score, length);                  // print the sorted array
    print_best_case(score, length);              // print the best case answer
    print_worst_case(score, length);             // print the worst case answer
}

int compare(const void *a, const void *b) {  // compare the two scores
    return *(int *)a - *(int *)b;
}

void print_array(int score[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", score[i]);
        if (i != length - 1) {
            printf(" ");  // print ' ' if it's between two scores
        } else {
            printf("\n");  // print '\n' if it's the last score
        }
    }
}

void print_best_case(int score[], int length) {
    int flag = 0;
    int max = -1;
    for (int i = 0; i < length; i++) {
        if (score[i] > max && score[i] < 60) {  // judge the score below 60
            flag = 1;                           // change flag to 1 if there's score below 60
            max = score[i];                     // set max
        }
    }
    if (flag == 1) {
        printf("%d\n", max);
    } else {
        printf("best case\n");  // print best case if no scores below 60
    }
}

void print_worst_case(int score[], int length) {
    int flag = 0;
    int min = 101;
    for (int i = 0; i < length; i++) {
        if (score[i] < min && score[i] >= 60) {  // judge the score above 60
            flag = 1;                            // change flag to 1 if there's score above 60
            min = score[i];                      // set min
        }
    }
    if (flag == 1) {
        printf("%d\n", min);
    } else {
        printf("worst case\n");  // print best case if no scores above 60
    }
}
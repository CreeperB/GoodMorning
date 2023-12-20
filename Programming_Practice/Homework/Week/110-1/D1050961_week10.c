#include <stdio.h>

int count_fibonacci = 2;  // var fibonacci index as global variables
void fibonacci(int *);
void swap(int *, int *);

int main(void) {
    int fib[100] = {0, 1};  // var fib array with fib(0) & fib(1)
    int times = 0;
    scanf("%d", &times);  // input loop times
    for (int i = 0; i < times; i++) {
        int amount = 0;
        int start = 0;
        int end = 0;
        scanf("%d %d", &start, &end);  // input range
        if (start > end)
            swap(&start, &end);  // swap if the second input is bigger than the first one
        while (1) {
            if (fib[count_fibonacci - 1] <= end) {  // create the next number of fib if the maxium of the last element is smaller or equal to end
                fibonacci(fib);
            } else
                break;
        }
        for (int i = 0;; i++) {
            if (fib[i] >= start && fib[i] <= end) {  // print the fib element in the range
                printf("%d\n", fib[i]);
                amount++;
            } else if (fib[i] > end)
                break;
        }
        printf("%d\n", amount);  // print the amount of the numbers in the range
        if (i != times - 1)
            printf("------\n");
    }
}

void fibonacci(int *fib) {
    fib[count_fibonacci] = fib[count_fibonacci - 1] + fib[count_fibonacci - 2];  // rule of fibonacci
    count_fibonacci++;                                                           // ready for the next call
}

void swap(int *start, int *end) {  // swap two elements
    int temp = *start;
    *start = *end;
    *end = temp;
}
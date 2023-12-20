#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main() {
    int start = 0, end = 0;
    while (scanf("%d %d", &start, &end) && !(start == -1 && end == -1)) {
        swap(&start, &end);
        printf("%d\n", (start + 100 - end < abs(start - end)) ? start + 100 - end : abs(start - end));
    }
}

void swap(int *a, int *b) {
    if (*b < *a) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
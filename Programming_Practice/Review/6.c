#include <stdio.h>
#include <stdlib.h>
int compare(const void *, const void *);

int main() {
    int times = 0;
    int scores[1000] = {0};
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d", &scores[i]);
    }
    qsort(scores, times, sizeof(int), compare);
    for (int i = 0; i < times; i++) {
        printf("%d%c", scores[i], " \n"[i == times - 1]);
    }
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
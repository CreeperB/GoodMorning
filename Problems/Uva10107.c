#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *, const void *);

int main() {
    int n = 0;
    int midian[1000] = {0};
    int i = 0;
    while (scanf("%d", &n) != EOF) {
        int mid = 0;
        i++;
        midian[i] = n;
        qsort(midian, i + 1, sizeof(int), compare);
        if (i % 2) {
            mid = (i + 1) / 2;
            printf("%d\n", midian[mid]);
        } else {
            mid = i / 2;
            printf("%d\n", (midian[mid] + midian[mid + 1]) / 2);
        }
    }
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main() {
    int times = 0;
    int length = 0;
    int door[1000] = {0};
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d", &length);
        for (int j = 0; j < length; j++) {
            scanf("%d", &door[j]);
        }
        qsort(door, length, sizeof(int), compare);
        int mid = length / 2;
        int distance = 0;
        for (int l = 0; l < length; l++) {
            int k = 0;
            k = abs(door[mid] - door[l]);
            distance = distance + k;
        }
        printf("%d\n", distance);
    }
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
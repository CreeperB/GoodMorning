#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool is_sorted(int *a, int n) {
    while (--n >= 1) {
        if (a[n] < a[n - 1])
            return false;
    }
    return true;
}

void shuffle(int *a, int n) {
    int t, r;
    for (int i = 0; i < n; i++) {
        t = a[i];
        r = rand() % n;
        a[i] = a[r];
        a[r] = t;
    }
}

void bogosort(int *a, int n) {
    while (!is_sorted(a, n))
        shuffle(a, n);
}

int main() {
    int time_time = time(NULL);
    int x[100000] = {0};
    int len = 0;
    while (1) {
        scanf("%d", &x[len]);
        len++;
        if (getchar() == '\n') {
            break;
        }
    }
    printf("Original Array:\n");
    for (int i = 0; i < len; i++)
        printf("%d%s", x[i], i == len - 1 ? "\n" : " ");

    bogosort(x, len);

    printf("\nSorted Array:\n");
    for (int i = 0; i < len; i++)
        printf("%d%s", x[i], i == len - 1 ? "\n" : " ");
}
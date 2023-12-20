#include <stdio.h>
#include <stdlib.h>
int gcd(int, int);
int compare(const void *, const void *);

int main() {
    int times = 0;
    int x, y;
    int ans[1000] = {0};
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d %d", &x, &y);
        ans[i] = gcd(x, y);
    }
    qsort(ans, times, sizeof(int), compare);
    for (int i = 0; i < times; i++) {
        printf("%d%c", ans[i], " \n"[i == times - 1]);
    }
}

int gcd(int x, int y) {
    if (!y) {
        return x;
    }
    return gcd(y, x % y);
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
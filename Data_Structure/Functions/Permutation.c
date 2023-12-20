#include <stdio.h>
#include <string.h>
#define SWAP(a, b) \
    {              \
        int t;     \
        t = a;     \
        a = b;     \
        b = t;     \
    }

void perm(char *list, int i, int n) {
    if (i == n) {
        printf("%s\n", list);
    } else {
        for (int j = i; j <= n; j++) {
            SWAP(list[i], list[j]);
            perm(list, i + 1, n);
            SWAP(list[i], list[j]);
        }
    }
}

int main(void) {
    char buffer[10] = "abcd";
    perm(buffer, 0, strlen(buffer) - 1);
}

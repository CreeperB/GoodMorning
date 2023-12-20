#include <stdio.h>
#include <stdlib.h>

int main() {
    int friend = 0, enemy = 0;
    while (scanf("%d", &friend), scanf("%d", &enemy) != EOF)
        printf("%d\n", abs(friend - enemy));
}
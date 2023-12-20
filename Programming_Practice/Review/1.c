#include <stdio.h>

int main() {
    long AC = 0;
    int score = 0;
    int i = 0;
    char GF;
    scanf("%ld %c", &AC, &GF);
    if (GF == 'N') {
        if (AC >= 40) {
            printf("100\n");
            return 0;
        }
        while (AC-- > 0) {
            if (i < 10) {
                score += 6;
            } else if (i < 20) {
                score += 2;
            } else if (i < 40) {
                score += 1;
            }
            i++;
        }
        printf("%d\n", score);
    } else
        printf("Flunked\n");
}
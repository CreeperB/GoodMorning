#include <stdio.h>
#include <stdlib.h>

int main() {
    char input_map[101][101] = {0};
    char output_map[103][103] = {0};
    int x, y;
    scanf("%d %d\n", &y, &x);
    for (int i = 0; i < y; i++) {
        scanf("%s", input_map[i]);
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (input_map[i][j] == '*') {
                for (int k = i; k <= i + 2; k++) {
                    for (int l = j; l <= j + 2; l++) {
                        output_map[k][l]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (input_map[i][j] == '*') {
                printf("*");
            } else {
                printf("%d", output_map[i + 1][j + 1]);
            }
        }
        printf("\n");
    }
}
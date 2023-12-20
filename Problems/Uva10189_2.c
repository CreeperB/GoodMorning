#include <stdio.h>

int main() {
    int length = 0, width = 0;
    int field = 0;
    while (scanf("%d %d\n", &length, &width) != EOF && !(length == 0 && width == 0)) {
        char map[103][103] = {0};
        int count[103][103] = {0};
        for (int i = 1; i <= length; i++) {
            for (int j = 1; j <= width; j++) {
                scanf("%c", &map[i][j]);
                if (map[i][j] == '*') {
                    for (int k = i - 1; k <= i + 1; k++) {
                        for (int l = j - 1; l <= j + 1; l++) {
                            count[k][l]++;
                        }
                    }
                }
            }
            getchar();
        }
        printf("Field #%d:\n", ++field);
        for (int i = 1; i <= length; i++) {
            for (int j = 1; j <= width; j++) {
                if (map[i][j] == '*') {
                    printf("*");
                } else {
                    printf("%d", count[i][j]);
                }
            }
            puts("");
        }
        puts("");
    }
}
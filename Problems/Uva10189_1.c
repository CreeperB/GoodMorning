#include <stdio.h>

int main() {
    int length = 0, width = 0;
    int field = 0;
    while (scanf("%d %d\n", &length, &width) != EOF && !(length == 0 && width == 0)) {
        char map[103][103] = {0};
        for (int i = 1; i <= length; i++) {
            for (int j = 1; j <= width; j++) {
                scanf("%c", &map[i][j]);
            }
            getchar();
        }
        for (int i = 1; i <= length; i++) {
            for (int j = 1; j <= width; j++) {
                if (map[i][j] == '*') continue;
                int mine_count = 0;
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (map[k][l] == '*') {
                            mine_count++;
                        }
                    }
                }
                map[i][j] = mine_count + '0';
            }
        }
        printf("Field #%d:\n", ++field);
        for (int i = 1; i <= length; i++) {
            for (int j = 1; j <= width; j++) {
                printf("%c", map[i][j]);
            }
            puts("");
        }
        puts("");
    }
}
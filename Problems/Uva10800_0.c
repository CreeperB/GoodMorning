#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int times;
    scanf("%d", &times);
    for (int i = 1; i <= times; i++) {
        printf("Case #%d:\n", i);
        char stock[100] = {0};
        scanf("%s", stock);
        int width = strlen(stock);
        int height = 0;
        int max_height = 0;
        for (int i = 0; i < width; i++) {
            if (stock[i] == 'R') {
                if (stock[i + 1] == 'C' && i > 0 && i < width) {
                    height++;
                }
                height++;
            }
            if (stock[i] == 'F') {
                height--;
            }
            if (height > max_height) {
                max_height = height;
            }
        }
        // height = 10;
        // width = 20;
        height = max_height + 1;
        width += 3;
        char **xy = NULL;
        xy = (char **)malloc((height) * sizeof(char *));
        for (int i = 0; i < height; i++) {
            xy[i] = (char *)malloc((width) * sizeof(char));
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                xy[i][j] = ' ';
            }
        }
        for (int i = 0; i < height; i++) {
            xy[i][0] = '|';
        }
        xy[height - 1][0] = '+';
        for (int i = 1; i < width; i++) {
            xy[height - 1][i] = '-';
        }
        int y = 2;
        int flag = 0;
        for (int i = 2; i < width - 1; i++) {
            if (stock[i - 2] == 'R') {
                if (i > 2) {
                    if (stock[i - 3] == 'F') {
                        ;
                    } else if (flag) {
                        y++;
                    } else if (!flag) {
                        y--;
                    }
                }
                xy[height - y][i] = '/';
                flag = 1;
            } else if (stock[i - 2] == 'F') {
                if (i > 2) {
                    if (stock[i - 3] == 'R') {
                        ;
                    } else if (flag) {
                        y++;
                    } else if (!flag) {
                        y--;
                    }
                }
                xy[height - y][i] = '\\';
                flag = 0;
            } else if (stock[i - 2] == 'C') {
                if (i > 2) {
                    if (stock[i - 3] == 'C') {
                        ;
                    } else if (flag && i > 2) {
                        y++;
                    } else if (!flag && i > 2) {
                        y--;
                    }
                }
                xy[height - y][i] = '_';
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%c", xy[i][j]);
            }
            puts("");
        }
    }
}
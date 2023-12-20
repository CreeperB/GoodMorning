#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int lost[100][100] = {0};
    int x_edge, y_edge;
    scanf("%d %d\n", &x_edge, &y_edge);
    int x, y;
    char ori;
    while (scanf("%d %d %c\n", &x, &y, &ori) != EOF) {
        int flag = 0;
        char a;
        while (1) {
            a = getchar();
            if (a == '\n') {
                break;
            }
            if (a == 'L') {
                switch (ori) {
                    case 'N':
                        ori = 'W';
                        break;
                    case 'W':
                        ori = 'S';
                        break;
                    case 'S':
                        ori = 'E';
                        break;
                    case 'E':
                        ori = 'N';
                        break;
                    default:
                        break;
                }
            } else if (a == 'R') {
                switch (ori) {
                    case 'N':
                        ori = 'E';
                        break;
                    case 'E':
                        ori = 'S';
                        break;
                    case 'S':
                        ori = 'W';
                        break;
                    case 'W':
                        ori = 'N';
                        break;
                    default:
                        break;
                }
            } else {
                switch (ori) {
                    case 'N':
                        y++;
                        break;
                    case 'W':
                        x--;
                        break;
                    case 'S':
                        y--;
                        break;
                    case 'E':
                        x++;
                        break;
                    default:
                        break;
                }
            }
            if (x < 0 || y < 0 || x > x_edge || y > y_edge) {
                switch (ori) {
                    case 'N':
                        y--;
                        break;
                    case 'W':
                        x++;
                        break;
                    case 'S':
                        y++;
                        break;
                    case 'E':
                        x--;
                        break;
                    default:
                        break;
                }
                if (lost[x][y] == 1) {
                    continue;
                }
                lost[x][y] = 1;
                flag = 1;
                while (getchar() != '\n')
                    ;
                break;
            }
        }
        if (flag) {
            printf("%d %d %c LOST\n", x, y, ori);
        } else {
            printf("%d %d %c\n", x, y, ori);
        }
    }
}
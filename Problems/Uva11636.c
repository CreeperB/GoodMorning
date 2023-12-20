#include <math.h>
#include <stdio.h>

int main() {
    int num;
    int x = 0, y;
    while (scanf("%d", &num), num >= 0) {
        x += 1;
        y = 0;
        while (1) {
            if (pow(2, y) >= num) {
                break;
            } else {
                y += 1;
            }
        }
        printf("Case %d: %d\n", x, y);
    }
}
#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    int top;
    int mid;
    int bot;
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && b + c > a && a + c > b) {
        if (a >= b && a >= c) {
            top = a;
            if (b >= c) {
                mid = b;
                bot = c;
            } else {
                mid = c;
                bot = b;
            }
        } else if (b >= a && b >= c) {
            top = b;
            if (a >= c) {
                mid = a;
                bot = c;
            } else {
                mid = c;
                bot = a;
            }
        } else {
            top = c;
            if (a >= b) {
                mid = a;
                bot = b;
            } else {
                mid = b;
                bot = a;
            }
        }

        if (mid * mid + bot * bot == top * top) {
            printf("right triangle\n");
        } else if (mid * mid + bot * bot > top * top) {
            printf("acute triangle\n");
        } else {
            printf("obtuse triangle\n");
        }
    } else {
        printf("Not a triangle.\n");
    }
}
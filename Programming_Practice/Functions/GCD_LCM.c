#include <stdio.h>

int main() {
    int a, b;
    int GCD = 0;
    int LCM = 0;
    int count = 1;
    int temp;
    scanf("%d %d", &a, &b);

    count = a * b;
    while (GCD == 0) {
        if (a % count == 0 && b % count == 0) {
            GCD = count;
        } else {
            count -= 1;
        }
    }
    count = 1;
    while (LCM == 0) {
        if (count % a == 0 && count % b == 0) {
            LCM = count;
        } else {
            count += 1;
        }
    }
    printf("%d %d", GCD, LCM);
}
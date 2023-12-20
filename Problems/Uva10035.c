#include <stdio.h>

int main() {
    int n1, n2;
    while (scanf("%d%d", &n1, &n2) && !(n1 == 0 && n2 == 0)) {
        int digit = 0;
        while (n1 != 0 && n2 != 0) {
            if (n1 % 10 + n2 % 10 >= 10) {
                digit++;
                n1 += 10;
            }
            n1 /= 10;
            n2 /= 10;
        }
        if (!digit) {
            printf("No carry operation.\n");
        } else {
            printf("%d carry operation%s.\n", digit, !(digit - 1) ? "" : "s");
        }
    }
}
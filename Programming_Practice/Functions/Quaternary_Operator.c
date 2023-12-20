#include <stdio.h>

int main(void) {
    int a, b;
    char notation;
    scanf("%d %c %d", &a, &notation, &b);

    switch (notation) {
        case '+':
            printf("%d + %d = %d", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d", a, b, a * b);
            break;
        case '/':
            if (b == 0) {
                printf("Denominator can't be 0.");
                break;
            } else {
                printf("%d / %d = %.4lf", a, b, (double)a / (double)b);
                break;
            }
        default:
            printf("Error input\n");
            break;
    }
}
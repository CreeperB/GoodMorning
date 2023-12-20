#include <stdio.h>
int count_digit(long long);

int main() {
    long long num = 0;
    while (scanf("%lld", &num) && num != 0) {
        printf("%d\n", count_digit(num));
    }
}

int count_digit(long long num) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += num % 10;
        num /= 10;
    }
    if (sum >= 10) {
        return count_digit(sum);
    } else {
        return sum;
    }
}
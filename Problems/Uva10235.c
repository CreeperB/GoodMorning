#include <stdio.h>

int prime(int, int *, int);
int create_prime(int *, int);
int first_n = 0;

int main() {
    int index = 0;
    int prime_num[10000] = {0};
    while (scanf("%d", &first_n) != EOF) {
        int result = prime(first_n, prime_num, index);
        if (result == 2) {
            printf("%d is not prime.\n", first_n);
        } else {
            printf("%d is %s.\n", first_n, result ? "prime" : "emirp");
        }
    }
}

int prime(int n, int *prime_num, int index) {
    if (n < prime_num[index]) {
        for (int i = 0; i <= index; i++) {
            if (n == prime_num[i]) {
                int reverse_n = 0, digit = 1;
                for (int j = n; j >= 10; j /= 10) {
                    digit *= 10;
                }
                for (int j = n; j > 0; j /= 10, digit /= 10) {
                    reverse_n += (j % 10) * digit;
                }
                if (first_n == reverse_n)
                    return 1;
                if (prime(reverse_n, prime_num, index) == 2)
                    return 1;
                else
                    return 0;
            }
        }
        return 2;
    } else {
        prime_num[index + 1] = create_prime(prime_num, index);
        return prime(n, prime_num, index + 1);
    }
}

int create_prime(int *prime_num, int index) {
    for (int i = prime_num[index] + 1;; i++) {
        int flag = 0;
        for (int j = i - 1; j > 1; j--) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            return i;
        }
    }
}
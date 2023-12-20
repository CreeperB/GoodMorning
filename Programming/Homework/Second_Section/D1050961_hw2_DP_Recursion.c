#include <stdio.h>

int climbStairs(int);
int value[46] = {1, 1};

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%ld\n", climbStairs(n));
}

int climbStairs(int n) {
    if (n <= 2)
        return n;
    if (!value[n])  // if the value in the previous one doesn't exist , make it exist
        value[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return value[n];
}
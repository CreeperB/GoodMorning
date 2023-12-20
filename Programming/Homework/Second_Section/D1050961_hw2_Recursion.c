#include <stdio.h>

int climbStairs(int);

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", climbStairs(n));
}

int climbStairs(int n) {
    if (n <= 2)
        return n;
    else
        return climbStairs(n - 1) + climbStairs(n - 2);  // keep calling itself until the condition above is valid
}
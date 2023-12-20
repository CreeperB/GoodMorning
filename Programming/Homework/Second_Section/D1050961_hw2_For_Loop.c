#include <stdio.h>

int climbStairs(int);

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", climbStairs(n));
}

int climbStairs(int n) {
    int f[46] = {1, 1};
    for (int i = 2; i <= n; i++) {  // calculate the array's element to n
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
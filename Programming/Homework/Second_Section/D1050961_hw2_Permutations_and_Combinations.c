#include <stdio.h>

long long C(int, int);
long long factorial(int);
int climbStairs(int);

int main() {
    int n = 0, sum = 0;
    scanf("%d", &n);
    climbStairs(n);
    printf("%d\n", climbStairs(n));
}

int climbStairs(int n) {
    int sum = 0;
    for (int i = 0; i <= n / 2; i++) {
        sum += C(n - 2 * i, i);  // count all the ways to climb stairs
    }
    return sum;
}

long long C(int up, int down) {  // calculate combination
    return factorial(up + down) / (factorial(up) * factorial(down));
}

long long factorial(int a) {  // calculate factorial
    if (a == 0 || a == 1)
        return 1;
    else
        return factorial(a - 1) * a;
}
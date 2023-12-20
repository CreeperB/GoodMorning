#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary(long long x) {  // binary function
    int i;
    if (x == 0) return;  // if x is 0, return index
    if (x % -2 == -1) {  // correct the value of x
        i = 1;
        x -= 2;
    } else if (x % -2 == 1) {  // mod == 1
        i = 1;
    } else {  // mod == 0
        i = 0;
    }
    binary(x / -2);   // recursive call
    printf("%d", i);  // print the value of i
}

int main() {
    long long in;
    int times;
    int cases = 1;
    scanf("%d", &times);  // input times
    while (times--) {
        printf("Case #%d: ", cases++);
        scanf("%lld", &in);
        if (in == 0) {  // if in is 0, output 0
            printf("0\n");
            continue;
        }
        binary(in);  // call binary function and get the index
        printf("\n");
    }
}
#include <stdio.h>

void bangla(long long);

int main() {
    long long num = 0;
    int case_count = 0;
    while (scanf("%lld", &num) != EOF) {
        printf("%4d.", ++case_count);
        if (!num) {
            printf(" 0\n");
            continue;
        }
        bangla(num);
        puts("");
    }
}

void bangla(long long num) {
    if (num >= 10000000) {
        bangla(num / 10000000);
        printf(" kuti");
        num %= 10000000;
    }
    if (num >= 100000) {
        if (num / 100000) {
            printf(" %lld lakh", num / 100000);
        }
        num %= 100000;
    }
    if (num >= 1000) {
        if (num / 1000) {
            printf(" %lld hajar", num / 1000);
        }
        num %= 1000;
    }
    if (num >= 100) {
        if (num / 100) {
            printf(" %lld shata", num / 100);
        }
        num %= 100;
    }
    if (num) {
        printf(" %lld", num);
    }
}
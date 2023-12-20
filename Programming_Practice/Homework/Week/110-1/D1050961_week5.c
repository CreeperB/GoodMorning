#include <stdio.h>

int sum;
int cola_counter(int cola) {
    sum += cola / 3;             //總合加上兌換的
    cola = cola / 3 + cola % 3;  //計算剩餘可樂數
    if (cola == 2) {
        return sum + 1;  //如果可以借一瓶就借完再換一瓶
    } else if (cola < 2) {
        return sum;  //不用借的情況
    } else {
        return cola_counter(cola);  //如果還能兌換就再返回function
    }
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        sum = N;  //設一開始的數量
        printf("%d\n", cola_counter(N));
    }
}
#include <stdio.h>

int main() {
    int ticket;  //設定ticket變數
    int drink;   //設定drink變數
    printf("How many tickets and drinks needed ?\n");
    scanf("%d %d", &ticket, &drink);  //輸入ticket, drink數量
    if (ticket == 1 && drink >= 1) {  // A方案條件
        printf("%d\n", ticket * 300 + drink * 40 - 10);
    } else if (ticket > 1 && drink == 0) {  // B方案條件
        printf("%.0f\n", (float)ticket * 300 * 0.9);
    } else if (ticket > 1 && drink > 0) {  // C方案條件
        printf("%.0f\n", (float)(ticket * 300 + drink * 40) * 0.85 - 30);
    } else {  //不享有任何優惠
        printf("%d\n", ticket * 300 + drink * 40);
    }
}
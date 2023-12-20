#include <stdio.h>

int main() {
    int x;  //定義x
    int y;  //定義y
    int z;  //定義z
    scanf("%d", &z);
    x = (z + 63) / 3 - 30;        // z代入計算x值
    y = (x + 10) * 3 + 6;         // x代入計算y值
    printf("%d %c", x, (char)y);  //輸出密碼&ASCII轉換
}
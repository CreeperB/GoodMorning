#include <stdio.h>

void hanoi(int, char, char, char);
void swap(char, char);
int count = 0;
int A[] = {0};
int B[] = {0};
int C[] = {0};

int main() {
    int n;
    printf("請輸入盤數:");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("total count : %d\n", count);
    return 0;
}

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        swap(A, C);
    } else {
        hanoi(n - 1, A, C, B);  //把左邊最下面以上的往中間移
        swap(A, C);             //把左邊最下面的移到右邊
        hanoi(n - 1, B, A, C);  //把原本左邊最下面以上的(中間)移到右邊
    }
}

void swap(char A, char C) {
    printf("Move sheet from %c to %c\n", A, C);
    count++;
}
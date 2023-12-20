#include <stdio.h>
int judge(int);

int main() {
    int input = 0;
    while (scanf("%d", &input)) {
        if (input == 0) {
            return 0;
        }
        int compare_1 = judge(input);
        if (input == compare_1) {
            printf("=%d\n", input);
            continue;
        }
        int compare_2 = judge(compare_1);
        if (input == compare_2) {
            printf("%d\n", compare_1);
            continue;
        }
        printf("0\n");
    }
}

int judge(int input) {
    int sum = 1;
    for (int i = 2; i * i <= input; i++) {
        if (input % i == 0) {
            if (i == input / i) {
                sum -= i;
            }
            sum += i + input / i;
        }
    }
    return sum;
}
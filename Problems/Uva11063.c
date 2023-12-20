#include <stdio.h>

int main() {
    int case_num = 0, length = 0;
    int b2[100] = {0};
    while (scanf("%d", &length) != EOF) {
        int sum[10000] = {0};
        int sum_flag = 0;
        for (int i = 0; i < length; i++) {
            scanf("%d", &b2[i]);
        }
        for (int i = 0; i < length - 1; i++) {
            if (b2[i] > b2[i + 1] || b2[i] < 0)
                sum_flag = 1;
        }
        int sum_count = 0;
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                sum[sum_count] = b2[i] + b2[j];
                sum_count++;
            }
        }
        for (int i = 0; i < sum_count; i++) {
            int flag = 0;
            for (int j = i + 1; j < sum_count; j++) {
                if (sum[i] == sum[j]) {
                    flag++;
                }
            }
            if (flag) {
                sum_flag = 1;
                break;
            }
        }
        case_num++;
        printf("Case #%d: It is %s B2-Sequence.\n\n", case_num, sum_flag ? "not a" : "a");
    }
}
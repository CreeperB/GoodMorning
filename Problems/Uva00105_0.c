#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int left, height, right;
    int height_sum[20002] = {0};
    int rightest = 0;
    while (scanf("%d%d%d", &left, &height, &right) != EOF) {
        if (right > rightest)
            rightest = right;
        for (int i = left * 2; i <= right * 2; i++) {
            if (height > height_sum[i])
                height_sum[i] = height;
        }
    }
    int flag = 0;
    for (int i = 0; i < rightest * 2; i++) {
        if (height_sum[i] != 0 && flag == 0) {
            flag = 1;
            printf("%d %d ", i / 2, height_sum[i]);
        } else if (height_sum[i] == 0 && flag == 0) {
            continue;
        } else {
            printf("%d %d ", i / 2, height_sum[i]);
        }
        for (int j = i; j < rightest * 2; j++) {
            if (height_sum[i] == height_sum[i + 1]) {
                i++;
            } else {
                break;
            }
        }
    }
    printf("%d 0\n", rightest);
}
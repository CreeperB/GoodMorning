#include <stdio.h>

int main() {
    int times = 0;
    scanf("%d", &times);
    int low_sum = 0;
    int high_sum = 0;
    for (int i = 1; i <= times; i++) {
        printf("Case %d: ", i);
        int low = 0;
        int high = 0;
        int walls = 0;
        scanf("%d", &walls);
        int point = 0;
        int next = 0;
        scanf("%d", &point);
        for (int i = 1; i < walls; i++) {
            scanf("%d", &next);
            if (next <= point) {
                low++;
            } else if (next > point) {
                high++;
            }
            point = next;
        }
        printf("%d %d\n", low, high);
        low_sum += low;
        high_sum += high;
    }
    printf("low jumps: %d\n", low_sum);
    printf("high jumps: %d\n", high_sum);
}
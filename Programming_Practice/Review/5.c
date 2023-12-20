#include <stdio.h>

int main() {
    int points[100] = {0};
    int critical_point[100] = {0};
    int times = 0;
    int count = 0;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d", &points[i]);
    }
    for (int i = 1; i < times - 1; i++) {
        if ((points[i] < points[i - 1] && points[i] < points[i + 1]) || (points[i] > points[i - 1] && points[i] > points[i + 1])) {
            critical_point[count] = i;
            count++;
        }
    }
    if (count <= 1) {
        printf("-1 -1\n");
        return 0;
    }
    int min = 100;
    for (int i = 0; i < count - 1; i++) {
        int distance = critical_point[i + 1] - critical_point[i];
        if (distance < min) {
            min = distance;
        }
    }
    int max = critical_point[count - 1] - critical_point[0];
    printf("%d %d\n", min, max);
}
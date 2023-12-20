#include <stdio.h>

int main() {
    float hour, min;
    while (scanf("%f:%f\n", &hour, &min) && (hour || min)) {
        hour = (hour + min / 60) * 30;
        min = min * 6;
        float degree = (hour - min < 0) ? min - hour : hour - min;
        printf("%.3f\n", (degree > 180) ? 360 - degree : degree);
    }
}
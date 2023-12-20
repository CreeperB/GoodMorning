#include <math.h>
#include <stdio.h>

int main() {
    int start = 0, end = 0;
    while (scanf("%d %d", &start, &end) && !(start == 0 && end == 0)) {
        int count = 0;
        for (int i = start; i <= end; i++) {
            for (int j = 0; j < 340; j++) {
                if (i == (int)pow(j, 2)) {
                    count++;
                    break;
                } else if (i < (int)pow(j, 2)) {
                    break;
                }
            }
        }
        printf("%d\n", count);
    }
}
#include <stdio.h>
#include <string.h>

typedef struct frequency {
    int askii;
    int times;
} frequency;

int main() {
    frequency f[128] = {0};
    char str[1001] = {0};
    while (gets(str)) {
        for (int i = 32; i <= 127; i++) {
            f[i].askii = i;
            f[i].times = 0;
        }
        int length = strlen(str);
        for (int i = 0; i < length; i++) {
            f[str[i]].times++;
        }

        for (int i = 32; i <= 127; i++) {
            int min = f[i].times;
            int min_index = i;
            for (int j = i + 1; j <= 127; j++) {
                if (f[j].times < min) {
                    min_index = j;
                    min = f[j].times;
                }
            }
            frequency temp = f[min_index];
            for (int j = min_index; j > i; j--) {
                f[j] = f[j - 1];
            }
            f[i] = temp;
        }

        for (int j = 1; j <= length; j++) {
            for (int i = 127; i >= 32; i--) {
                if (f[i].times == j) {
                    printf("%d %d\n", f[i].askii, f[i].times);
                }
            }
        }
        puts("");
    }
}
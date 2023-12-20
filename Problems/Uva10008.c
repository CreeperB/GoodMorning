#include <stdio.h>
#include <string.h>

int main() {
    int times = 0;
    scanf("%d", &times);
    getchar();
    char input[1000] = {0};
    int sum[27] = {0};
    int total = 0;
    for (int k = 0; k < times; k++) {
        gets(input);
        int str_len = strlen(input);
        total += str_len;
        for (int i = 0; i < str_len; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                sum[input[i] - 'A']++;
            }
            if (input[i] >= 'a' && input[i] <= 'z') {
                sum[input[i] - 'a']++;
            }
        }
    }
    for (int j = total; j > 0; j--) {
        for (int i = 0; i < 26; i++) {
            if (sum[i] == j) {
                printf("%c %d\n", (char)65 + i, sum[i]);
            }
        }
    }
}
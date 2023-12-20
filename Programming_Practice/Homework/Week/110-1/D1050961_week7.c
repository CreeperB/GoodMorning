#include <stdio.h>
#include <string.h>

int main() {
    int times = 0;
    scanf("%d", &times);  // scan times to input strings
    getchar();            // delete the \n after entering times
    char input[1000] = "";
    int sum[27] = {0};
    for (int k = 0; k < times; k++) {
        gets(input);  // input strings
        int str_len = strlen(input);
        for (int i = 0; i < str_len; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                sum[input[i] - 'A']++;
            }
            if (input[i] >= 'a' && input[i] <= 'z') {
                sum[input[i] - 'a']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (sum[i] > 0) {
            printf("%c %d\n", (char)65 + i, sum[i]);  // print if the alphabet amount is above 0
        }
    }
}
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000] = {0};
    int times = 0;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%s", input);
        int str_len = strlen(input);
        int yes_no = 1;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < str_len; i++) {
            if (input[i] == '(') sum1++;
            if (input[i] == ')') sum1--;
            if (input[i] == '[') sum2++;
            if (input[i] == ']') sum2--;
        }
        if (sum1 != 0 || sum2 != 0) {
            printf("No\n");
            continue;
        }
        for (int i = 0; i < str_len; i++) {
            if (input[i] == ')') {
                if (input[i - 1] == '(') {
                    for (int j = i - 1; i < str_len - 2; i++) {
                        input[j] = input[j + 2];
                    }
                    str_len -= 2;
                    continue;
                } else {
                    yes_no = 0;
                    break;
                }
            } else if (input[i] == ']') {
                if (input[i - 1] == '[') {
                    for (int j = i - 1; i < str_len - 2; i++) {
                        input[j] = input[j + 2];
                    }
                    str_len -= 2;
                    continue;
                } else {
                    yes_no = 0;
                    break;
                }
            }
        }
        printf("%s\n", (yes_no) ? "Yes" : "No");
    }
}
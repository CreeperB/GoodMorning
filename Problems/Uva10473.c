#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000] = {0};
    while (scanf("%s", &input) && input[0] != '-') {
        int length = strlen(input);
        int output = 0;
        if (input[1] == 'x') {
            for (int i = length - 1; i > 1; i--) {
                output += (input[i] - '0') * pow(16, length - i - 1);
            }
            printf("%d\n", output);
        } else {
            for (int i = length - 1; i >= 0; i--) {
                output += (input[i] - '0') * pow(10, length - i - 1);
            }
            printf("0x%X\n", output);
        }
    }
}
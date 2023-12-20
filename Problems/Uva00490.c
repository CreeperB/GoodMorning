#include <stdio.h>
#include <string.h>

int main() {
    char input[101] = {0};
    char output[101][101] = {0};
    int count = 0;
    int max_length = 0;
    while (gets(input)) {
        int length = strlen(input);
        if (length > max_length) {
            max_length = length;
        }
        for (int i = 0; i < length; i++) {
            output[i][count] = input[i];
        }
        count++;
    }
    for (int i = 0; i < max_length; i++) {
        int j = 0;
        for (j = count - 1; j >= 0; j--) {
            if (output[i][j] == 0)
                printf(" ");
            else
                printf("%c", output[i][j]);
        }
        puts("");
    }
}
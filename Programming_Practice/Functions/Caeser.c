#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(int len, int offset, char *input, char *output) {
    for (int i = 0; i < len; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            int temp = input[i];
            temp += offset % 26;
            if ((input[i] >= 'a' && input[i] <= 'z' && temp > 'z')) {
                temp -= 26;
            }
            if (input[i] >= 'A' && input[i] <= 'Z' && temp > 'Z') {
                temp -= 26;
            }
            output[i] = (char)temp;
        } else {
            output[i] = input[i];
        }
    }
}
void decrypt(int len, int offset, char *input, char *output) {
    for (int i = 0; i < len; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            int temp = input[i];
            temp -= offset % 26;
            if (input[i] >= 'a' && input[i] <= 'z' && temp < 'a') {
                temp += 26;
            }
            if (input[i] >= 'A' && input[i] <= 'Z' && temp < 'A') {
                temp += 26;
            }
            output[i] = (char)temp;
        } else {
            output[i] = input[i];
        }
    }
}

int main() {
    char input[1000] = {0};
    printf("Input : ");
    gets(input);
    int len = strlen(input);
    char *output = (char *)malloc(len * sizeof(char));
    int offset = 0;
    printf("Offset : ");
    scanf("%d", &offset);
    int mode = 0;
    printf("Mode : ");
    scanf("%d", &mode);
    void (*func[2])(int, int, char *, char *) = {encrypt, decrypt};
    func[mode - 1](len, offset, input, output);
    printf("Output : ");
    printf("%s", output);
}
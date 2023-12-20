#include <stdio.h>
#include <string.h>

int main() {
    char dict[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";
    char a;
    while (scanf("%c", &a) != EOF) {
        int length = strlen(dict);
        int i = 0;
        for (i = 0; i < length; i++) {
            if (a == dict[i]) {
                printf("%c", dict[i - 2]);
                break;
            }
        }
        if (i == length) {
            printf("%c", a);
        }
    }
}
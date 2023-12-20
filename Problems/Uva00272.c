#include <stdio.h>
#include <string.h>

int main() {
    char sent[1000] = {0};
    int fs = 0;
    while (gets(sent)) {
        int length = 0;
        length = strlen(sent);
        for (int i = 0; i < length; i++) {
            if (sent[i] == '"' && fs == 0) {
                fs = 1;
                printf("``");
            } else if (sent[i] == '"' && fs == 1) {
                fs = 0;
                printf("''");
            } else {
                printf("%c", sent[i]);
            }
        }
        puts("");
    }
}
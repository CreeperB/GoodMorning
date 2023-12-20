#include <stdio.h>
#include <string.h>

FILE *stream;

int main() {
    char name[1000] = {0};
    char keyword[100] = "C語言程式設計";
    int count = 0;
    if ((stream = fopen("zhwiki-latest-all-titles-in-ns0", "r")) == NULL) {
        printf("denied\n");
    }
    while (!feof(stream)) {
        count++;
        fscanf(stream, "%s", name);
        // printf("%s\n", name);
        if (strcmp(name, keyword) == 0)
            printf("%d\n", count);
        fclose(stream);
        break;
    }
}
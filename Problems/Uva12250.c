#include <stdio.h>
#include <string.h>

int main() {
    char arr[100] = {0};
    int count = 0;
    while (scanf("%s", arr) != EOF && strcmp(arr, "#")) {
        count++;
        printf("Case %d: ", count);
        if (!strcmp(arr, "HELLO"))
            printf("ENGLISH\n");
        else if (!strcmp(arr, "HOLA"))
            printf("SPANISH\n");
        else if (!strcmp(arr, "HALLO"))
            printf("GERMAN\n");
        else if (!strcmp(arr, "BONJOUR"))
            printf("FRENCH\n");
        else if (!strcmp(arr, "CIAO"))
            printf("ITALIAN\n");
        else if (!strcmp(arr, "ZDRAVSTVUJTE"))
            printf("RUSSIAN\n");
        else
            printf("UNKNOWN\n");
    }
}
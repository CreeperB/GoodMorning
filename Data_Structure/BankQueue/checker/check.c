// compare ans.txt and output.txt and print AC or WA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp1 = fopen("ans.txt", "r"), *fp2 = fopen("output.txt", "r");
    char str1[100], str2[100];

    while (fgets(str1, 100, fp1) != NULL && fgets(str2, 100, fp2) != NULL)
        if (strcmp(str1, str2) != 0) {
            printf("WA\n");
            return 0;
        }
    if (fgets(str1, 100, fp1) == NULL && fgets(str2, 100, fp2) == NULL)
        printf("AC\n");
    else
        printf("WA\n");
    return 0;
}
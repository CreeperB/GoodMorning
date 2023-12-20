#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *, const void *);

int main() {
    char input1[1001] = {0};
    char input2[1001] = {0};
    while (gets(input1) && gets(input2)) {
        int length1 = strlen(input1);
        int length2 = strlen(input2);
        char output[1001] = {0};
        int out_i = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            int count1 = 0;
            int count2 = 0;
            for (int j = 0; j < length1; j++) {
                if (input1[j] == i) {
                    count1++;
                }
            }
            for (int j = 0; j < length2; j++) {
                if (input2[j] == i) {
                    count2++;
                }
            }
            while (count1-- && count2--) {
                output[out_i++] = i;
            }
        }
        qsort(output, out_i, sizeof(char), compare);
        puts(output);
    }
}

int compare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}
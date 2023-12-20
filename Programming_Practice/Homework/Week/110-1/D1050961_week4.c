#include <stdio.h>

int main() {
    int head = 1;                                           // var head length
    int body;                                               // var body length
    int leg;                                                // var leg length
    int i, j, k;                                            // var variable in loop
    for (i = 0; head != 0 || body != 0 || leg != 0; i++) {  // judge if head, body. leg != 0
        scanf("%d %d %d", &head, &body, &leg);              // input length

        for (j = head; j >= 1; j--) {  // head start
            for (k = 0; k < j; k++) {
                printf(".");
            }  // front dot

            if (j == head) {
                printf("*");
            }  // first line's star

            else if (j == 1) {
                for (k = 1; k < head * 2; k++) {
                    printf("*");
                }
            }  // last line's star

            else {
                printf("*");
                for (k = 1; k < (head - j) * 2; k++) {
                    printf(".");
                }
                printf("*");
            }  // second to last second line's star

            for (k = 0; k < j; k++) {
                printf(".");
            }  // back dot

            printf("\n");  // next line
        }

        for (i = 0; i < body; i++) {  // body start
            printf("..");
            for (j = 1; j < head * 2 - 2; j++) {
                printf("*");
            }
            printf("..\n");
        }

        for (i = 0; i < leg; i++) {  // leg starts
            for (j = 1; j < head; j++) {
                printf(".");
            }
            printf("***");
            for (j = 1; j < head; j++) {
                printf(".");
            }
            printf("\n");
        }
    }
}
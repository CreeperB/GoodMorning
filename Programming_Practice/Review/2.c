#include <stdio.h>

int main() {
    int range = 0;
    int index = 0;
    int prime_number[10000] = {2};
    int prime_index = 0;
    int prime_counter = 3;
    while (scanf("%d %d", &range, &index) != EOF) {
        while (range >= prime_counter) {
            int flag = 0;
            for (int i = 0; i < prime_index; i++) {
                if (prime_counter % prime_number[i] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                prime_number[++prime_index] = prime_counter;
            }
            prime_counter++;
        }
        if (prime_number[index - 1] && prime_number[index - 1] <= range) {
            printf("%d\n", prime_number[index - 1]);
        } else {
            printf("none\n");
        }
    }
}
#include <stdio.h>
#include <string.h>

int main() {
    int times = 0;
    scanf("%d", &times);
    char num_dict[10][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    for (int i = 0; i < times; i++) {
        char string[10] = {0};
        scanf("%s", string);
        for (int nums = 0; nums < 10; nums++) {
            if (strlen(string) != strlen(num_dict[nums])) {
                continue;
            }
            int temp = 0;
            for (int j = 0; j < 5; j++) {
                if (string[j] == num_dict[nums][j] && string[j] != '\0') {
                    temp++;
                }
            }
            if (temp >= strlen(num_dict[nums]) - 1) {
                printf("%d\n", nums + 1);
                break;
            }
        }
    }
}
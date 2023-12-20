#include <stdio.h>

int main() {
    char input_box[100][100] = {0};
    char output_box[100][100] = {0};
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < y; i++) {
        scanf("%s", input_box[i]);
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x - 1; j++) {
            for (int k = 0; k < x - 1 - j; k++) {
                if (input_box[i][k] == '#' && input_box[i][k + 1] == '.') {
                    char temp = input_box[i][k];
                    input_box[i][k] = input_box[i][k + 1];
                    input_box[i][k + 1] = temp;
                }
            }
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            output_box[i][j] = input_box[j][i];
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = y - 1; j >= 0; j--) {
            printf("%c", output_box[i][j]);
        }
        printf("\n");
    }
}
#include <stdio.h>

typedef struct type {
    int number;
    char color;
} type;

int main() {
    type train[1000] = {0};
    int times = 0;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d %s", &train[i].number, &train[i].color);
    }
    int changes = 0;
    for (int i = 0; i < times - 1; i++) {
        for (int j = 0; j < times - 1 - i; j++) {
            if (train[j].number >= train[j + 1].number) {
                if (train[j].number == train[j + 1].number && train[j].color > train[j + 1].color) {
                    continue;
                }
                changes++;
                type temp = train[j];
                train[j] = train[j + 1];
                train[j + 1] = temp;
            }
        }
    }
    printf("%d\n", changes);
    for (int i = 0; i < times; i++) {
        printf("%d %c\n", train[i].number, train[i].color);
    }
}
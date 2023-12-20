#include <stdio.h>

int main() {
    int array[100000] = {0};
    int count = 0;
    while (1) {
        scanf("%d", &array[count]);
        count++;
        if (getchar() == '\n') {
            break;
        }
    }
     for (int i = 0; i < count - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[count - 1]);
}
#include "bubble.h"
#define size 10

int main() {
    int arr[size] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    puts("Data items in original order");
    for (int i = 0; i < size; i++) {
        printf("%d%c", arr[i], " \n"[i == size - 1]);
    }
    bubble(arr, size, ascending);
    puts("Data items in ascending order");
    for (int i = 0; i < size; i++) {
        printf("%d%c", arr[i], " \n"[i == size - 1]);
    }
    bubble(arr, size, decending);
    puts("Data items in decending order");
    for (int i = 0; i < size; i++) {
        printf("%d%c", arr[i], " \n"[i == size - 1]);
    }
}
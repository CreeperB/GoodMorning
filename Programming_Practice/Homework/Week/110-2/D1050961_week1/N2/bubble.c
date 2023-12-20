#include "bubble.h"

void bubble(int *arr, int size, int compare(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (compare(arr[j], arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int ascending(int a, int b) {
    return b < a;
}
int decending(int a, int b) {
    return b > a;
}
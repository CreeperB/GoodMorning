#include "bubble.h"

int total(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double average(int *arr, int size) {
    return (double)total(arr, size) / size;
}

int medium(int *arr, int size) {
    if (size % 2) {
        return arr[size / 2 + 1];
    } else {
        return (arr[size / 2] + arr[size / 2 + 1]) / 2;
    }
}

int frequency_count(int *arr, int frequent, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == frequent) {
            sum++;
        }
    }
    return sum;
}
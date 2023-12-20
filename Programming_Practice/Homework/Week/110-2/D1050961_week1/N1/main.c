#include "bubble.h"
#include "calculate.h"
#define size 100

int main() {
    int frequency[10] = {0};
    int arr[size] =
        {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
         7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
         6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
         7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
         6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
         7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
         5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
         7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
         7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
         4, 5, 6, 1, 6, 5, 7, 8, 7, 9};
    printf("The total is %d\n", total(arr, size));
    printf("The average is %.2lf\n\n", average(arr, size));
    bubble(arr, size);
    puts("The sorted arr is:");
    for (int i = 1; i <= size; i++) {
        printf("%d%c", arr[i - 1], "\n "[i % 10 != 0]);
    }
    puts("");
    printf("The medium is %d\n\n", medium(arr, size));
    printf("%8s%15s\n", "Rating", "Frequency");
    for (int i = 0; i <= 9; i++) {
        printf("%8d%15d\n", i, frequency_count(arr, i, size));
    }
}
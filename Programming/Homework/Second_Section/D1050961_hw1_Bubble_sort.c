#include <stdio.h>

int bubble_sort(int *, int);
void swap(int *, int *);
void print_array(int *, int);

int main() {
    int array[100000] = {0};
    int array_size = 0;
    while (1) {  // get array
        scanf("%d", &array[array_size]);
        array_size++;
        if (getchar() == '\n') {
            break;
        }
    }
    bubble_sort(array, array_size);
    print_array(array, array_size);
}

int bubble_sort(int *array, int array_size) {
    for (int pass = 1; pass < array_size; pass++) {                                        // scan from first to last
        for (int compare_index = 0; compare_index < array_size - pass; compare_index++) {  // compare the two elements to see which one is greater
            if (array[compare_index] > array[compare_index + 1]) {
                swap(&array[compare_index], &array[compare_index + 1]);  // swap two elements if the next element is smaller than the compare one
            }
        }
    }
    return array;
}

void swap(int *address_a, int *address_b) {  // swap two elements
    int temp = *address_a;
    *address_a = *address_b;
    *address_b = temp;
}

void print_array(int *array, int array_size) {  // print array
    for (int i = 0; i < array_size; i++)
        printf("%d%c", array[i], i == array_size - 1 ? '\n' : ' ');
}
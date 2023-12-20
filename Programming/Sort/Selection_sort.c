#include <stdio.h>

int *selection_sort(int *, int);
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
    selection_sort(array, array_size);
    print_array(array, array_size);
}

int *selection_sort(int *array, int array_size) {
    for (int compare_index = 0; compare_index < array_size; compare_index++) {
        int min = array[compare_index];  // set min as the first element
        int min_index = compare_index;   // set min_index as the first index
        for (int find_min = compare_index + 1; find_min < array_size; find_min++) {
            if (array[find_min] < min) {
                min = array[find_min];  // set new min as the element which is smaler than the original one
                min_index = find_min;   // set new min_index as the element_index
            }
        }
        swap(&array[compare_index], &array[min_index]);  // swap the array[compare_index] with the min one
    }
    return *array;
}

void swap(int *address_a, int *address_b) {  // swap two elements
    int temp = *address_a;
    *address_a = *address_b;
    *address_b = temp;
}

void print_array(int *array, int count) {  // print array
    for (int i = 0; i < count; i++)
        printf("%d%c", array[i], i == count - 1 ? '\n' : ' ');
}
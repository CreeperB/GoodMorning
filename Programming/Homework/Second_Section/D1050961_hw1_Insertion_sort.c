#include <stdio.h>

int insertion_sort(int *, int);
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
    insertion_sort(array, array_size);
    print_array(array, array_size);
}

int insertion_sort(int *array, int array_size) {
    for (int compare_index = 1; compare_index < array_size; compare_index++) {
        int key = array[compare_index];  // set key from first to last
        int compare_key;
        for (compare_key = compare_index - 1; compare_key >= 0 && array[compare_key] > key; compare_key--) {
            array[compare_key + 1] = array[compare_key];  // move left if array[compare_key] is greater than the key
        }
        array[compare_key + 1] = key;  // move key back
    }
    return array;
}

void print_array(int *array, int array_size) {  // print array
    for (int i = 0; i < array_size; i++)
        printf("%d%c", array[i], i == array_size - 1 ? '\n' : ' ');
}
#include <stdio.h>

void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);
void printArray(int*, int);

int main(void) {
    int arr[100000] = {0};
    int array_size = 0;
    while (1) {  // get array
        scanf("%d", &arr[array_size]);
        array_size++;
        if (getchar() == '\n') {
            break;
        }
    }
    quickSort(arr, 0, array_size - 1);
    printArray(arr, array_size);
    return 0;
}

/*
void quickSort(int* num, int start, int end) {  // with one function
    if (start >= end)
        return;
    int pivot = num[end];
    int i = start, k = end;
    while (i < k) {
        for (i; num[i] <= pivot && i < k; i++)
            ;
        num[k] = num[i];
        num[i] = pivot;
        for (k; num[k] >= pivot && i < k; k--)
            ;
        num[i] = num[k];
        num[k] = pivot;
    }
    quickSort(num, start, i - 1);
    quickSort(num, k + 1, end);
}
*/

void quickSort(int* arr, int start, int end) {
    if (start < end) {                           // if start == end, the sort ends
        int pivot = partition(arr, start, end);  // find the pivot point

        quickSort(arr, start, pivot - 1);  // sort the array on the left side of the pivot
        quickSort(arr, pivot + 1, end);    // sort the array on the right side of the pivot
    }
}

int partition(int* arr, int start, int end) {
    int pivot = arr[end];        // set pivot as the end element
    int left_index = start - 1;  // locate the left_index

    for (int compare_index = start; compare_index < end; compare_index++) {
        if (arr[compare_index] < pivot) {
            left_index++;
            swap(&arr[left_index], &arr[compare_index]);  // move left if &arr[compare_index] is smaller than the pivot
        }
    }
    swap(&arr[left_index + 1], &arr[end]);  // left_index + 1 == the location of pivot, swap pivot with the element at left_index + 1
    return left_index + 1;                  // return the location of pivot
}

void swap(int* address_a, int* address_b) {  // swap two elements
    int temp = *address_a;
    *address_a = *address_b;
    *address_b = temp;
}

void printArray(int* array, int array_size) {  // print array
    for (int i = 0; i < array_size; i++)
        printf("%d%c", array[i], i == array_size - 1 ? '\n' : ' ');
}
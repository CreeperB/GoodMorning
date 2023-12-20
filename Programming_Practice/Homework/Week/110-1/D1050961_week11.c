#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coordinate {  // define struct cooordinate as a type
    int x;
    int y;
    int z;
} coordinate;

int compare(const void *, const void *);

int main(void) {
    coordinate data[1000];  // set data array as coordinate type
    int times = 0;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d%d%d", &data[i].x, &data[i].y, &data[i].z);  // input datas
    }
    qsort(data, times, sizeof(coordinate), compare);  // use qsort function to sort datas
    for (int i = 0; i < times; i++) {
        printf("%d %d %d%s", data[i].x, data[i].y, data[i].z, (i != times - 1) ? "\n----------\n" : "\n");  // output the sorted data and judge if it's the last row
    }
}

int compare(const void *a, const void *b) {
    coordinate a_ = *(coordinate *)a;  // change a's type to cooordinate
    coordinate b_ = *(coordinate *)b;  // change b's type to cooordinate
    if (a_.x == b_.x)                  // if a's x equals to b's x then compare the next element
        if (a_.y == a_.y)              // if a's y equals to b's y then compare the next element
            return a_.z - b_.z;        // return the subtraction value of a's z and b's z
        else
            return a_.y - b_.y;  // return the subtraction value of a's y and b's y
    else
        return a_.x - b_.x;  // return the subtraction value of a's x and b's x
}
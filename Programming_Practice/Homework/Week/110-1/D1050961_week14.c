#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int *a, int *b) {  // put element to output
    *b = *a;
}

/*
void reverse(int **input, int **output, int row, int column) {
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            output[i][j] = input[j][i];
        }
    }
}
*/

int main() {
    int row, column;
    scanf("%d %d", &row, &column);  // input row and column

    int **input = (int **)calloc(row, sizeof(int *));  // calloc input array
    for (int i = 0; i < row; i++) {
        input[i] = (int *)calloc(column, sizeof(int));
    }

    int **output = (int **)calloc(column, sizeof(int *));  // calloc output array
    for (int i = 0; i < column; i++) {
        output[i] = (int *)calloc(row, sizeof(int));
    }

    for (int i = 0; i < row; i++) {  // get input array
        for (int j = 0; j < column; j++) {
            scanf("%d", &input[i][j]);
        }
    }
    for (int i = 0; i < row; i++) {  // reverse input array to output array
        for (int j = 0; j < column; j++) {
            reverse(&input[i][j], &output[j][i]);  // calling function one by one
        }
    }
    /*
    reverse(input, output, row, column); // calling function at once
    */
    for (int i = 0; i < column; i++) {  // print output array
        for (int j = 0; j < row; j++) {
            printf("%d%c", output[i][j], " \n"[j == row - 1]);
        }
    }
}
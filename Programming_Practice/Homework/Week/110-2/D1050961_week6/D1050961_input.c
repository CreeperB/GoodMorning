#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *hw = fopen("D1050961.dat", "wb");  // wb: write binary
    int num[10] = {0};
    scanf("%d", num);                                              // input num
    fwrite("D1050961\n", sizeof(char), strlen("D1050961\n"), hw);  // write D1050961
    fwrite(num, sizeof(int), 1, hw);                               // write num
    fwrite("\n", sizeof(char), 1, hw);                             // write \n
    fclose(hw);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* file = fopen("D1050961.dat", "rb+");  // rb+: read and write.
    char id_input[10];
    char binary[100] = {0};
    int num, temp;
    fseek(file, 0, SEEK_SET);                  // SEEK_SET: set file pointer to the beginning of the file.
    fread(id_input, sizeof(char), 8, file);    // fread: read id from file.
    fseek(file, 1, SEEK_CUR);                  // set file pointer behind '\n'.
    fread(&num, sizeof(int), 1, file);         // fread: read num from file.
    temp = num;                                // temp: num.
    printf("%s\nInput: %d\n", id_input, num);  // print id and num.
    int i = 0;
    while (temp) {  // binary: num to binary.
        binary[i] = temp % 2 + '0';
        temp /= 2;
        i++;
    }
    int bin_len = i;         // bin_len: binary length.
    fprintf(file, "BIN: ");  // fprintf: write binary to file.
    printf("BIN: ");
    while (i) {
        fprintf(file, "%c", binary[--i]);
        printf("%c", binary[i]);
    }
    fprintf(file, "\n");                        // fprintf: write \n to file.
    printf("\n");                               // printf: write \n.
    fprintf(file, "OCT: %*o\n", bin_len, num);  // write octal to file.
    printf("OCT: %*o\n", bin_len, num);         // write octal to screen.
    fprintf(file, "DEC: %*d\n", bin_len, num);  // write decimal to file.
    printf("DEC: %*d\n", bin_len, num);         // write decimal to screen.
    fprintf(file, "HEX: %*x\n", bin_len, num);  // write hexadecimal to file.
    printf("HEX: %*x\n", bin_len, num);         // write hexadecimal to screen.
}
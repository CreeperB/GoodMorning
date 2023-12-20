#include <stdio.h>

int lower(int character) {
    if (character >= 65 && character <= 90)  // judge if the character is between A to Z
        return character + 32;               // return the lower character
    else
        return character;  // return the original character
}
int upper(int character) {
    if (character >= 97 && character <= 122)  // judge if the character is between a to z
        return character - 32;                // return the upper character
    else
        return character;  // return the original character
}
int string_length(char string[]) {
    int strlen = 0;
    for (int i = 0; string[i] != '\0'; i++) {  // strlen++ until search to the \0 at the end of the string
        strlen++;
    }
    return strlen;  // return the length of the string
}

int main() {
    char string[] = "HellO? World!!!/^^";
    printf("%s\n", string);
    printf("string length: %d\n", string_length(string));
    for (int i = 0; i < string_length(string); i++) {
        printf("%c", lower(string[i]));
    }

    printf("\n");
    for (int i = 0; i < string_length(string); i++) {
        printf("%c", upper(string[i]));
    }
    printf("\n");
}

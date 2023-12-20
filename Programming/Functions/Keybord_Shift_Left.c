#include <stdio.h>
#include <string.h>

int main(){
    char sentence[50] = {0};
  	char character;
    while (gets(sentence)){
        for(int i = 0; i < strlen(sentence); i++){
            switch (sentence[i]){
            case 'W':
                sentence[i] = 'Q';
                break;
            case 'E':
                sentence[i] = 'W';
                break;
            case 'R':
                sentence[i] = 'E';
                break;
            case 'T':
                sentence[i] = 'R';
                break;
            case 'Y':
                sentence[i] = 'T';
                break;
            case 'U':
                sentence[i] = 'Y';
                break;
            case 'I':
                sentence[i] = 'U';
                break;
            case 'O':
                sentence[i] = 'I';
                break;
            case 'P':
                sentence[i] = 'O';
                break;
            case '[':
                sentence[i] = 'P';
                break;
            case ']':
                sentence[i] = '[';
                break;
            case '\\':
                sentence[i] = ']';
                break;
            case 'S':
                sentence[i] = 'A';
                break;
            case 'D':
                sentence[i] = 'S';
                break;
            case 'F':
                sentence[i] = 'D';
                break;
            case 'G':
                sentence[i] = 'F';
                break;
            case 'H':
                sentence[i] = 'G';
                break;
            case 'J':
                sentence[i] = 'H';
                break;
            case 'K':
                sentence[i] = 'J';
                break;
            case 'L':
                sentence[i] = 'K';
                break;
            case ';':
                sentence[i] = 'L';
                break;
            case '\'':
                sentence[i] = ';';
                break;
            case 'X':
                sentence[i] = 'Z';
                break;
            case 'C':
                sentence[i] = 'X';
                break;
            case 'V':
                sentence[i] = 'C';
                break;
            case 'B':
                sentence[i] = 'V';
                break;
            case 'N':
                sentence[i] = 'B';
                break;
            case 'M':
                sentence[i] = 'N';
                break;
            case ',':
                sentence[i] = 'M';
                break;
            case '.':
                sentence[i] = ',';
                break;
            case '/':
                sentence[i] = '.';
                break;
            case '1':
                sentence[i] = '`';
                break;
            case '2':
                sentence[i] = '1';
                break;
            case '3':
                sentence[i] = '2';
                break;
            case '4':
                sentence[i] = '3';
                break;
            case '5':
                sentence[i] = '4';
                break;
            case '6':
                sentence[i] = '5';
                break;
            case '7':
                sentence[i] = '6';
                break;
            case '8':
                sentence[i] = '7';
                break;
            case '9':
                sentence[i] = '8';
                break;
            case '0':
                sentence[i] = '9';
                break;
            case '-':
                sentence[i] = '0';
                break;
            case '=':
                sentence[i] = '-';
                break;
            default:
                break;
            }
        }
        printf("%s\n", sentence);
    }
}
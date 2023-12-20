#include <stdio.h>

int main(){
    int a;
    int switc = 0;
    scanf("%d", &a);
    for(int i = 0; a != 0; i++){
        if(switc == 0 && a % 10 != 0){
            switc = 1;
        }
        if(switc == 1){
            printf("%d", a % 10);
        }
        a = (a - a % 10) / 10;
    }
}
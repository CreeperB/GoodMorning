#include <math.h>
#include <stdio.h>

int main() {
    char id[7];                              // var id as array in 7 column
    int uid;                                 // var uid
    int check_num;                           // var check number
    int i;                                   // var i in loop
    int sum;                                 // var sum
    int temp, temp1;                         // var temp
    int check_rule[6] = {8, 7, 6, 8, 7, 6};  // var check rule as array in 6 column
    int id_temp;
    printf("輸入學號(不含英文字母):");
    scanf("%d", &uid);  // input student id

    id_temp = 0;
    for (i = 6; i >= 0; i--) {  // put student id into array
        id[i] = uid % 10;
        uid /= 10;
    }

    sum = 0;
    for (i = 0; i <= 5; i++) {  // substitute student id into the check number rule
        temp = id[i] * check_rule[i];
        sum += temp / 10 + temp % 10;
    }

    check_num = id[6];  // check if the result is conform to the check nunber
    if ((10 - (sum % 10)) % 10 == check_num) {
        printf("此學號存在\n");
    } else {
        printf("此學號不存在\n");
    }
}
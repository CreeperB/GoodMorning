#include <math.h>
#include <stdio.h>

int id[7];  // var id as array in 7 column
int id_temp(int i) {
    for (int j = 6; j >= 0; j--) {  // put student id into array
        id[j] = i % 10;
        i /= 10;
    }
}

int temp, temp1;                         // var temp in rule
int check_rule[6] = {8, 7, 6, 8, 7, 6};  // var check rule as array in 6 column
int rule() {
    int sum = 0;                    // var sum in rule
    for (int j = 0; j <= 5; j++) {  // substitute student id into the check number rule
        temp = id[j] * check_rule[j];
        sum += temp / 10 + temp % 10;
    }
    return sum;
}

int odd = 0;                   // var sum of odd
int even = 0;                  // var sum of even
int i;
int odd_even(int check_num) {  // var check number
    if ((10 - (rule() % 10)) % 10 == check_num) {
        if(i > 1050869 && i < 1050961){
            printf("%d\n", i);
        }
        if (check_num % 2 == 1) {
            odd += 1;
        } else {
            even += 1;
        }
    }
}

int main() {
    for (i = 700000; i <= 1099999; i++) {  // looping data for student id's possibility
        id_temp(i);
        rule();
        odd_even(id[6]);
    }
    printf("odd number:%d\n", odd);
    printf("even number:%d\n", even);
}
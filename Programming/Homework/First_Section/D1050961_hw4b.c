#include <math.h>
#include <stdio.h>

int main() {
    int id[7];                               // var id as array in 7 column
    int check_num;                           // var check number
    int i, j;                                // var  in loop
    int id_temp;                             // var temp in id
    int sum;                                 // var sum in rule
    int temp, temp1;                         // var temp in rule
    int odd = 0;                             // var sum of odd
    int even = 0;                            // var sum of even
    int check_rule[6] = {8, 7, 6, 8, 7, 6};  // var check rule as array in 6 column

    for (i = 700000; i <= 1099999; i++) {  // looping data for student id's possibilities

        id_temp = i;
        for (j = 6; j >= 0; j--) {  // put student id into array
            id[j] = id_temp % 10;
            id_temp /= 10;
        }

        sum = 0;
        for (j = 0; j <= 5; j++) {  // substitute student id into the check number rule
            temp = id[j] * check_rule[j];
            temp1 = temp / 10 + temp % 10;
            sum += temp1;
        }

        check_num = id[6];  // check if the result is conform to the check nunber
        if ((10 - (sum % 10)) % 10 == check_num) {
            if (check_num % 2 == 1) {
                odd += 1;
            } else {
                even += 1;
            }
        }
    }
    printf("odd number:%d\n", odd);
    printf("even number:%d\n", even);
}
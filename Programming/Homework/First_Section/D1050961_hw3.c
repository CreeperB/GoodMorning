#include <stdio.h>
#include <time.h>

int main() {
    int id;              //設定學號變數
    int year;            //設定入學年份變數
    int serial＿number;  //設定學號內流水號變數
    int odd_even;        //設定學號尾數奇偶數變數
    int week;            //設定這週是第幾週變數
    char identity;

    time_t seconds;
    seconds = time(NULL);
    week = (seconds / 3600 / 24 + 4) / 7 - 2697;
    //前面code看不懂，但是運用從1970到現在的秒數推算這週為逢甲開學第幾週
    //計算1970年到現在之秒數換算成週數後再扣掉逢甲開學前已經過的週數
    //計算week時的+4是因為1970/1/1為禮拜四所以要計算偏差
    //+4的話為設定禮拜日為一週的開始，+3的話為設定禮拜一為一週的開始
    //+4/-3或+3/-4都可以，差在後面扣掉的週數而已

    printf("輸入你的學號(含大寫英文字母):");
    scanf("%c%d", &identity, &id);               //輸入學號
    year = id / 100000;                          //計算入學年份
    serial＿number = (id - year * 100000) / 10;  //計算流水號
    odd_even = id % 10;                          //計算學號是否為單雙數

    switch (identity) {  //判斷學生身份
        case 'D':
            printf("你是大學生\n");
            break;
        case 'E':
            printf("你是進修生\n");
            break;
        case 'M':
            printf("你是碩士生\n");
            break;
        case 'P':
            printf("你是博士生\n");
        default:
            printf("無法辨認身份\n");  //字母部分有誤，中斷程式
            return 0;
    }

    if (year < 50) {
        year += 100;
        //若年份判定小於50則判定為100年後的學生
        //會設定為50是因為逢甲創校於民國50年，所以不會有人在50年前入校
    }
    printf("%d年入學\n", year);
    printf("%d年畢業\n", year + 4);  //計算4年後畢業年份

    if (serial＿number / 1000 <= 4) {  //流水號第一位為0~4者
        printf("入學方式可能為特殊選材/繁星推薦/海外申請\n");
    } else if (serial＿number / 1000 > 4 && serial＿number / 1000 <= 8) {  //流水號第一位為5~8者
        printf("入學方式可能為申請入學/四技二專徵選\n");
    } else {  //流水號第一位為9者
        printf("入學方式可能為考試入學\n");
    }

    if (odd_even % 2 == 1 && week % 2 == 1) {  //單號單週情況
        printf("這週為第%d週，學號尾數單號要實體上課\n", week);
    } else if (odd_even % 2 == 1 && week % 2 == 0) {  //單號雙週情況
        printf("這週為第%d週，學號尾數單號要線上上課\n", week);
    } else if (odd_even % 2 == 0 && week % 2 == 1) {  //雙號單週情況
        printf("這週為第%d週，學號尾數雙號要線上上課\n", week);
    } else {  //雙號雙週情況
        printf("這週為第%d週，學號尾數雙號要實體上課\n", week);
    }
}
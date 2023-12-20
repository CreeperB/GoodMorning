#include <stdio.h>
#include <time.h>
int flag = 0;
int flag_identity = 0;

void ASKII_art() {
    printf(
        "\n"
        "            $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        "          $$$____$$$_____$$$$$$$$$$$$$$$$$\n"
        "       $$$__$$__$$_$$$$_$$$$___$$$$$$_$$$$$\n"
        "      $$$__$$$__$$__$$$$_$$$$___$$$$$$__$$$$$$\n"
        "    $$$___$$$___$$_$$$$$_$$$$____$$$$$$___$$$$$\n"
        "   $$___$$$$$__$$__$$$$$_$$$$____$$$$$$$____$$$$$\n"
        " $$____$$$$$___$$__$$$$$_$$$$_____$$$$$$_____$$$$$$\n"
        "$$$$$_____$$__$$__$$$$$$_$$$$_____$$$$$$$$$$$$$$$$$$\n"
        "  $$$$$$$____$$$__$$$$$$_$$$$___$$$$$$$$$$$$$$$$$$\n"
        "   $$$___$$$$$$__________$$$$$$$$$$$$$$$$$$$$$$$$\n"
        "     $$__$___$$$$$$$$$$$$$$$$$$$$$$$$$$$$$__$$$\n"
        "       $$_$$$_$$_________$$$$$$$$$$$$$$___$$$$\n"
        "        $$__$$_$$__$$$$$_$$$______$$$$___$$$\n"
        "          $$_$$_$$__$$$$_$$$_____$$$$__$$$\n"
        "           $$_$$_$$_$$$$__$$____$$$$__$$$\n"
        "            $$_$_$$_$$$__$$____$$$$_$$$\n"
        "              $_$_$$_$$__$$__$$$$_$$$\n"
        "                $$__$__$__$$__$$$$$$\n"
        "                  $__$____$$_$$$$$$\n"
        "                   $$_$___$$$$$$$\n"
        "                     $$$__$$$$$$\n"
        "                      $$$_$$$$\n"
        "                       $$$$$\n"
        "                        $$$\n"
        "                         $\n"
        "                Here's your diamond.\n\n");
}

void BMI() {
    float Height;  //定義變數Height
    float Weight;  //定義變數Weight
    float BMI;     //定義變數BMI
    printf("Input your height(cm):");
    scanf("%f", &Height);   //接收身高值
    Height = Height / 100;  //公分轉公尺
    printf("Input your weight(kg):");
    scanf("%f", &Weight);               //接收體重值
    BMI = Weight / (Height * Height);   //計算BMI
    printf("Your BMI is %.1f\n", BMI);  // BMI值輸出

    if (BMI < 18.5)  //設定過輕體重
    {
        printf("You're too thin.\n");
        printf("Eat more.\n");
    } else if (18.5 <= BMI && BMI < 24)  //設定標準體重
    {
        printf("Just right.\n");
        printf("Keep going on.\n");
    } else if (24 <= BMI && BMI < 27)  //設定過重標準
    {
        printf("You're a bit heavy.\n");
        printf("Go do some exercise.\n");
    } else if (27 <= BMI && BMI < 30)  //設定輕度肥胖標準
    {
        printf("You're a bit too heavy.\n");
        printf("Eat less and do more exercise.\n");
    } else if (30 <= BMI && BMI < 35)  //設定中度肥胖標準
    {
        printf("You're such a heavy guy.\n");
        printf("You should really get some help.\n");
    } else  //設定過度肥胖標準
    {
        printf("The King of FATMAN\n");
        printf("Nah. Just try to stay alive.\n");
    }
}

void check_id(int uid) {
    char id[7];                              // var id as array in 7 column
    int check_num;                           // var check number
    int i;                                   //var i in loop
    int sum;                                 // var sum
    int temp, temp1;                         // var temp
    int check_rule[6] = {8, 7, 6, 8, 7, 6};  // var check rule as array in 6 column
    int id_temp;

    id_temp = 0;
    for (i = 6; i >= 0; i--) {  // put student id into array
        id[i] = uid % 10;
        uid /= 10;
    }

    sum = 0;
    for (i = 0; i <= 5; i++) {  // substitute student id into the check number rule
        temp = id[i] * check_rule[i];
        temp1 = temp - temp / 10 * 10 + temp / 10;
        sum += temp1;
    }

    check_num = id[6];  // check if the result is conform to the check nunber
    if ((10 - (sum % 10)) % 10 == check_num) {
        printf("哎呦～原來你是逢甲");
    } else {
        printf("假逢甲人滾啦！\n");
        flag = 1;
    }
}

void id_data(int id, char identity) {
    int year;            //設定入學年份變數
    int serial＿number;  //設定學號內流水號變數
    int odd_even;        //設定學號尾數奇偶數變數
    int week;            //設定這週是第幾週變數

    time_t seconds;
    seconds = time(NULL);
    week = (seconds / 3600 / 24 + 4) / 7 - 2697;
    //前面code看不懂，但是運用從1970到現在的秒數推算這週為逢甲開學第幾週
    //計算1970年到現在之秒數換算成週數後再扣掉逢甲開學前已經過的週數
    //計算week時的+4是因為1970/1/1為禮拜四所以要計算偏差
    //+4的話為設定禮拜日為一週的開始，+3的話為設定禮拜一為一週的開始
    //+4/-3或+3/-4都可以，差在後面扣掉的週數而已

    year = id / 100000;                          //計算入學年份
    serial＿number = (id - year * 100000) / 10;  //計算流水號
    odd_even = id % 10;                          //計算學號是否為單雙數

    switch (identity) {  //判斷學生身份
        case 'D':
            printf("大學生\n");
            break;
        case 'E':
            printf("進修生\n");
            break;
        case 'M':
            printf("碩士生\n");
            break;
        case 'P':
            printf("博士生\n");
        default:
            printf("人...嗎？怎麼無法辨別你的身份？？\n");  //字母部分有誤，中斷程式
            flag_identity = 1;
    }
    if (flag_identity == 0) {
        if (year < 50) {
            year += 100;
            //若年份判定小於50則判定為100年後的學生
            //會設定為50是因為逢甲創校於民國50年，所以不會有人在50年前入校
        }
        printf("在%d年入學\n", year);
        printf("預計於%d年畢業\n", year + 4);  //計算4年後畢業年份

        if (serial＿number / 1000 <= 4) {  //流水號第一位為0~4者
            printf("你的入學方式可能為特殊選材/繁星推薦/海外申請\n");
        } else if (serial＿number / 1000 > 4 && serial＿number / 1000 <= 8) {  //流水號第一位為5~8者
            printf("你的入學方式可能為申請入學/四技二專徵選\n");
        } else {  //流水號第一位為9者
            printf("你的入學方式可能為考試入學\n");
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
}

void check_id_all() {
    int id[7];                               // var id as array in 7 column
    int check_num;                           // var check number
    int i, j;                                // var  in loop
    int id_temp;                             // var temp in id
    int sum;                                 // var sum in rule
    int temp, temp1;                         // var temp in rule
    int odd = 0;                             // var sum of odd
    int even = 0;                            // var sum of even
    int check_rule[6] = {8, 7, 6, 8, 7, 6};  // var check rule as array in 6 column

    for (i = 1000000; i <= 1099999; i++) {  // looping data for student id's possibilities

        id_temp = i;
        for (j = 6; j >= 0; j--) {  // put student id into array
            id[j] = id_temp % 10;
            id_temp /= 10;
        }

        sum = 0;
        for (j = 0; j <= 5; j++) {  // substitute student id into the check number rule
            temp = id[j] * check_rule[j];
            temp1 = temp - temp / 10 * 10;
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
    printf("今年學號奇數號有效數有%d筆\n", odd);
    printf("今年學號偶數號有效數有%d筆\n", even);
    if (odd == even) {
        printf("想不到奇偶數數量一樣吧～（還是其實有想到...\n");
    } else {
        printf("不相等...？怎麼可能？？");
    }
}

int main() {
    char identity;
    int id;
    char blank;
    printf("Press enter for a diamond...");
    scanf("%c", &blank);
    if (blank == '\n') {
        ASKII_art();
    } else {
        printf("你的損失\n");
    }
    printf("底下你將發現自己屬於何種身材...\n");
    BMI();
    while (getchar() != '\n') {
    }
    printf("輸入你的學號(含大寫英文字母):");
    scanf("%c%d", &identity, &id);  //輸入學號
    check_id(id);                   //呼叫檢查程式
    if (flag == 0) {
        id_data(id, identity);
        if (flag_identity == 0) {
            printf("跟你說個逢甲人才能知道的秘密喔\n");
            printf("Press enter to see the secret...");
            getchar();
            scanf("%c", &blank);
            if (blank == '\n') {
                check_id_all();
            } else {
                printf("不要拉倒\n");
            }
        } else {
            printf("你到底是誰...?");
        }
    } else {
        printf("請你離開謝謝\n");
    }
}
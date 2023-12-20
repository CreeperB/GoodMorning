#include <stdio.h>

int main() {
    float Height;  //定義變數Height
    float Weight;  //定義變數Weight
    float BMI;     //定義變數BMI
    printf("Height(cm):");
    scanf("%f", &Height);   //接收身高值
    Height = Height / 100;  //公分轉公尺
    printf("Weight(kg):");
    scanf("%f", &Weight);              //接收體重值
    BMI = Weight / (Height * Height);  //計算BMI
    printf("%.1f\n", BMI);             // BMI值輸出

    if (BMI < 18.5)  //設定過輕體重
    {
        printf("Too thin.\n");
        printf("Eat more.\n");
    } else if (18.5 <= BMI && BMI < 24)  //設定標準體重
    {
        printf("Just right.\n");
        printf("Keep going on.\n");
    } else if (24 <= BMI && BMI < 27)  //設定過重標準
    {
        printf("A bit heavy.\n");
        printf("Go do some exercise.\n");
    } else if (27 <= BMI && BMI < 30)  //設定輕度肥胖標準
    {
        printf("A bit too heavy.\n");
        printf("Eat less and do more exercise.\n");
    } else if (30 <= BMI && BMI < 35)  //設定中度肥胖標準
    {
        printf("Such a heavy guy.\n");
        printf("You should really get some help.\n");
    } else {  //設定過度肥胖標準
        printf("The King of FATMAN\n");
        printf("Nah. Just try to stay alive.\n");
    }
}

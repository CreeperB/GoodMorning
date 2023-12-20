#include <stdio.h>

int main()
{
    char input[100] = {0};
    int count = 0;
    char val;
    scanf("%d", &count); //字串長度
    getchar();
    for (int i = 0; i < count; i++)
    {
        scanf("%c", &input[i]); //字串掃入陣列
    }
    getchar();
    scanf("%c", &val); //刪除項目
    for (int i = 0; i < count; i++)
    {
        if (val == input[i]) //判定相同值
        {
            for (int j = i; j <= count; j++)
            {
                input[j] = input[j + 1]; //以相同欄起將該陣列向左搬移
            }
            if (val == input[i])
            {
                i -= 1; //左移後仍相同則重複該迴圈(不要讓i增加)
            }
        }
    }
    printf("%s", input);
}
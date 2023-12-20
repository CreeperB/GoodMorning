#include <stdio.h>

int main(void)
{
 
    char a = 0;
     char string[][12] = {
        "hello,world",
        "hello      ",
        "      world", 
        "he         ",
        "he      r d", 
        "   lo w    ",  
        "    o    ld", 
        "hello,world",
    };
    printf("Please press enter...\n");

    for (int i = 0 ; i < 8 ; i++)
    {
        scanf("%c",&a);
        printf("%s",string[i]);
    }
    return 0;
}

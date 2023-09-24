#include <string.h>
#include <stdio.h>
int main()
{
    char c[5] = {'c', 'h', 'i', 'n', 'a'};
    //数组名是数组的首地址, 就是第一个元素的地址。
    //字符串结束符\0.
    char a[]="good";
    printf("%s", c);
    printf("\n");
    //strcat(),完成字符串的拼接
    gets(a);
    gets(c);
    strcat(a,c);
    printf("%c", strcat(a,c));
    return 0;
}
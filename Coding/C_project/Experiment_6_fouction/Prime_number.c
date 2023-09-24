// 写一个判断素数的函数，形参为一个整数，当该整数是素数时,
// 返回1，否则返回0。在主函数中输入一个整数，输入是否是素数的信息。
// （素数：只能被1和自身整除的数）
#include <stdio.h>
int prime(int a);
int main()
{
    int a;
    scanf("%d", &a);
    int p = prime(a);
    printf("%d", p);
    return 0;
}
// 从2到a-1除a，如果没有余数则为素数
int prime(int a)
{
    int i;
    for (i = 2; i < a; i++)
    {
        if (a % i != 0)
            return 1;
        else
            return 0;
    }
}
#include <stdio.h>
int main()
{
    printf("请输入十个数字");
    int i = 0;
    int mun[10] = {0};
    int a[10];
    for(i; i<10; i++)
    {
        scanf("%d", &mun[i]);
    }
    for(i=0; i<10; i++)
    {
        a[0+i]=mun[9-i];
    }
    for(i=0; i<10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
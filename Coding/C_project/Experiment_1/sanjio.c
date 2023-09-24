#include <stdio.h>
int main()
{
    int a, b, c;
    printf("输入三角形的三边");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a+b>c&&a-b<c)
    {
        if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
        {
            printf("此三角行为直角\n");
        }
        if(a*a+b*b<c*c||a*a+c*c<b*b||c*c+b*b<a*a)
        {
            printf("此三角行为钝角三角形\n");
        }
        if("a*a+b*b>c*c||a*a+c*c>b*b||b*b+c*c>a*a")
        {
            printf("此三角行为锐角三角形\n");
        }
    }
    else
    {
        printf("不能组成三角形");
    }
    return 0;
}
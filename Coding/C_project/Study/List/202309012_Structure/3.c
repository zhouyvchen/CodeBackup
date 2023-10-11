#include <stdio.h>
#include <time.h>
void Fun()
{
    int i, j;
    for (i = 1500; i > 0; i--)
        for (j = 2000; j > 0; j--)
            ;
}
int main()
{
    clock_t start, stop; // 定义2个变量用来存放开始和结束时间
    double duration;
    start = clock();                               // 开始计时
    Fun();                                         // 被测函数
    stop = clock();                                // 结束计时
    duration = ((double)(stop - start)) / CLK_TCK; // 计算以秒为单位的运行时间，（结束时间-开始时间）/CLK_TCK
    printf("Fun函数耗费时间为%f秒\n", duration);
    return 0;
}
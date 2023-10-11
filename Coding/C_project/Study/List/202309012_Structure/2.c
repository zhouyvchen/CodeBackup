#include <stdio.h>
#include <time.h>

void add()
{
    long long sum = 0;
    long long n = 9999999;
    for (long long i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("Sum: %lld\n", sum);
}

void Gaosi()
{
    long long n = 99999999;
    long long sum = 0;
    sum = (1 + n) * n / 2;
    printf("Sum: %lld\n", sum);
}

// 计算函数运行时间的函数
double usetime(void (*function)())
{
    clock_t start, end;
    double times;

    start = clock();
    function();
    end = clock();

    times = ((double)(end - start)) / CLOCKS_PER_SEC;
    return times;
}

int main()
{
    double times = usetime(add);
    printf("累加所需时间: %lf 秒\n", times);

    double times = usetime(Gaosi) return 0;
}
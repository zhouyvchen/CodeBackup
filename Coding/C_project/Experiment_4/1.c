//由用户输入10个整数，将这10个整数放入一个数组中，
//然后将数组中的值按从大到小的顺序排序并。重新存放。
#include <stdio.h>
int main()
{
    printf("请输入十个数字");
    int i = 0;
    int mun[10] = {0};
    for (i; i < 10; i++)
    {
        scanf("%d", &mun[i]);
    }
    int j;
    for (j = 0; j<10; j++)
    {
        for (i = 0; i < 10; i++)
        {
            if (mun[i] < mun[i + 1])
            {
                int t;
                t = mun[i];
                mun[i] = mun[i + 1];
                mun[i + 1] = t;
            }
        }
    }
    for(i=0; i<10; i++)
    printf("%d ", mun[i]);
    return 0;
}

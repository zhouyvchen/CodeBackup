#include <stdio.h>
int main()
{
    int a, b, j, k, p;
    k = 0, p = 0;
    scanf("%d %d", &a, &b);
    if (a < -100 || b > 100 || a > b)
    {
        scanf("%d %d", &a, &b);
    }
    for (j = a; j <= b; j++)
    {
        printf("%5d", j);
        p++;
        k += j;
        if (p % 5 == 0)
        {
            printf("\n");
        }
    }
    if (p % 5 != 0)
    {
        printf("\n");
    }
    printf("和%d", k);
    return 0;
}
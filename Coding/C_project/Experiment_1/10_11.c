#include <stdio.h>
int main()
{
    int n, i, z, d;
    double sum = 0;
    scanf("%d", &n);
    if (0 < n < 100)
    {
        while (i <= n)
        {
            if (i / 5 == 0 || i / 9 == 0)
            {
                sum = sum + 1.0 / i;
            }
        }
    }
    printf("%d", sum);
    return 0;
}

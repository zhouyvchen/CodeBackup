#include <stdio.h>
int main()
{
    int n = 1, sum = 0, product;
    for (n; n <= 99; n += 2)
    {
        product = n * (n + 1);
        sum += product;
        printf("%d*%d=%d\n",n, n+1, sum);
    }                                                                                                                                                                                                                                                                                                                                                        
    return 0;
}
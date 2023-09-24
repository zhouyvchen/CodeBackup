#include <stdio.h>
int main()
{
    double sum=0;
    int i=1,n;
    scanf("%d",&n);
    while(i<=n)
    {
        if((i%5==0)||(i%9==0))
        sum=sum+1.0/i;
        i++;
    }
    printf("%.6f",sum);
    return 0;
}
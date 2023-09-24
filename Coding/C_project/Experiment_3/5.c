#include <stdio.h>
#include <math.h>
int main()
/*求S=a+aa+aaa+…+aa…a(n个a)之值，其中a是一个数字例如2+22+222+2222+22222(此时n=5)，
注意，a的值和n的值都由键盘输入。*/
{
	//n为a的个数
    int a, n;
    printf("请输入两个数a和n:\n");
    scanf("%d %d", &a, &n);
    int sum=0, product=0;
    for ( int i=1, v=1; i <= n; i++){
        for( ; v <= i; v++){
            product += a*pow(10, v-1);
        }
        sum += product;
        printf("sum=%d,porduct=%d\n", sum, product);
    }
    return 0;
}
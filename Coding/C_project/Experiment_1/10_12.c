#include<stdio.h>
int main()
{
	int a, b, c;
 	printf("输入一个数");
	scanf("%d,%d,%d",&a,&b,&c);
	if(a<b){
		if(b<c)
			printf("最大数%d",c);
		else
			printf("最小数%d",b);
	}
	else{
		if(c<a)
			printf("最大数%d",a);
		else
			printf("最小数%d",c);
	}
	return 0;
}
//猴子选大王(约瑟夫环问题)(数组) 
//请输入猴子数和出圈猴子的报到数：10 3
//9个猴子的出圈顺序是：3 6 9 2 7 1 8 5 10
//最后圈内剩下猴子的编号是：4
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m;
	printf("请输入猴子数和出圈猴子的报到数：");
	scanf("%d %d", &n, &m);
	int *a = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
		a[i] = i + 1;
	printf("%d个猴子的出圈顺序是：", n-1);
	int j = n - 1;              //*****重要 
	for(int i = 1; i < n; i++)  //踢出去n-1个 
	{
		int k = 0;
		while(k < m)
		{
			j = (j + 1) % n;//*****重要 
			if(a[j] != 0)
				k++;
		}
		printf("%d ", a[j]);
		a[j] = 0;	
	} 
	printf("\n最后圈内剩下猴子的编号是：");
	for(int i = 0; i < n; i++)
	{
		if(a[i] != 0)
			printf("%d\n", a[i]);
	}
	free(a);
	return 0;
} 
#include <stdio.h>
 
int main()
{
   int a;
	printf("输入百分制成绩\n");
	scanf("%d", &a);
	if (90 <= a && 100 >= a) printf("A");
	else if (80 <= a && 89 >= a) printf("B");
	else if (70 <= a && 79 >= a) printf("C");
	else if (60 <= a && 69 >= a) printf("D");
	else if (0 <= a && 59 >= a) printf("E");
	else printf("error\n");
   return 0;
}
/*有1、2、3、4四个数字，能组成多少个互不相同和无重复数字的三位数？都是多少？
程序分析：可填在百位、十位、个位的数字都是1、2、3、4，组成所有的排列后再去
掉不满条件的排列。*/
#include <stdio.h>       
int main()
{
    for( int a=1; a<5; a++)
    {
        for( int b=1; b<5; b++)
        {
            for( int c=1; c<5; c++)
            {
                printf("%d%d%d\n", a, b, c);
            }
        }
    }
    return 0;
}
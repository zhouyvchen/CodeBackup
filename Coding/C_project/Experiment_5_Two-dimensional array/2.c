#include <stdio.h>
int main()
{
    int A[5][6];
    int x, y;
    int i = 1;
    for (x = 0; x < 5; x++)
    {
        for (y = 0; y < 6; y++)
        {
            A[x][y] = i;
            i++;
        }
    }
    //将A转化到B
    int B[6][5];
    for(x=0; x<6; x++)
    {
        for(y=0; y<5; y++)
        {
            B[x][y]=A[y][x];
        }
    }
    //打印B
    for(x=0; x<6; x++)
    {
        for(y=0; y<5; y++)
        {
            printf("%d ", B[x][y]);
        }
        printf("\n");
    }
    return 0;
}
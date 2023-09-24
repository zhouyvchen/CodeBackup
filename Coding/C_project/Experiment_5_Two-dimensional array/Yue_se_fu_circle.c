/*10个同学排成一个首尾相连的圈，先给每位同学从1到10编号，
然后依次报数（1，2，3），报到3的同学退出，至到只剩1个同
学为止，请求出最后剩下的这个同学的编号是多少。*/
#include <stdio.h>
int main()
{
    int student[10] = {0}; // 0表示为未被退出，1表示为被退出
    int i;
    int n = 10;    //计数
    int count = 1; //表示123
    for (i = 0;; i++)
    {
        if (i == 10)
            i = 0;
        if (student[i] == 0)
        {
            if (count != 3)
            {
                count++; //计数加1
            }
            if (count == 3)
            {
                student[i] = 1; //技数为3被退出
                count = 1;      //计数归1
                n--;            //人数减1
            }
        }
        else
            count = count; //计数不变
        if (n == 1)
        {
            for(i=0; i<10; i++)
            {
                if(student[i]==0)
                printf("最后一位同学为第%d位\n", i);
            }
            break;
        }
    }
    return 0;
}
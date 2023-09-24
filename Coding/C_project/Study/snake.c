#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
char m;
int x,y,fx,fy,ta,blength=2;//为了方便，数组第0个元素不要了，直接从1开始
                        //length>=1必须的
int sbody_move;
struct sbody
{
   
    int bx;
    int by;
}sbody[1801];
int ou(int n)
{
   
    if(n%2==1) n=n+1;
    return n;
}
void map()
{
   
    //地图20*60 活动空间18*58
    printf("by qq1176611589 on 11.13\nYour body length=%d,goal=20\n",blength);
    int i,a,b,pr=0;
    for (i=1;i<=60;i++) //第一行全为“- ”
       printf("-");
    printf("\n");
   for(i=1;i<=18;i++)//中间18行
    {
   
        printf("|");
        for(a=1;a<=58;a++)//具体打印某个值
        {
   
            if(i==y && a==x)  pr=1; //蛇头
            if(i==fy && a==fx)    pr=1; //产生食物
            else
            {
   
                for(b=1;b<=blength;b++)
                {
   
                    if(sbody[b].bx==a && sbody[b].by==i)
                    {
   
                        pr=1;
                        break;
                    }
                }
            }
            if(pr==0) printf(" ");
            if(pr==1) printf("*");
            pr=0;
        }
        printf("|");
        printf("\n");
    }
    for (i=1;i<=60;i++) //最后一行全为“- ”
       printf("-");
    printf("\n");
}
void move()
{
   
    sbody[sbody_move].bx=x;//摆动身体
    sbody[sbody_move].by=y;
    sbody_move-=1;
    if(sbody_move<=0)
    sbody_move=blength;
    switch(m)//蛇头坐标改变
    {
   
    case 's':y+=1;break;
    case 'a':x-=2;break;
    case 'd':x+=2;break;
    case 'w':y-=1;
    }
}
void s_introducer()//游戏初始化...
{
   
    printf("by_Wang qq1176611589 on 11.13\nasdw控制移动方向，请切换成英文输入法，身体长度达到20胜利\n");
    system("pause");
   m='d';
    x=10;
    y=10;
    sbody[1].by=10;
    sbody[1].bx=8;
    sbody[2].by=9;
    sbody[2].bx=8;
    sbody_move=blength;
    char ta;
}
void food()
{
   
    int data,guess,ran,i;
    srand((unsigned)time(NULL));
    ran=rand();
    f:                          //每个坐标必须为偶数
    fy=ou(rand()%(17)+1);       //data (1,17) x58 y18
    fx=ou(rand()%(57)+1);       //(1,57)
    if(x==fx && y==fy) goto f;  //food不能在头上
    for(i=1;i<=blength;i++)//food不能再身体上
       {
   
           if(sbody[i].bx==fx && sbody[i].by==fy)
           {
   
            goto f;
           }
        }
}
main()
{
   
    system("mode con cols=65 lines=25");
    s_introducer();//游戏初始化 打酱油的无伤大雅的开局介绍和进入游戏。
    int win=0,de=1,i,gameover=0,fe=0;
    for(;gameover==0;)          //主程序 =====================
    {
   
       move();
       if(x>58 || x<1 || y>18 || y<1)//判断游戏是否结束 活动空间x58 y18 /判断是否撞墙
            break;

        for(i=1;i<=blength;i++)//判断是否咬到自己
       {
   
           if(sbody[i].bx==x && sbody[i].by==y)
           {
   
            gameover=1;
           break;
           }
        }
        if(gameover==1) break;
        system("cls");
        if(kbhit())
          {
   
              ta=m;
               m=getch();//判断按下某键 asdw作为控制
            if(m=='a' && ta=='d') m=ta;
            if(m=='d' && ta=='a') m=ta;
            if(m=='w' && ta=='s') m=ta;
            if(m=='s' && ta=='w') m=ta;
            de=0;
        }
        if(x==fx && y==fy)
        {
   
            blength+=1;
            fe=0;
        }
        if(blength>=20)
        {
   
        win=1;
        break;
        }
        map();
        if(fe==0)
        {
   
        food();//如果食物不存在，产生食物。
        fe=1;
        }
        if(de==1)
        Sleep(80);
        if(de==0)
        de=1;
    }
    if(win==0) printf("=========Gameover.You fail!=========\n");
    if(win==1) printf("=========Gameover.You win!=========\n");
    system("pause");
}
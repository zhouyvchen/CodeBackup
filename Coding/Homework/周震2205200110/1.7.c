#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <time.h>
#include <unistd.h>
#include <Windows.h>
const char* LastStr = "[--------------------] 100%";

const char ProgressIcon = '-';

const int Step = 5;

const int IconMaxNum = 20;

const int PrintInterval = 1000; // 每次打印时间*/

#define N 100000
struct Ray
{
	int jifen;//积分
	int id;//编号
	char name[20];//名字
	char produce[30];//产di
	int number;//数量
	float price;//价格
	int RMB;
};
struct key
{
	int mima;
};
void look();//查询
void look2();//查询2
void Append();//添加
void Browse();//浏览
void Browse2();//浏览2
int validateID(int id);//管理账号
void Endprogram();//结束程序（退出）
void Endprogram2();//结束程序（退出）2
void Revision();//修改
void Delete();//删除
//void menu();//菜单
void Time();//节日1（可删除）
void Time2();//节日2（可删除）
void menu1();//用户菜单
void menu2();//管理员菜单
void Lottery();//抽奖
void Lottery2();//抽奖2
void jifenchongzhi();//积分充值
void Browse1();//积分查询
void nothing();//积分定义
void jifenchongzhi_2();//积分充值2
void Browse1_2();//积分查询2
void nothing_2();//积分定义
void color();//系统颜色，用户
void color_2();//系统颜色
void jingquechazhao();//精确查找
void jingquechazhao_2();//精确查找2
void jifen_zon_1();//积分总页面
void jifen_zon_2();
void jindutiao();
int loading(int mima);
void key();
void buy();

//
void increase_staff();//增加员工。
void look_staff();
void query();
void increase_staff_2();//增加员工。
void look_staff_2();
void query_2();
void staff();
void staff_2();
//staff是员工
//大型超市，人员多，分市多。
struct staff
{
	char people_id[20];//编号
	char people_name[50];//名字
	char people_location[50];//员工所服务的超市
	char duties[1500];//职务
};

void menu1()//用户菜单界面
{
	int a, b;
	system("cls");
	struct tm t;   //tm结构指针
	time_t now; //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时jian
	a = t.tm_mon + 1;
	b = t.tm_mday;
	if (a == 1 & b == 1)//元旦节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是元旦节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 2 & b == 14)//情人节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是情人节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 3 & b == 8)//妇女节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是妇女节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 5 & b == 1)//劳动节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是劳动节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 6 & b == 1)//儿童节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是儿童节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 10 & b == 1)//国庆节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是国庆节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 2 & b == 1)//春节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是春节，有优惠及打折。    ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 12 & b == 15)//元宵节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是元宵节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 9 & b == 29)//中秋节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是中秋节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 12 & b == 25)//圣诞节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是圣诞节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 6 & b == 22)//端午节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是端午节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 5 & b == 14)//母亲节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是母亲节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 6 & b == 18)//父亲节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是父亲节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天不是节日，没有优惠及打折。┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	int choice;
	printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【超市库存管理系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
	printf("\n\t-----------------------------------系统菜单显示如下-------------------------------\n");
	printf("\n\tI:1=====================【           物品信息浏览         】======================I\n");
	printf("\n\tI:2=====================【           退出超市系统         】======================I\n");
	printf("\n\tI:3=====================【           查询商品信息         】======================I\n");
	printf("\n\tI:4=====================【               日期             】======================I\n");
	printf("\n\tI:5=====================【               抽奖             】======================I\n");
	printf("\n\tI:6=====================【             系统设置           】======================I\n");
	printf("\n\tI:7=====================【             账户系统           】======================I\n");
	printf("\n\tI:8=====================【             员工系统           】======================I\n");
	printf("\n\tI:9=====================【             商品购买           】======================I\n");
	printf("\n\t===================================================================================\n");
	printf("\n\t请输入您要选择的选项：");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		Browse();
		break;
	case 2:
		Endprogram();
		break;
	case 3:
		look();
		break;
	case 4:
		Time();
		break;
	case 5:
		Lottery();
		break;
	case 6:
		color();
		break;
	case 7:
		jifen_zon_1();
		break;
	case 8:
		staff();
		break;
	case 9:
		buy();
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇输入无效，请您重新输入......(y/n)     〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		getchar();
		Sleep(1500);
		system("cls");
		menu1();
	}
}void menu2()//管理员菜单界面
{
	int a, b;
	system("cls");
	struct tm t;   //tm结构指针
	time_t now; //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时jian
	a = t.tm_mon + 1;
	b = t.tm_mday;
	if (a == 1 & b == 1)//元旦节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是元旦节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 2 & b == 14)//情人节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是情人节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 3 & b == 8)//妇女节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是妇女节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 5 & b == 1)//劳动节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是劳动节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 6 & b == 1)//儿童节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是儿童节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 10 & b == 1)//国庆节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是国庆节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 2 & b == 1)//春节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是春节，有优惠及打折。    ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 12 & b == 15)//元宵节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是元宵节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 9 & b == 29)//中秋节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是中秋节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 12 & b == 25)//圣诞节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是圣诞节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 6 & b == 22)//端午节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是端午节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 5 & b == 14)//母亲节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是母亲节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else if (a == 6 & b == 18)//父亲节
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天是父亲节，有优惠及打折。  ┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	else
	{
		printf("\n\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━╮                              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天是：%d年  %d月  %d日 ┃                              ┃今天不是节日，没有优惠及打折。┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━╯                              ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	int choice;
	printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【超市库存管理系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
	printf("\n\t-----------------------------------系统菜单显示如下-------------------------------\n");
	printf("\n\tI:1=====================【           新购物品入库         】======================I\n");
	printf("\n\tI:2=====================【           物品信息浏览         】======================I\n");
	printf("\n\tI:3=====================【           退出超市系统         】======================I\n");
	printf("\n\tI:4=====================【           查询商品信息         】======================I\n");
	printf("\n\tI:5=====================【           修改商品信息         】======================I\n");
	printf("\n\tI:6=====================【           删除商品信息         】======================I\n");
	printf("\n\tI:7=====================【               日期             】======================I\n");
	printf("\n\tI:8=====================【               抽奖             】======================I\n");
	printf("\n\tI:9=====================【             系统设置           】======================I\n");
	printf("\n\tI:10====================【             账户系统           】======================I\n");
	printf("\n\tI:11====================【             员工系统           】======================I\n");
	printf("\n\tI:12====================【             用户界面           】======================I\n");
	printf("\n\t===================================================================================\n");
	printf("\n\t请输入您要选择的选项：");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		Append();//增加
		break;
	case 2:
		Browse2();//浏览
		break;
	case 3:
		Endprogram2();//退出
		break;
	case 4:
		look2();//查询
		break;
	case 5:
		Revision();//修改
		break;
	case 6:
		Delete();//删除
		break;
	case 7:
		Time2();//时间
		break;
	case 8:
		Lottery2();//抽奖
		break;
	case 9:
		color_2();//系统设置
		break;
	case 10:
		jifen_zon_2();
		break;
	case 11:
		staff_2();
		break;
	case 12:
		menu1();
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		getchar();
		Sleep(1500);
		system("cls");
		menu2();
	}
}
void Append()//录入
{
	struct Ray i;
	char choice;
	FILE* fp;
	fp = fopen("info", "ab");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}

labID:
	printf("\n\t请您输入要入库物品的信息...\n");
	printf("\t\t\t\t   物品的编号:");
	scanf("%d", &i.id);
	if (validateID(i.id) == 1)
	{
		printf("\t\t\t\t此编号已被使用，请您重新输入......");
		Sleep(1500);
		system("cls");
		goto labID;
	}
	printf("\t\t\t\t   物品的名称:");
	scanf("%s", i.name);
	printf("\t\t\t\t   物品的生产地:");
	scanf("%s", i.produce);
	printf("\t\t\t\t   物品的数量:");
	scanf("%d", &i.number);
	printf("\t\t\t\t   物品的单价:");
	scanf("%f", &i.price);
	fwrite(&i, sizeof(struct Ray), 1, fp);
	fclose(fp);
	printf("\t\t\t\t\t\t  物品信息已入库成功!!!\n");

	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		Append();
	}
	else
	{
		system("cls");
		menu2();
	}
}

void Browse()//浏览1
{
	struct Ray i;
	int index = 0;
	char choice;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请你重试........");
		exit(0);
	}

	fread(&i, sizeof(struct Ray), 1, fp);

	while (!feof(fp))
	{
		index++;
		printf("\n\n\t╭━━━━━━━━━━━━━━━━物品信息:%d━━━━━━━━━━━━━━━╮\n", index);
		printf("\t┃物品编号...%30d┃\n", i.id);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t┃物品名称...%30s┃\n", i.name);
		printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("\t┃生产厂家...%30s┃\n", i.produce);
		printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("\t┃进口数量...%30d┃\n", i.number);
		printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("\t┃批发价格...%30.3f┃\n", i.price);
		printf("\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		getchar();
		fread(&i, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);

	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Browse();
	}
	else
	{
		system("cls");
		menu1();
	}
}
void Browse2()//浏览2
{
	struct Ray i;
	int index = 0;
	char choice;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请你重试........");
		exit(0);
	}

	fread(&i, sizeof(struct Ray), 1, fp);

	while (!feof(fp))
	{
		index++;
		printf("\n\n\t╭━━━━━━━━━━━━━━━━物品信息:%d━━━━━━━━━━━━━━━╮\n", index);
		printf("\t┃物品编号...%30d┃\n", i.id);
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t┃物品名称...%30s┃\n", i.name);
		printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("\t┃生产厂家...%30s┃\n", i.produce);
		printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("\t┃进口数量...%30d┃\n", i.number);
		printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("\t┃批发价格...%30.3f┃\n", i.price);
		printf("\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		getchar();
		fread(&i, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Browse2();
	}
	else
	{
		system("cls");
		menu2();
	}
}
int validateID(int id)//账号管理
{
	FILE* fp;
	struct Ray i;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇系统错误，请您重试........(y/n)     〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		exit(0);
	}

	fread(&i, sizeof(struct Ray), 1, fp);
	while (!feof(fp))
	{
		if (i.id == id)
		{
			fclose(fp);
			return 1;
			break;
		}
		fread(&i, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);
	return 0;
}
void Endprogram()//退出1
{


	char choice;
	system("cls");

	printf("\n\n\n\n\n\n\n\t\t\t您确定要退出系统吗?\n\n\n\t\t\t如果您想退出请按'y',其它键将返回主菜单.....");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t谢谢您的使用!!!");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	}
	else
	{
		system("cls");
		menu1();
	}

}
void Endprogram2()//退出2
{


	char choice;
	system("cls");

	printf("\n\n\n\n\n\n\n\t\t\t您确定要退出系统吗?\n\n\n\t\t\t如果您想退出请按'y',其它键将返回主菜单.....");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t谢谢您的使用!!!");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	}
	else
	{
		system("cls");
		menu2();
	}

}

void main()
{
	jindutiao();
	printf("\n\n");
	system("color 1a");
	printf("\t\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t\t┃                                          ┃\n");
	printf("\t\t\t┃ ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑ ┃\n");
	printf("\t\t\t┃ ┃                                      ┃ ┃\n");
	printf("\t\t\t┃ ┃                                      ┃ ┃\n");
	printf("\t\t\t┃ ┣━━━━━━━━━━━━●○●欢迎使用●○●━━━━━━━━━━━━┫ ┃\n");
	printf("\t\t\t┃ ┃                                      ┃ ┃\n");
	printf("\t\t\t┃ ┃          ╭━━━━━━━━━━━━━━━━━━╮        ┃ ┃\n");
	printf("\t\t\t┃ ┃          ┃超级好超市管理系统┃        ┃ ┃\n");
	printf("\t\t\t┃ ┃          ╰━━━━━━━━━━━━━━━━━━╯        ┃ ┃\n");
	printf("\t\t\t┃ ┃               Ⅰ用户菜单              ┃ ┃\n");
	printf("\t\t\t┃ ┃               Ⅱ管理员菜单            ┃ ┃\n");
	printf("\t\t\t┃ ┃               Ⅲ:密码设制             ┃ ┃\n");
	printf("\t\t\t┃ ┃            请选择使用的菜单          ┃ ┃\n");
	printf("\t\t\t┃ ┃                                      ┃ ┃\n");
	printf("\t\t\t┃ ┃                                      ┃ ┃\n");
	printf("\t\t\t┃ ┃                                      ┃ ┃\n");
	printf("\t\t\t┃ ┖━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┚ ┃\n");
	printf("\t\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	//getchar();
	int xuanze;
	printf("\t\t\t请输入您的选择：");
	scanf("%d", &xuanze);
	if (xuanze == 1)
	{
		menu1();
	}
	else if (xuanze == 2)
	{
	labID:
		system("cls");
		struct key i;
		char choice;

		FILE* fp;
		fp = fopen("key", "ab");
		if (fp == NULL)
		{
			printf("\t\t\t系统错误，请您重试........");
			exit(0);
		}

		printf("请输入密码\n");
		scanf("%d", &i.mima);
		if (loading(i.mima) == 0)
		{
			printf("密码输入错误，请重试\n");
			Sleep(2000);
			goto labID;
		}
		fclose(fp);
		menu2();
	}
	else if (xuanze == 3)
	{
		key();
	}

	else
	{
		printf("未识别请求，请重试！");
	}

}
void look()//查询1
{
	struct Ray find;
	int index = 0;
	char choice;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请你重试........");
		exit(0);
	}

	fread(&find, sizeof(struct Ray), 1, fp);
	int lookid;
find:
	printf("请输入你想要查询的对象编号：");
	scanf("%d", &lookid);
	if (find.id == lookid)
	{
		system("cls");
		index++;
		printf("\t╭───────────────────────────────────────────╮\n");
		printf("\t│▁▂▃▄▅▆▇█>>>>>>>>>物品信息%d<<<<<<<<<█▇▆▅▄▃▂▁│", index);
		printf("\n\t╰───○●★●○───────────────────────────────────╯\n");
		printf("\t\t  ┏━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t  ┣①物品编号:%3d          ┃\n", find.id);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣②物品名称:%3s          ┃\n", find.name);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣③生产厂家:%3s          ┃\n", find.produce);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣④进口数量:%3d          ┃\n", find.number);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣⑤批发价格:%3fRMB ┫\n", find.price);
		printf("\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		getchar();
		fread(&find, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);

	printf("\t\t  ╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t  〇您想继续吗?(y/n)     〇\n");
	printf("\t\t  ╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		goto find;
	}
	else
	{
		system("cls");
		menu1();
	}
}
void look2()//查询2
{
	struct Ray find;
	int index = 0;
	char choice;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请你重试........");
		exit(0);
	}

	fread(&find, sizeof(struct Ray), 1, fp);
	int lookid;
find:
	printf("请输入你想要查询的对象编号：");
	scanf("%d", &lookid);
	if (find.id == lookid)
	{
		system("cls");
		index++;
		printf("\t╭───────────────────────────────────────────╮\n");
		printf("\t│▁▂▃▄▅▆▇█>>>>>>>>>物品信息%d<<<<<<<<<█▇▆▅▄▃▂▁│", index);
		printf("\n\t╰───○●★●○──────────────────────────────────╯\n");
		printf("\t\t  ┏━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t  ┣①物品编号:%3d          ┃\n", find.id);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣②物品名称:%3s          ┃\n", find.name);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣③生产厂家:%3s          ┃\n", find.produce);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣④进口数量:%3d          ┃\n", find.number);
		printf("\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t  ┣⑤批发价格:%3fRMB ┫\n", find.price);
		printf("\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		getchar();
		fread(&find, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);

	printf("\t\t  ╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t  〇您想继续吗?(y/n)     〇\n");
	printf("\t\t  ╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		goto find;
	}
	else
	{
		system("cls");
		menu2();
	}
}
void Revision()//修改
{
	int i;
	int input_id;
	struct Ray c[N];
	struct Ray code;
	int index = 0;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试......");
		exit(0);
	}
	fread(&code, sizeof(struct Ray), 1, fp);
	while (!feof(fp))
	{
		c[index] = code;
		index++;
		fread(&code, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);
change:
	//int a = 0;
	printf("请输入需要修改的商品序号：");
	scanf("%d", &input_id);
	fp = fopen("info", "w");
	for (i = 0; i < index; i++)
	{
		if (input_id == c[i].id)
		{
			printf("\t\t\t\t  修改物品的名称:");
			scanf(" %s", &c[i].name);
			printf("\t\t\t\t  修改物品的生产地:");
			scanf(" %s", &c[i].produce);
			printf("\t\t\t\t  修改物品的数量:");
			scanf(" %d", &c[i].number);
			printf("\t\t\t\t  修改物品的单价:");
			scanf(" %f", &c[i].price);
			fwrite(&c[i], sizeof(struct Ray), 1, fp);
			printf("\t\t\t\t修改成功！\n");
		}
		else
		{
			fwrite(&c[i], sizeof(struct Ray), 1, fp);
		}
	}
	fclose(fp);
	int choice;
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗?(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		goto change;
	}
	else
	{
		system("cls");
		menu2();
	}
}
void Delete()//删除
{
	int i;
	int input_id;
	struct Ray c[N];
	struct Ray code;
	int index = 0;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试......");
		exit(0);
	}
	fread(&code, sizeof(struct Ray), 1, fp);
	while (!feof(fp))
	{
		c[index] = code;
		index++;
		fread(&code, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);
Delete:
	printf("请输入需要删除的商品序号：");
	scanf("%d", &input_id);
	fp = fopen("info", "w");
	for (i = 0; i < index; i++)
	{
		if (input_id != c[i].id)
		{
			fwrite(&code, sizeof(struct Ray), 1, fp);
		}
	}
	fclose(fp);
	printf("删除成功！\n");
	int choice;
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗?(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		goto Delete;
	}
	else
	{
		system("cls");
		menu2();
	}
}

void Time()//时间
{
	system("cls");
	int a, b;
	struct tm t;   //tm结构指针
	time_t now; //声明time_t类型变量
T:
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时jian
	printf("\n\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━╮");
	printf("\n\t\t┃今天是：%d年  %d月  %d日┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	a = t.tm_mon + 1;
	b = t.tm_mday;
	if (a == 1 & b == 1)//元旦节
	{
		printf("\n");
		printf("今天是元旦节");
	}
	else if (a == 2 & b == 14)//情人节
	{
		printf("\n");
		printf("今天是情人节");
	}
	else if (a == 3 & b == 8)//妇女节
	{
		printf("\n");
		printf("今天是妇女节");
	}
	else if (a == 5 & b == 1)//劳动节
	{
		printf("\n");
		printf("今天是劳动节");
	}
	else if (a == 6 & b == 1)//儿童节
	{
		printf("\n");
		printf("今天是儿童节");
	}
	else if (a == 10 & b == 1)//国庆节
	{
		printf("\n");
		printf("今天是国庆节");
	}
	else if (a == 2 & b == 1)//春节
	{
		printf("\n");
		printf("今天是春节");
	}
	else if (a == 12 & b == 15)//元宵节
	{
		printf("\n");
		printf("今天是元宵节");
	}
	else if (a == 9 & b == 29)//中秋节
	{
		printf("\n");
		printf("今天是中秋节");
	}
	else if (a == 12 & b == 25)//圣诞节
	{
		printf("\n");
		printf("今天是圣诞节");
	}
	else if (a == 6 & b == 22)//端午节
	{
		printf("\n");
		printf("今天是端午节");
	}
	else if (a == 5 & b == 14)//母亲节
	{
		printf("\n");
		printf("今天是母亲节");
	}
	else if (a == 6 & b == 18)//父亲节
	{
		printf("\n");
		printf("今天是父亲节");
	}
	else
	{
		printf("\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
		printf("\n\t┃今天不是节日，没有优惠及打折。 ┃\n");
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯");
	}
	int choice;
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗?(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		goto T;
	}
	else
	{
		system("cls");
		menu1();
	}
}

void Time2()//时间
{
	system("cls");
	int a, b;
	struct tm t;   //tm结构指针
	time_t now; //声明time_t类型变量
T:
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时jian
	printf("\n\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t┃今天是：%d年  %d月  %d日┃\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	a = t.tm_mon + 1;
	b = t.tm_mday;
	if (a == 1 & b == 1)//元旦节
	{
		printf("\n");
		printf("今天是元旦节");
	}
	else if (a == 2 & b == 14)//情人节
	{
		printf("\n");
		printf("今天是情人节");
	}
	else if (a == 3 & b == 8)//妇女节
	{
		printf("\n");
		printf("今天是妇女节");
	}
	else if (a == 5 & b == 1)//劳动节
	{
		printf("\n");
		printf("今天是劳动节");
	}
	else if (a == 6 & b == 1)//儿童节
	{
		printf("\n");
		printf("今天是儿童节");
	}
	else if (a == 10 & b == 1)//国庆节
	{
		printf("\n");
		printf("今天是国庆节");
	}
	else if (a == 2 & b == 1)//春节
	{
		printf("\n");
		printf("今天是春节");
	}
	else if (a == 12 & b == 15)//元宵节
	{
		printf("\n");
		printf("今天是元宵节");
	}
	else if (a == 9 & b == 29)//中秋节
	{
		printf("\n");
		printf("今天是中秋节");
	}
	else if (a == 12 & b == 25)//圣诞节
	{
		printf("\n");
		printf("今天是圣诞节");
	}
	else if (a == 6 & b == 22)//端午节
	{
		printf("\n");
		printf("今天是端午节");
	}
	else if (a == 5 & b == 14)//母亲节
	{
		printf("\n");
		printf("今天是母亲节");
	}
	else if (a == 6 & b == 18)//父亲节
	{
		printf("\n");
		printf("今天是父亲节");
	}
	else
	{
		printf("\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t┃今天不是节日，没有优惠及打折。 ┃\n");
		printf("\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	}
	int choice;
	printf("\n\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗?(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		goto T;
	}
	else
	{
		system("cls");
		menu2();
	}
}
void Lottery()//抽奖
{
	int a;
	char choice;
	struct Ray i;
	FILE* fp;
	fp = fopen("JIFEN", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试......");
		exit(0);
	}
	fread(&i, sizeof(struct Ray), 1, fp);
	fp = fopen("JIFEN", "w");
	printf("\n抽中数字1、2、3为中奖，否则未中奖\n");
	printf("\n抽取一次奖品将消耗您100积分，您现在的积分为%d\n", i.jifen);

	if (i.jifen >= 100)
	{
		srand((unsigned)time(NULL));//每次播种的时间不同，那么生成的种子就不同，最终的随机数也就不同
		a = rand() % 10; //产生0~9的随机数，注意10会被整除
		printf("%d\n", a);
	}
	if (a == 1 || a == 2 || a == 3)
	{
		i.jifen -= 100;
		system("cls");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇中奖号码：1、2、3    〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t◇您的号码为：%d         ◇\n", a);
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t\n\n\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇恭喜您，中奖了！！！ 〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━╯\n");
		fwrite(&i, sizeof(struct Ray), 1, fp);
		fclose(fp);
		printf("您剩余的积分为%d\n", i.jifen);
	}
	else
	{
		i.jifen -= 100;
		system("cls");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇中奖号码：1、2、3    〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t◇您的号码为：%d         ◇\n", a);
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t\n\n\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇很遗憾，您未中奖……〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━╯\n");
		fwrite(&i, sizeof(struct Ray), 1, fp);
		fclose(fp);
		printf("您剩余的积分为%d\n", i.jifen);
	}
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇请问您是否选择继续〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Lottery();
	}
	else
	{
		system("cls");
		menu1();
	}
}
void Lottery2()//抽奖
{
	struct Ray i;

	FILE* fp;
	fp = fopen("JIFEN", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试......");
		exit(0);
	}
	fread(&i, sizeof(struct Ray), 1, fp);
	printf("您的积分为：%d", i.jifen);
	i.jifen = i.jifen - 100;
	int a;
	char choice;
	srand((unsigned)time(NULL));//每次播种的时间不同，那么生成的种子就不同，最终的随机数也就不同
	a = rand() % 10; //产生0~9的随机数，注意10会被整除
	printf("%d\n", a);
	if (a == 1 || a == 2 || a == 3)
	{
		system("cls");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇中奖号码：1、2、3    〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t◇您的号码为：%d         ◇\n", a);
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t\n\n\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇恭喜您，中奖了！！！ 〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("您剩余的积分为%d\n", i.jifen);
	}
	else
	{
		system("cls");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇中奖号码：1、2、3    〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t◇您的号码为：%d         ◇\n", a);
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("\t\t\n\n\n");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇很遗憾，您未中奖……〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━╯\n");
		printf("您剩余的积分为%d\n", i.jifen);

	}
	printf("\n\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续抽奖吗?(y/n) 〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Lottery();
	}
	else
	{
		system("cls");
		menu2();
	}
}
void jifenchongzhi()//积分充值
{
	int b;
	struct Ray i;
	FILE* fp;
	fp = fopen("JIFEN", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试......");
		exit(0);
	}
	fread(&i, sizeof(struct Ray), 1, fp);
	fp = fopen("JIFEN", "w");
	printf("\t\t\t\t 请输入充值的金额:");
	scanf("%d", &b);
	i.jifen += b;
	i.RMB += b;
	printf("\t\t\t充值成功！");
	fwrite(&i, sizeof(struct Ray), 1, fp);
	printf("\t\t\t您剩余的积分为%d", i.jifen);
	printf("\t\t\t您剩余的金额为%d", i.RMB);
	fclose(fp);
	int choice;
	printf("\n您想继续吗?(y/n)");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		jifenchongzhi();
	}
	else
	{
		system("cls");
		jifen_zon_1();
	}
}
void Browse1()//积分查询
{
	struct Ray i;
	char choice;
	FILE* fp;
	fp = fopen("JIFEN", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请你重试........");
		exit(0);
	}
	fread(&i, sizeof(struct Ray), 1, fp);
	printf("\n\n\t\t\t╭━☆━━━━━━━━━╮\n");
	printf("\t\t\t┃剩余积分%d   \n", i.jifen);
	printf("\t\t\t┃剩余金额%d   \n", i.RMB);
	printf("\t\t\t╰━━━━━━━━━●━╯");
	fclose(fp);
	printf("\t\t\t返回菜单请按Y or y");
	scanf("%f", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		jifen_zon_1();
	}
}
void nothing()//积分定义
{
	struct Ray i;
	char choice;
	FILE* fp;
	fp = fopen("JIFEN", "ab");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	printf("欢迎使用积分系统，请输入0，为您服务...");
	int m;
	scanf("%d", &m);
	if (m == 0)
	{
		i.jifen = 0;
		fwrite(&i, sizeof(struct Ray), 1, fp);
		fclose(fp);
		jifen_zon_1();
	}
	else
	{
		printf("很遗憾，无法为您服务哦！");
		jifen_zon_1();
	}
}
void jifenchongzhi_2()//积分充值
{
	int b;
	struct Ray i;
	FILE* fp;
	fp = fopen("JIFEN", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试......");
		exit(0);
	}
	fread(&i, sizeof(struct Ray), 1, fp);
	fp = fopen("JIFEN", "w");
	printf("\t\t\t\t 请输入充值的金额:");
	scanf("%d", &b);
	i.jifen += b;
	i.RMB += b;
	printf("\n\n\t\t\t\t充值成功！");
	fwrite(&i, sizeof(struct Ray), 1, fp);
	printf("\t\t\t您剩余的积分为%d", i.jifen);
	printf("\t\t\t您剩余的金额为%d", i.RMB);
	fclose(fp);
	int choice;
	printf("\n您想继续吗?(y/n)");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		jifenchongzhi();
	}
	else
	{
		system("cls");
		jifen_zon_1();
	}
}
void Browse1_2()//积分查询
{
	struct Ray i;
	char choice;
	FILE* fp;
	fp = fopen("JIFEN", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请你重试........");
		exit(0);
	}
	fread(&i, sizeof(struct Ray), 1, fp);
	printf("\n\n\t\t\t╭━☆━━━━━━━━━╮\n");
	printf("\t\t\t┃剩余积分%d   \n", i.jifen);
	printf("\t\t\t┃剩余金额%d   \n", i.RMB);
	printf("\t\t\t╰━━━━━━━━━●━╯");
	fclose(fp);
	printf("\t\t\t返回菜单请按Y or y");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		jifen_zon_2();
	}
}
void nothing_2()//积分定义
{
	struct Ray i;
	char choice;
	FILE* fp;
	fp = fopen("JIFEN", "ab");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	printf("欢迎使用积分系统，请输入0，为您服务...");
	int m;
	scanf("%d", &m);
	if (m == 0)
	{
		i.jifen = 0;
		fwrite(&i, sizeof(struct Ray), 1, fp);
		fclose(fp);
		jifen_zon_2();
	}
	else
	{
		printf("很遗憾，无法为您服务哦！");
		jifen_zon_2();
	}
}
void jifen_zon_1()
{
	printf("\n\n\n\t\t\t欢迎使用积分系统...\t\t\t接下来如果您第一次使用本系统，请先进行积分系统激活...\n");
	printf("\n\n\n\t\t\t1:积分充值\n\t\t\t2:积分查询\n\t\t\t3:积分系统激活\n");
	int i;
kaishi:
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		jifenchongzhi_2();//积分充值
		break;
	case 2:
		Browse1_2();//积分查询
		break;
	case 3:
		nothing_2();//积分定义
		break;
	case 4:
		menu1();;//积分定义
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇输入无效，请您重新输入......(y/n)     〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		getchar();
		Sleep(1500);
		system("cls");
		goto kaishi;
	}
}
void jifen_zon_2()
{
	printf("\n\n\n\t\t\t欢迎使用积分系统...\n\n\n\t\t\t接下来如果您第一次使用本系统，请先进行积分系统激活...\n");
	printf("\n\n\n\t\t\t1:积分充值\n\t\t\t2:积分查询\n\t\t\t3:积分系统激活");
	printf("\t\t\t如果想返回主菜单，请按 4:退出\n");
	int i;
kaishi:
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		jifenchongzhi_2();//积分充值
		break;
	case 2:
		Browse1_2();//积分查询
		break;
	case 3:
		nothing_2();//积分定义
		break;
	case 4:
		menu2();;//积分定义
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
		printf("\t\t〇输入无效，请您重新输入......(y/n)     〇\n");
		printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
		getchar();
		Sleep(1500);
		system("cls");
		goto kaishi;
	}
	if (i == 'Y' || i == 'y')
	{
		menu2();
	}
}
void color()//颜色
{
	system("cls");
	int a;
	char choice;
	printf("\n\t\t\t\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t\t\t\t┃①蓝色               ②绿色┃\n");//27
	printf("\t\t\t\t\t┃③浅蓝色             ④红色┃\n");
	printf("\t\t\t\t\t┃⑤紫色               ⑥黄色┃\n");
	printf("\t\t\t\t\t┃⑦灰色                    ┃\n");
	printf("\t\t\t\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	printf("\t\t\t\t\t╭﹂━━━━━━━━━━━━━━━━━━」\n");
	printf("\t\t\t\t\t 请选择系统背景颜色:\n");
	scanf("%d", &a);
	if (a == 1)
	{
		system("color 1a");//蓝色
	}

	else if (a == 2)
	{
		system("color 2a");//绿色
	}

	else if (a == 3)
	{
		system("color 3a");//浅蓝色
	}

	else if (a == 4)
	{
		system("color 4a");//红色
	}

	else if (a == 5)
	{
		system("color 5a");//紫色
	}

	else if (a == 6)
	{
		system("color 6a");//黄色
	}
	else if (a == 7)
	{
		system("color 8a");//灰色
	}
	else
	{
		system("color 1a");//蓝色
	}
	printf("\n您想继续改变颜色吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		color();
	}
	else
	{
		system("cls");
		menu1();
	}
}
void color_2()//颜色
{
	system("cls");
	int a;
	char choice;
	printf("\n\n\t\t\t╭━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t\t\t\t┃①蓝色               ②绿色┃\n");//27
	printf("\t\t\t\t\t┃③浅蓝色             ④红色┃\n");
	printf("\t\t\t\t\t┃⑤紫色               ⑥黄色┃\n");
	printf("\t\t\t\t\t┃⑦灰色                     ┃\n");
	printf("\t\t\t\t\t╰━━━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	printf("\t\t\t\t\t╭﹂━━━━━━━━━━━━━━━━━━」\n");
	printf("\t\t\t\t\t\t\t请选择系统背景颜色:\n");
	scanf("%d", &a);
	if (a == 1)
	{
		system("color 1a");//蓝色
	}

	else if (a == 2)
	{
		system("color 2a");//绿色
	}

	else if (a == 3)
	{
		system("color 3a");//浅蓝色
	}

	else if (a == 4)
	{
		system("color 4a");//红色
	}

	else if (a == 5)
	{
		system("color 5a");//紫色
	}

	else if (a == 6)
	{
		system("color 6a");//黄色
	}
	else if (a == 7)
	{
		system("color 8a");//灰色
	}
	else
	{
		system("color 1a");//蓝色
	}
	printf("\n您想继续改变颜色吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		color();
	}
	else
	{
		system("cls");
		menu2();
	}
}

/*
void quanbu_delete()
{
	struct Ray i;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp==NULL);
	{
		printf("系统错误！");
		exit(0);
	}
	fread(&i,sizeof(struct Ray),1,fp);

}*/
void increase_staff()//员工信息录入
{
	struct staff ID;
	FILE* fp1;
	char choice;
	int i, j, k;
	//const char ID_num[10000] = {};
	fp1 = fopen("yuangong", "ab");
labID:
	printf("\n\t请您输入要新增员工的信息...\n");
	printf("\t\t\t\t   员工的编号:");
	scanf("%s", &ID.people_id);
	printf("\t\t\t\t   员工的姓名:");
	scanf("%s", ID.people_name);
	printf("\t\t\t\t   员工的工作地:");
	scanf("%s", ID.people_location);
	printf("\t\t\t\t   员工的职务:");
	scanf("%s", &ID.duties);

	fwrite(&ID, sizeof(struct staff), 1, fp1);
	fclose(fp1);
	printf("\t\t\t\t\t\t  员工添加成功!!!\n");

	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
	}
	else
	{
		system("cls");
		staff();
	}
}

void look_staff()//员工信息浏览
{
	struct staff ID2;
	FILE* fp1;
	fp1 = fopen("yuangong", "r");
	if (fp1 == NULL)
	{
		printf("目前老板孤家寡人，还没有员工哦！！！\n");
		printf("正在退出，请稍后...");
		Sleep(2000);
		increase_staff();
	}
	fread(&ID2, sizeof(struct staff), 1, fp1);
	while (!feof(fp1))
	{
		system("cls");
		printf("\t\t\t\t   员工的编号:%-3s\n", ID2.people_id);
		printf("\t\t\t\t   员工的姓名:%-3s\n", ID2.people_name);
		printf("\t\t\t\t   员工的工作地:%-3s\n", ID2.people_location);
		printf("\t\t\t\t   员工的职务:%-3s\n", ID2.duties);
		getchar();
		fread(&ID2, sizeof(struct staff), 1, fp1);
	}
	fclose(fp1);
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	int choice;
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
	}
	else
	{
		system("cls");
		staff();
	}
}

void query()//员工查询
{
	struct staff ID3;
	FILE* fp1;
	fp1 = fopen("yuangong", "r");
	if (fp1 == NULL)
	{
		printf("目前老板孤家寡人，还没有员工哦！！！\n");
		printf("正在退出，请稍后...");
		Sleep(2000);
		increase_staff();
	}
	printf("请您输入员工编号(这里是我们小组成员的学号)");
	char staff_ID[30];
	scanf("%s", staff_ID);
	while (!feof(fp1))
	{
		if (ID3.people_id == staff_ID);
		{
			system("cls");
			printf("\t\t\t\t   员工的编号:%-3s\n", ID3.people_id);
			printf("\t\t\t\t   员工的姓名:%-3s\n", ID3.people_name);
			printf("\t\t\t\t   员工的工作地:%-3s\n", ID3.people_location);
			printf("\t\t\t\t   员工的职务:%-3s\n", ID3.duties);
			getchar();
			fread(&ID3, sizeof(struct staff), 1, fp1);
		}

	}
	fclose(fp1);
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	int choice;
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
	}
	else
	{
		system("cls");
		staff();
	}
}
void increase_staff_2()
{
	struct staff ID;
	FILE* fp1;
	char choice;
	int i, j, k;
	const char ID_num[10000] = {};
	fp1 = fopen("yuangong", "ab");
labID:
	printf("\n\t请您输入要新增员工的信息...\n");
	printf("\t\t\t\t   员工的编号:");
	scanf("%s", &ID.people_id);
	printf("\t\t\t\t   员工的姓名:");
	scanf("%s", ID.people_name);
	printf("\t\t\t\t   员工的工作地:");
	scanf("%s", ID.people_location);
	printf("\t\t\t\t   员工的职务:");
	scanf("%s", &ID.duties);

	fwrite(&ID, sizeof(struct staff), 1, fp1);
	fclose(fp1);
	printf("\t\t\t\t\t\t  员工添加成功!!!\n");

	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
	}
	else
	{
		system("cls");
		staff_2();
	}
}
void look_staff_2()//员工信息浏览
{
	struct staff ID2;
	FILE* fp1;
	fp1 = fopen("yuangong", "r");
	if (fp1 == NULL)
	{
		printf("目前老板孤家寡人，还没有员工哦！！！\n");
		printf("正在退出，请稍后...");
		Sleep(2000);
		increase_staff();
	}
	fread(&ID2, sizeof(struct staff), 1, fp1);
	while (!feof(fp1))
	{
		system("cls");
		printf("\t\t\t\t   员工的编号:%-3s\n", ID2.people_id);
		printf("\t\t\t\t   员工的姓名:%-3s\n", ID2.people_name);
		printf("\t\t\t\t   员工的工作地:%-3s\n", ID2.people_location);
		printf("\t\t\t\t   员工的职务:%-3s\n", ID2.duties);
		getchar();
		fread(&ID2, sizeof(struct staff), 1, fp1);
	}
	fclose(fp1);
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	int choice;
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
	}
	else
	{
		system("cls");
		staff_2();
	}
}

void query_2()//员工查询
{
	struct staff ID3;
	FILE* fp1;
	fp1 = fopen("yuangong", "r");
	if (fp1 == NULL)
	{
		printf("目前老板孤家寡人，还没有员工哦！！！\n");
		printf("正在退出，请稍后...");
		Sleep(2000);
		increase_staff();
	}
	printf("请您输入员工编号(这里是我们小组成员的学号)");
	char staff_ID[30];
	scanf("%s", staff_ID);
	while (!feof(fp1))
	{
		if (ID3.people_id == staff_ID);
		{
			system("cls");
			printf("\t\t\t\t   员工的编号:%-3s\n", ID3.people_id);
			printf("\t\t\t\t   员工的姓名:%-3s\n", ID3.people_name);
			printf("\t\t\t\t   员工的工作地:%-3s\n", ID3.people_location);
			printf("\t\t\t\t   员工的职务:%-3s\n", ID3.duties);
			getchar();
			fread(&ID3, sizeof(struct staff), 1, fp1);
		}

	}
	fclose(fp1);
	printf("\t\t╭━━━━━━━━━━━━━━━━━━━━━━━╮\n");
	printf("\t\t〇您想继续吗？(y/n)     〇\n");
	printf("\t\t╰━━━━━━━━━━━━━━━━━━━━━━━╯\n");
	int choice;
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
	}
	else
	{
		system("cls");
		staff_2();
	}
}
void staff()//1
{
	int i;
	printf("\t\t\t员工管理系统\n");
	printf("\t\t\t1：新增员工  \n\t\t\t2：员工浏览\n\t\t\t 3：员工查询\n\t\t\t请输入您的选择： \n");
	scanf("%d", &i);
	if (i == 1)
	{
		increase_staff();
	}
	else if (i == 2) {
		look_staff();
	}
	else if (i == 3) {
		query();
	}
	else
	{
		menu1();
	}
}
void staff_2()//2
{
	int i;
	printf("\t\t\t员工管理系统\n");
	printf("\t\t\t1：新增员工  \n\t\t\t2：员工浏览\n\t\t\t 3：员工查询\n\t\t\t请输入您的选择： \n");
	scanf("%d", &i);
	if (i == 1)
	{
		increase_staff();
	}
	else if (i == 2)
	{
		look_staff();
	}
	else if (i == 3) 
	{
		query();
	}
	else
	{
		menu2();
	}
}
int loading(int mima)//密码比对
{
	system("cls");
	FILE* fp;
	struct key i;
	fp = fopen("key", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&i, sizeof(struct key), 1, fp);
	while (!feof(fp))
	{
		if (mima == i.mima)
		{
			fclose(fp);
			return 1;
			break;
		}
		fread(&i, sizeof(struct key), 1, fp);
	}
	fclose(fp);
}
void key()//设置密码
{
	struct key i;
	char choice;
	FILE* fp;
	fp = fopen("key", "ab");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	int n;
	printf("请设置密码\n");
	scanf("%d", &i.mima);
	printf("请确认密码\n");
	scanf("%d", &n);
	if (i.mima != n)
	{
		key();
	}
	fwrite(&i.mima, sizeof(struct key), 1, fp);
	fclose(fp);
	printf("\t\t\t\t\t\t  密码已设置成功!!!\n");
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		key();
	}
	else
	{
		system("cls");
		main();
	}
}
void buy()//商品购买
{
	int a;//输入购买数量
	int b;//原数量
	int r;//钱包金额
	int p;//单价
	int i;
	int input_id;
	struct Ray c[N];
	struct Ray code;
	struct Ray R;
	int index = 0;
	int index1 = 0;
	FILE* fp;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试......");
		exit(0);
	}
	fread(&code, sizeof(struct Ray), 1, fp);
	while (!feof(fp))
	{
		c[index] = code;
		index++;
		fread(&code, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);
	fp = fopen("info", "r");
	fread(&code, sizeof(struct Ray), 1, fp);
	while (!feof(fp))
	{

		index1++;
		printf("\n\n\t****************物品信息%d*****************", index1);
		printf("\n\t物品编号...%30d\n", code.id);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品名称...%30s\n", code.name);
		printf("\n\t-----------------------------------------");
		printf("\n\t生产厂家...%30s\n", code.produce);
		printf("\n\t-----------------------------------------");
		printf("\n\t进口数量...%30d\n", code.number);
		printf("\n\t-----------------------------------------");
		printf("\n\t批发价格...%30.3f\n", code.price);
		printf("\n\t-----------------------------------------\n");
		getchar();
		fread(&code, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);

bought:
	fp = fopen("JIFEN", "r");//读金额
	fread(&R, sizeof(struct Ray), 1, fp);
	r = R.RMB;
	fclose(fp);//
	printf("\t请输入需要购买的商品序号：");
	scanf("%d", &input_id);
	fp = fopen("info", "w");
	for (i = 0; i < index; i++)
	{
		if (input_id == c[i].id)
		{
			printf("\n\t物品编号...%30d\n", c[i].id);
			printf("\n\t-----------------------------------------");
			printf("\n\t物品名称...%30s\n", c[i].name);
			printf("\n\t-----------------------------------------");
			printf("\n\t生产厂家...%30s\n", c[i].produce);
			printf("\n\t-----------------------------------------");
			printf("\n\t进口数量...%30d\n", c[i].number);
			printf("\n\t-----------------------------------------");
			printf("\n\t批发价格...%30.3f\n", c[i].price);
			printf("\n\t-----------------------------------------");
			printf("\t\t\t\t  购买物品的数量:");
			b = *(&c[i].number);
			p = *(&c[i].price);
			scanf(" %d", &a);
			if (r >= a * p)
			{
				c[i].number = b - a;
				fwrite(&c[i], sizeof(struct Ray), 1, fp);
				printf("\t购买成功！");
			}
			else
			{
				printf("\t您的金额不足\n");
				printf("\t您剩余的金额为%d\n", R.RMB);
				goto bought;
			}


		}
		else
		{
			fwrite(&c[i], sizeof(struct Ray), 1, fp);

		}
	}
	fclose(fp);

	fp = fopen("JIFEN", "w");//金额，积分覆写
	R.RMB = r - p * a;
	if (a > 0)
	{
		R.jifen += 10;
	}
	printf("\t您的积分增加为%d\n", R.jifen);
	printf("\t\t\t您剩余的金额为%d\n", R.RMB);
	fwrite(&R, sizeof(struct Ray), 1, fp);
	r = R.RMB;
	fclose(fp);
	char choice;
	printf("请选择是否继续购买商品:\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		buy();
	}
	else
	{
		system("cls");
		menu1();
	}
}

void jindutiao()
{
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	printf("                                         \n");
	{
		printf("\n                                           拼命加载中ing🫡: ");

		for (int i = 0; i <= 100; ++i)
		{
			printf("[");
			int currentIndex = i / Step;
			for (int j = 0; j < IconMaxNum; ++j)
			{
				if (j < currentIndex)
				{
					printf("%c", ProgressIcon);
				}
				else
				{
					printf(" ");
				}
			}

			printf("] ");
			// ----------------------------------------

			// -------- 打印数字进度 ----------
			printf("%3d%%", i);
			fflush(stdout);
			// -------------------------------

			usleep(PrintInterval);

			for (int j = 0; j < strlen(LastStr); ++j)
			{
				printf("\b"); 
			}

			fflush(stdout);
		}
	}
	system("cls");
}
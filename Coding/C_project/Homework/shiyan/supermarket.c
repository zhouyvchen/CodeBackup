#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define N 1000
struct Ray
{
	int id;			  // 编号
	char name[20];	  // 名字
	char produce[30]; // 产品
	int number;		  // 数量
	float price;	  // 价格
};
void look();			// 查询
void Append();			// 添加
void Browse();			// 浏览
int validateID(int id); // 管理账号
void Endprogram();		// 结束程序
void Revision();		// 修改
void Delete();			// 删除
// void menu();//菜单
void Time();	// 节日
void menu1();	// 用户菜单
void menu2();	// 管理员菜单
void Lottery(); // 抽奖

void menu1() // 用户菜单界面
{
	int a, b;
	system("cls");
	struct tm t;		   // tm结构指针
	time_t now;			   // 声明time_t类型变量
	time(&now);			   // 获取系统日期和时间
	localtime_s(&t, &now); // 获取当地日期和时jian
	a = t.tm_mon + 1;
	b = t.tm_mday;
	if (a == 1 & b == 1) // 元旦节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是元旦节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 2 & b == 14) // 情人节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是情人节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 3 & b == 8) // 妇女节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是妇女节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 5 & b == 1) // 劳动节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是劳动节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 6 & b == 1) // 儿童节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是儿童节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 10 & b == 1) // 国庆节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是国庆节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 2 & b == 1) // 春节
	{
		printf("\n\t--------------------------                                ----------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是春节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ----------------------------\n");
	}
	else if (a == 12 & b == 15) // 元宵节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是元宵节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 9 & b == 29) // 中秋节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是中秋节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 12 & b == 25) // 圣诞节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是圣诞节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 6 & b == 22) // 端午节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是端午节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 5 & b == 14) // 母亲节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是母亲节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 6 & b == 18) // 父亲节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是父亲节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else
	{
		printf("\n\t--------------------------                               --------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天不是节日，没有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                --------------------------------\n");
	}
	int choice;
	printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【超市库存管理系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
	printf("\n\t-----------------------------------系统菜单显示如下-------------------------------\n");
	printf("\n\tI:1=====================【           物品信息浏览         】======================I\n");
	printf("\n\tI:2=====================【           退出超市系统         】======================I\n");
	printf("\n\tI:3=====================【           查询商品信息         】======================I\n");
	printf("\n\tI:4=====================【               日期             】======================I\n");
	printf("\n\tI:5=====================【               抽奖             】======================I\n");
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
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		getchar();
		system("cls");
		menu1();
	}
}
void menu2() // 管理员菜单界面
{
	int a, b;
	system("cls");
	struct tm t;		   // tm结构指针
	time_t now;			   // 声明time_t类型变量
	time(&now);			   // 获取系统日期和时间
	localtime_s(&t, &now); // 获取当地日期和时jian
	a = t.tm_mon + 1;
	b = t.tm_mday;
	if (a == 1 & b == 1) // 元旦节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是元旦节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 2 & b == 14) // 情人节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是情人节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 3 & b == 8) // 妇女节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是妇女节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 5 & b == 1) // 劳动节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是劳动节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 6 & b == 1) // 儿童节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是儿童节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 10 & b == 1) // 国庆节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是国庆节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 2 & b == 1) // 春节
	{
		printf("\n\t--------------------------                                ----------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是春节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ----------------------------\n");
	}
	else if (a == 12 & b == 15) // 元宵节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是元宵节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 9 & b == 29) // 中秋节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是中秋节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 12 & b == 25) // 圣诞节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是圣诞节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 6 & b == 22) // 端午节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是端午节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 5 & b == 14) // 母亲节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是母亲节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else if (a == 6 & b == 18) // 父亲节
	{
		printf("\n\t--------------------------                                ------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天是父亲节，有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                ------------------------------\n");
	}
	else
	{
		printf("\n\t--------------------------                               --------------------------------");
		printf("\n\tI今天是：%d年  %d月  %d日I                               I今天不是节日，没有优惠及打折。I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
		printf("\t--------------------------                                --------------------------------\n");
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
	printf("\n\t===================================================================================\n");
	printf("\n\t请输入您要选择的选项：");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		Append();
		break;
	case 2:
		Browse();
		break;
	case 3:
		Endprogram();
		break;
	case 4:
		look();
		break;
	case 5:
		Revision();
		break;
	case 6:
		Delete();
		break;
	case 7:
		Time();
		break;
	case 8:
		Lottery();
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		getchar();
		system("cls");
		menu1();
	}
}
void Append() // 录入
{
	struct Ray i;
	char choice;
	FILE *fp;
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

	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Append();
	}
	else
	{
		system("cls");
		menu1();
	}
}

void Browse() // 浏览
{
	struct Ray i;
	int index = 0;
	char choice;
	FILE *fp;
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
		printf("\n\n\t****************物品信息%d*****************", index);
		printf("\n\t物品编号...%30d\n", i.id);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品名称...%30s\n", i.name);
		printf("\n\t-----------------------------------------");
		printf("\n\t生产厂家...%30s\n", i.produce);
		printf("\n\t-----------------------------------------");
		printf("\n\t进口数量...%30d\n", i.number);
		printf("\n\t-----------------------------------------");
		printf("\n\t批发价格...%30.3f\n", i.price);
		printf("\n\t-----------------------------------------");
		getchar();
		fread(&i, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);

	printf("\n您想继续吗?(y/n)");
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
int validateID(int id) // 账号管理
{
	FILE *fp;
	struct Ray i;
	fp = fopen("info", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
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
void Endprogram() // 退出
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
void main()
{
	printf("\n\n");
	system("color 1a");
	printf("\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                        欢迎使用                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                     超市库存管理系统                          \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                       1:用户菜单                              \3\n");
	printf("\t\3                       2:管理员菜单                            \3\n");
	printf("\t\3                     请选择使用的菜单                          \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
	// getchar();
	int xuanze;
	scanf("%d", &xuanze);

	if (xuanze == 1)
	{
		menu1();
	}
	else if (xuanze == 2)
	{
		menu2();
	}
}
void look() // 查询
{
	struct Ray find;
	int index = 0;
	char choice;
	FILE *fp;
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
		index++;
		printf("\n\n\t****************物品信息%d*****************", index);
		printf("\n\t物品编号...%30d\n", find.id);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品名称...%30s\n", find.name);
		printf("\n\t-----------------------------------------");
		printf("\n\t生产厂家...%30s\n", find.produce);
		printf("\n\t-----------------------------------------");
		printf("\n\t进口数量...%30d\n", find.number);
		printf("\n\t-----------------------------------------");
		printf("\n\t批发价格...%30.3f\n", find.price);
		printf("\n\t-----------------------------------------");
		getchar();
		fread(&find, sizeof(struct Ray), 1, fp);
	}
	fclose(fp);

	printf("\n您想继续吗?(y/n)");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		goto find;
	}
	else
	{
		system("cls");
		menu1();
	}
}
void Revision()
{
	int i;
	int input_id;
	struct Ray c[N];
	struct Ray code;
	int index = 0;
	FILE *fp;
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
	int a = 0;
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
			printf("修改功成！");
		}
		else
		{
			fwrite(&c[i], sizeof(struct Ray), 1, fp);
		}
	}
	fclose(fp);
	int choice;
	printf("\n您想继续吗?(y/n)");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		goto change;
	}
	else
	{
		system("cls");
		menu1();
	}
}
void Delete()
{
	int i;
	int input_id;
	struct Ray c[N];
	struct Ray code;
	int index = 0;
	FILE *fp;
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
	int a = 0;
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
	printf("删除成功！");
	int choice;
	printf("\n您想继续吗?(y/n)");
	scanf_s(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		goto Delete;
	}
	else
	{
		system("cls");
		menu1();
	}
}

void Time()
{
	system("cls");
	int a, b;
	struct tm t; // tm结构指针
	time_t now;	 // 声明time_t类型变量
T:
	time(&now);			   // 获取系统日期和时间
	localtime_s(&t, &now); // 获取当地日期和时jian
	printf("\n\t--------------------------");
	printf("\n\tI今天是：%d年  %d月  %d日I\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	printf("\t--------------------------\n");
	a = t.tm_mon + 1;
	b = t.tm_mday;
	if (a == 1 & b == 1) // 元旦节
	{
		printf("\n");
		printf("今天是元旦节");
	}
	else if (a == 2 & b == 14) // 情人节
	{
		printf("\n");
		printf("今天是情人节");
	}
	else if (a == 3 & b == 8) // 妇女节
	{
		printf("\n");
		printf("今天是妇女节");
	}
	else if (a == 5 & b == 1) // 劳动节
	{
		printf("\n");
		printf("今天是劳动节");
	}
	else if (a == 6 & b == 1) // 儿童节
	{
		printf("\n");
		printf("今天是儿童节");
	}
	else if (a == 10 & b == 1) // 国庆节
	{
		printf("\n");
		printf("今天是国庆节");
	}
	else if (a == 2 & b == 1) // 春节
	{
		printf("\n");
		printf("今天是春节");
	}
	else if (a == 12 & b == 15) // 元宵节
	{
		printf("\n");
		printf("今天是元宵节");
	}
	else if (a == 9 & b == 29) // 中秋节
	{
		printf("\n");
		printf("今天是中秋节");
	}
	else if (a == 12 & b == 25) // 圣诞节
	{
		printf("\n");
		printf("今天是圣诞节");
	}
	else if (a == 6 & b == 22) // 端午节
	{
		printf("\n");
		printf("今天是端午节");
	}
	else if (a == 5 & b == 14) // 母亲节
	{
		printf("\n");
		printf("今天是母亲节");
	}
	else if (a == 6 & b == 18) // 父亲节
	{
		printf("\n");
		printf("今天是父亲节");
	}
	else
	{
		printf("\n\t今天不是节日，没有优惠及打折。\n");
	}
	int choice;
	printf("\n\t您想继续吗?(y/n)\n");
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
void Lottery() // 抽奖
{
	int a;
	char choice;
	srand((unsigned)time(NULL)); // 每次播种的时间不同，那么生成的种子就不同，最终的随机数也就不同
	a = rand() % 10;			 // 产生0~9的随机数，注意10会被整除
	printf("%d\n", a);
	if (a == 1 || a == 2 || a == 3)
	{
		printf("\n您中奖了");
	}
	else
	{
		printf("\n未抽中奖品");
	}
	printf("\n您想继续抽奖吗?(y/n)");
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
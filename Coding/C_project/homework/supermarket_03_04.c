﻿#include <conio.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_ID 11  // ID的最大长度
#define MAX_PWD 20 // 密码的最大长度
#define N 1000
struct ima
{
	int id;
	char name[20];
	char produce[30];
	int number;
	int price;
};
typedef struct Users
{
	char id[MAX_ID];   // id 即登录的账号
	char pwd[MAX_PWD]; // 密码
} Users;

void Register();	 // 注册
void Login();		 // 登录
void RandLMenu();	 // 登录注册菜单
void Append();		 // 录入
void Browse();		 // 浏览
void Findin();		 // 查询
void Change();		 // 修改
void Delete();		 // 删除
void Endprogram();	 // 退出
void menu();		 // 菜单
int vildid(int _id); // id判断
void jindutiao();	 // 进度条

void Register()
{
	Users a, b;

	char tmp[20] = "";

	printf("欢迎来到注册界面!\n");
	FILE *pf = fopen("users.dat", "r");
	fread(&b, sizeof(Users), 1, pf);
	if (!pf)
	{
		printf("%s", strerror(errno)); // errno可以理解是报的错误对应的编号，strerror可以把这个编号翻译出来，输出在屏幕上
		return;
	}
	Sleep(800);

	printf("请输入您的账号>>");
	scanf("%s", a.id);
	while (1)
	{
		if (strcmp(a.id, b.id))
		{
			if (!feof(pf))
			{
				fread(&b, sizeof(Users), 1, pf);
			}
			else
			{
				break;
			}
		}
		else // 有两个用户名相等
		{
			printf("此用户名已存在在,请重新输入!\n");
			Sleep(1000);
			fclose(pf);
			pf = NULL;
			return;
		}
	}

	printf("请输入您的密码>>");
	Getpwd(a.pwd);
	printf("\n请再次确认您的密码>>");
	Getpwd(tmp);
	do
	{
		if (!strcmp(a.pwd, tmp))
		{
			pf = fopen("users.dat", "ab");
			fwrite(&a, sizeof(Users), 1, pf);
			printf("\n账号注册成功,请登录!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("\n两次密码不匹配!请重新输入>>");
			Getpwd(a.pwd);
			printf("\n请再次确认>>");
			Getpwd(tmp);
		}
	} while (1);
	Login();
}

void Login()
{
	Users a, b;

	FILE *pf = fopen("users.dat", "rb");
	if (!pf)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	printf("欢迎来到登录界面!\n");
	Sleep(1000);

	fread(&b, sizeof(Users), 1, pf);

	printf("请输入账号>>");
	scanf("%s", a.id);

	while (1)
	{
		if (!strcmp(a.id, b.id))
		{
			break;
		}
		else
		{
			if (!feof(pf))
			{
				fread(&b, sizeof(Users), 1, pf); // 继续从文件中读取用户信息进b，直到在文件中找到一个和a的信息相同的
			}
			else
			{
				printf("此账号不存在!请重新输入!\n");
				Sleep(500);
				fclose(pf);
				pf = NULL;
				return;
			}
		}
	}
	do
	{
		printf("请输入密码>>");
		Getpwd(a.pwd);
		if (!strcmp(a.pwd, b.pwd)) // 输入的密码与文件中的相同
		{
			printf("\n登录成功!欢迎使用!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("\n密码输入错误,请重新输入\n");
		}
	} while (strcmp(a.pwd, b.pwd));
}

void RandLMenu()
{
	printf("登录或注册你的账号");
	printf("1.登录");
	printf("2.注册");

	printf("请选择功能");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		void Login();
		break;
	case 2:
		void Register();
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		getch();
		system("cls");
		RandLMenu();
	}
}

int vildid(int _id)
{
	struct ima v;
	FILE *fp;
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&v, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		if (_id == v.id)
		{
			fclose(fp);
			return 1;
		}
		fread(&v, sizeof(struct ima), 1, fp);
	}
	fclose(fp);
	return 0;
}
void Delete()
{
	int index = 0;
	int input_id;
	int i;
	int flag = 0;
	char choice;
	struct ima c[N];
	struct ima temp;
	FILE *fp;
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&temp, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		c[index] = temp;
		index++;
		fread(&temp, sizeof(struct ima), 1, fp);
	}
	fclose(fp);
	printf("请输入删除商品编号:");
	scanf("%s", &input_id);
	fp = fopen("GOODS", "w");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	// 遍历结构体数组查找要删除的商品编号，不删除的直接写回文件，要删除的不写回文件
	for (i = 0; i < index; i++)
	{
		if (input_id != c[i].id)
		{
			fwrite(&c[i], sizeof(struct ima), 1, fp);
		}
		else
		{
			flag = 1;
			printf("删除成功！");
		}
	}

	fclose(fp);
	if (flag == 0)
	{
		system("cls");
		printf("此商品编号不存在,请返回主菜单查询编号!\n");
		menu();
	}
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Delete();
	}
	else
	{
		system("cls");
		menu();
	}
}
void Change()
{
	int index = 0;
	int input_id;
	int i;
	int flag = 0;
	char choice;
	struct ima c[N];
	struct ima temp;
	FILE *fp;
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&temp, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		c[index] = temp;
		index++;
		fread(&temp, sizeof(struct ima), 1, fp);
	}
	fclose(fp);
	printf("请输入修改商品编号:");
	scanf("%d", &input_id);
	fp = fopen("GOODS", "w");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	// 遍历结构体数组查找要修改的商品编号，不修改的直接写回文件，要修改的先修改在写回文件
	for (i = 0; i < index; i++)
	{
		if (input_id == c[i].id)
		{
			flag = 1;
			printf("\t\t\t\t   修改物品的名称:");
			scanf("%s", c[i].name);
			printf("\t\t\t\t   修改物品的生产地:");
			scanf("%s", c[i].produce);
			printf("\t\t\t\t   修改物品的数量:");
			scanf("%d", &c[i].number);
			printf("\t\t\t\t   修改物品的单价:");
			scanf("%d", &c[i].price);
			printf("\t\t\t\t   修改成功!\n");
			fwrite(&c[i], sizeof(struct ima), 1, fp);
		}
		else
		{
			fwrite(&c[i], sizeof(struct ima), 1, fp);
		}
	}
	fclose(fp);
	if (flag == 0)
	{
		system("cls");
		printf("此商品编号不存在,请返回主菜单查询编号!\n");
		menu();
	}
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Change();
	}
	else
	{
		system("cls");
		menu();
	}
}
void Findin()
{
	struct ima f;
	int find_id;
	char choice;
	FILE *fp;
Flag:
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}

	printf("请输入查询的商品编号:");
	scanf("%d", &find_id);
	fread(&f, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		if (find_id == f.id)
		{
			printf("\n\n\t****************物品信息*****************");
			printf("\n\t物品编号...%30d\n", f.id);
			printf("\n\t-----------------------------------------");
			printf("\n\t物品名称...%30s\n", f.name);
			printf("\n\t-----------------------------------------");
			printf("\n\t生产厂家...%30s\n", f.produce);
			printf("\n\t-----------------------------------------");
			printf("\n\t进口数量...%30d\n", f.number);
			printf("\n\t-----------------------------------------");
			printf("\n\t批发价格...%30d\n", f.price);
			printf("\n\t-----------------------------------------");
			fclose(fp);
			printf("\n您想继续吗?(y/n)");
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				Findin();
			}
			else
			{
				system("cls");
				menu();
			}
		}
		fread(&f, sizeof(struct ima), 1, fp);
	}
	fclose(fp);
	printf("此商品不存在，请重新输入编号:");
	goto Flag;
}
void Append()
{
	struct ima a;
	char choice;
	FILE *fp;
	fp = fopen("GOODS", "ab");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
LABID:
	printf("\n\t请您输入要入库物品的信息...\n");
	printf("\t\t\t\t   物品的编号:");
	scanf("%d", &a.id);
	if (vildid(a.id) == 1)
	{
		printf("\t\t\t\t此编号已被使用，请您重新输入......");
		goto LABID;
	}
	printf("\t\t\t\t   物品的名称:");
	scanf("%s", a.name);
	printf("\t\t\t\t   物品的生产地:");
	scanf("%s", a.produce);
	printf("\t\t\t\t   物品的数量:");
	scanf("%d", &a.number);
	printf("\t\t\t\t   物品的单价:");
	scanf("%d", &a.price);
	fwrite(&a, sizeof(struct ima), 1, fp);
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
		menu();
	}
}
void Browse()
{
	struct ima b;
	int index = 0;
	char choice;
	FILE *fp;
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&b, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		index++;
		printf("\n\n\t****************物品信息%d*****************", index);
		printf("\n\t物品编号...%30d\n", b.id);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品名称...%30s\n", b.name);
		printf("\n\t-----------------------------------------");
		printf("\n\t生产厂家...%30s\n", b.produce);
		printf("\n\t-----------------------------------------");
		printf("\n\t进口数量...%30d\n", b.number);
		printf("\n\t-----------------------------------------");
		printf("\n\t批发价格...%30d\n", b.price);
		printf("\n\t-----------------------------------------");
		getch();
		fread(&b, sizeof(struct ima), 1, fp);
	}
	fclose(fp);
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Append();
	}
	else
	{
		system("cls");
		menu();
	}
}
void Endprogram()
{
	char choice;
	system("cls");

	printf("\n\n\n\n\n\n\n\t\t\t您确定要退出系统吗?\n\n\n\t\t\t如果您想退出请按'y',其它键将返回主菜单.....");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t谢谢您的使用!!!");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		exit(0);
	}
	else
	{
		system("cls");
		menu();
	}
}
void menu()
{
	int choice;
	printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【超市库存管理系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
	printf("--------------------------------系统菜单显示如下--------------------------------");
	printf("\n\t1=====================【           新购物品入库         】\n");
	printf("\n\t2=====================【           物品信息浏览         】\n");
	printf("\n\t3=====================【           物品信息查询         】\n");
	printf("\n\t4=====================【           物品信息修改         】\n");
	printf("\n\t5=====================【           物品信息删除         】\n");
	printf("\n\t6=====================【           退出                】\n");

	printf("\n\t请输入您要选择的菜单......");
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
		system("cls");
		Findin();
		break;
	case 4:
		Change();
		break;
	case 5:
		Delete();
		break;
	case 6:
		Endprogram();
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		getch();
		system("cls");
		menu();
	}
}
int main()
{
	printf("\n\n");
	// system("color 1a");
	printf("\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                        欢迎使用                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                     超市库存管理系统                          \3\n");
	printf("\t\3                      按任意键继续                             \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3");
	getch();
	system("cls");
	RandLMenu();
	return 0;
}
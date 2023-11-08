#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#define pi 3.1415926
double B1[4], B2[4];
double B1_avarage, B2_avarage;//B1为减速的平均值，B2为加速的平均值
double R = 0.025;//塔轮的半径
double Rw = 0.12, Rn = 0.105;
float g = 9.8;
float m = 0.02389;
float mh = 0.42417;
//定义匀减速的参数
int kn0[4] = { 5,6,7,8 }, km0[4] = { 1, 2, 3, 4 };//输入kn,km的值
double tm0[4], tn0[4];//输入tm,tn的值
//定义匀加速的参数
int kn1[4] = { 5,6,7,8 }, km1[4] = { 1, 2, 3, 4 };//输入kn,km的值
double tm1[4], tn1[4];//输入tm,tn的值

void   mathb(int kn[], int km[], double tm[], double tn[], int a, int b);
void   mathb(int kn[], int km[], double tm[], double tn[], int a, int b)//打印计算的贝塔2,并求出平均值
{
	if (a == 0)//匀减速操作
	{
		printf("----------------------------------------------------------------------\n");
		printf("**匀减速的数据为：\n");
		for (int i = 0; i < 4; i++)
		{
			B1[i] = (2 * pi * (kn[i] * tm[i] - km[i] * tn[i])) / ((tn[i] * tn[i] * tm[i]) - (tm[i] * tm[i] * tn[i]));

			printf("计算结果为：%lf\n", B1[i]);
		}

		int size = sizeof(B1) / sizeof(B1[0]);
		for (int i = 0; i < size; i++)
		{
			B1_avarage += B1[i];
		}
		B1_avarage /= size;
		printf("平均数为：%lf\n", B1_avarage);
		printf("----------------------------------------------------------------------\n");
	}
	if (a == 1)//匀加速操作
	{
		printf("----------------------------------------------------------------------\n");
		printf("**匀加速的数据为：\n");
		for (int i = 0; i < 4; i++)
		{
			B2[i] = (2 * pi * (kn[i] * tm[i] - km[i] * tn[i])) / ((tn[i] * tn[i] * tm[i]) - (tm[i] * tm[i] * tn[i]));

			printf("计算结果为：%lf\n", B2[i]);
		}

		int size = sizeof(B2) / sizeof(B2[0]);
		for (int i = 0; i < size; i++)
		{
			B2_avarage += B2[i];
		}
		B2_avarage /= size;
		printf("平均数为：%lf\n", B2_avarage);
		printf("----------------------------------------------------------------------\n");
	}
}
void calculateJ1();//误差分析
void  calculateJ1()
{
	double J1 = (m * R * (g - R * B2_avarage)) / (B2_avarage - B1_avarage);
	printf("请记录J1，J1的值为： %lf", J1);

}
void  shuru();
void  shuru()
{
	printf("----------------------------------------------------------------------\n");
	printf("--请输入匀减速的数据\n");
	printf("tm:");
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf", &tm0[i]);
	}
	printf("\ntn:");
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf", &tn0[i]);
	}
	printf("----------------------------------------------------------------------\n");
	printf("--请输入匀加速的数据\n");
	printf("tm:");
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf", &tm1[i]);
	}
	printf("\ntn:");
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf", &tn1[i]);
	}
}




int main()
{
	double J;
	double J1 = 0.010517;
	double J2 = 0.013754;
	double J3 = 0.003237;
	double E;
	double d = 0.1;
	//J3 = J2 - J1;
	//J = (mh * (Rw * Rw + Rn * Rn)) / 2;
	shuru();
	system("cls");
	printf("你的实验数据为:\n");
	mathb(kn0, km0, tm0, tn0, 0, 1);
	mathb(kn1, km1, tm1, tn1, 1, 0);
	calculateJ1();
	//printf("\nJ=%lf", J);
	//printf("%lf", J3);
	//E = ((J3 - J) / J);
	//printf("E:%lf", E);
    system("PAUSE");
    return 0;
}
#include <stdio.h>
#include <windows.h>
struct pro
{
    char nub[20];
    char name[20];  
    float price;
    char loction[1000];
}pro[3];

int main()
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("请输入商品的序号名字价格产地");
        scanf("%s %s %f %s", &pro[i].nub, &pro[i].name, &pro[i].price, &pro[i].loction);
    }
system("cls");
    
    for(i=0; i<3; i++)
    {
        printf("序号是 %s\n", pro[i].nub);
        printf("名字是 %s\n", pro[i].name);
        printf("价格是 %f\n", pro[i].price);
        printf("产地是 %s\n", pro[i].loction);
        printf("\n");
    }
    return 0;
}
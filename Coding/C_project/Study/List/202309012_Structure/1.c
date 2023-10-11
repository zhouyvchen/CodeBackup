#include <stdio.h>

struct student
{
    int num;
    char name[20];
};

void display(struct student stu)
{
    printf("%d %s\n", stu.num, stu.name);
}

int main()
{
    struct student stu1 = {1, "zhou"};
    display(stu1);
    return 0;
}
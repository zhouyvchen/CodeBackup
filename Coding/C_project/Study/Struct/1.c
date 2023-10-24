//
// Created by bokeboke on 2023/10/23.
//
//保存一百个学生的信息
#include <stdio.h>
struct Student{
    int id;
    int age;
    char *name;
};

void test(struct Student *student){
    student->age = 330;
}
int main(){
    struct Student stu1 = {1, 18, "zhou"};
    struct Student stu2 = {.id = 2, .name = "zhen", .age = 19};
    struct Student *p = &stu1;
    test(stu1);
    printf("stu1's age is %d\n", stu1->age);
}
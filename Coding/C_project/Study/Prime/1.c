#include <stdio.h>

void swap(int* a, int* b);
int* test(int* a);
int sum(int a, int b);

int main() { /*
     int a = 10, b = 20;
     swap(&a, &b);

     printf("a = %d, b = %d\n", a, b);

     char str[] = "Hello world!!!";
     char* p = str;
     printf("%c\n", *p);

     // 数组和指针
     // 一维数组
     char str1[] = "hello world!";
     char* p1 = str1;
     printf("%c\n", *(str1 + 1));

     // 二维数组
     int str2[2][3] = {{1, 2, 3}, {4, 5, 6}};
     int* p2 = str2[0];
     printf("#d\n", *(p2 + 1));
 */
             // 多级指针
             /*
             int a = 10;
             int* p = &a;
             int** pp = &p;
             printf("%p, %p", *p, *pp);
             */

    // 指针数组
    /*int a, b, c;
    int* str[] = {&a, &b, &c};

    *str[0] = 999;
    printf("a = %d\n", a);
*/

    // 指针函数和函数指针
    // 指针函数
    int a = 10;
    int* b = test(&a);
    printf("%d\n", b);

    // 函数指针
    int (*p)(int, int) = sum;

    int Sum = p(1, 2);
    printf("%d", Sum);


}

int* test(int* a) {
    return a;
}

int sum(int a, int b) {
    return a + b;
}
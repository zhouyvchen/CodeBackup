#include <stdio.h>

int sum(int (*p)(int, int), int a, int b) {
    return p(a, b);
}

int sumImpl(int a, int b) {  // 这个函数实现了a + b
    return a + b;
}

int main() {
    int (*p)(int, int) = sumImpl;  // 拿到实现那个函数的地址
    printf("%d", sum(p, 10, 20));
}
#include <stdio.h>

int sum(int (*p)(int, int), int a, int b) {
    return p(a, b);
}

int sumImpl(int a, int b) {
    return a + b;
}
int main() {
    int (*p)(int, int) = sumImpl;
    printf("%d\n", sum(p, 10, 20));
}
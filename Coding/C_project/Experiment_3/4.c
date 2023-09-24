#include <stdio.h>
int main() {
  int i = 100;
  for (i; i < 1000; i++) {
    int a, b, c;       // 用abc来表示这个数i的每一位
    a = i / 100 % 10;  // 分离出每一位作判断
    b = i / 10 % 10;
    c = i % 10;
    if (i == a * a * a + b * b * b + c * c * c) {
      printf("%d\n", i);
    }
  }
  return 0;
}
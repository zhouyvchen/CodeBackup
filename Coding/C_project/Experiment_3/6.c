#include <stdio.h>
int main() {
  int a, i;
  for (a = 2; a < 1000; a++) {
    int sum = 0;
    for (i = 1; i < a; i++)  // 对每一个1000以内的数进行判断
    {
      if (a % i == 0)  // 如果a能被i整除则说i为a的一个因子
      {
        sum += i;  // 将因子之和加起来
      }
    }
    if (sum == a) {
      printf("%d是一个完数,它的因子为:%d", a, a);
      for (i = 1; i < a; i++) {
        if (a % i == 0) {
          printf("+%d", i);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
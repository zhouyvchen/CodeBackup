#include <stdio.h>
int main() {
  int n, i;
  printf("打印一个九九乘法表\n");
  for (n = 1; n <= 9; n++) {
    for (i = 1; i <= n; i++) {
      printf("%d*%d=%d", i, n, i * n);
    }
    printf("\n");
  }
  return 0;
}
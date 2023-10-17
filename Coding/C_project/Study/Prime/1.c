#include <stdio.h>

void swap(int *a, int *b);

int main() {
  int a = 10, b = 20;
  swap(&a, &b);

  printf("a = %d, b = %d\n", a, b);

  char str[] = "Hello world!!!";
  char *p = str;
  printf("%c", *p);
  return 0;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

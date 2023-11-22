#include <stdio.h>
int main() {
    int i, n, arr[31];
    scanf("%d", &n);
    arr[0] = 0;
    arr[1] = 1;
    for (i = 2; i <= n; i++) {  // 按照公式，依次jisuan
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%d\n", arr[n]);
}
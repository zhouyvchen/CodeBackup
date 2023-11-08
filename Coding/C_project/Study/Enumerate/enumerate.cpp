//
// Created by bokeboke on 2023/10/25.
//用枚举来表达低中高三个档位

#include "stdio.h"
enum status {
    low = 1,
    middle = 2,
    high = 3,
};

int main() {
    enum status s = middle;
    printf("%d", s);
    return 0;
}
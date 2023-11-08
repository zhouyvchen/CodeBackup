//
// Created by bokeboke on 2023/10/25.
//联合体公用同一段内存空间

#include "stdio.h"

union object{
    int a;
    char b;
    float c;
};

int main(){
    union object obj;
    obj.a = 126;
    printf("%lu\n", sizeof (obj));
    return 0;
}
/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    int result = 0, t;
    int y = x>=0?x:-x;
    int a, b;
    /* 最小整数翻转就是0 */
    if(x == 0x80000000) return 0;
    a = 0x7FFFFFFF/10;
    b = 0x7FFFFFFF%10;
    while(y!=0) {
        t = y%10;
        /* 防止溢出 */
        if((result>a) || (result==a && t>b)) return 0; 
        result = result*10 + t;
        y = y/10;
    }
    return x>=0?result:-result;
}

int main() {
    printf("%d\n", reverse(1534236469));
    printf("%d\n", reverse(-2147483648));
    printf("%d\n", reverse(0));
    printf("%d\n", reverse(1));
    printf("%d\n", reverse(-1200));
    return 0;
}
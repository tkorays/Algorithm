/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int i, j, m, n, y = x;
    if(x<0) return false;
    for(i=1000000000, j=10; i>=j; i /= 10) {
        m = y/i;
        if(j==10 && m==0) continue;
        /* bottleneck */
        n = (y%j - y%(j/10))*10/j;
        if(m!=n) return false;
        y = y - m*i;
        j *= 10;
    }
    return true;
}

int main() {
    printf("%d\n", isPalindrome(12321));
    printf("%d\n", isPalindrome(1000030001));
    printf("%d\n", isPalindrome(2321));
    printf("%d\n", isPalindrome(1));
    printf("true;%d\n", true);
    return 0;
}
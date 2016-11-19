/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/
#include <stdlib.h>
#include <stdio.h>

int myAtoi(char* str) {
    int result = 0, i = 0, flag = -1, a, b;
    a = 0x7FFFFFFF/10;
    b = 0x7FFFFFFF%10;
    while(flag==-1 && str[i]!='\0') {
        if(str[i] == ' ') {i++; continue;}
        else if(str[i] == '+') {i++; flag = 0;}
        else if(str[i] == '-') {i++; flag = 1;}
        else if(str[i]>='0' && str[i]<='9') {flag = 0;}
        else return 0;
    }
    while(str[i]!='\0') {
        if(str[i]<'0' || str[i]>'9') return flag==0?result:-result;
        if(flag==0) {
            if((result>a) || (result==a && (str[i] - '0')>b)) return 0x7FFFFFFF;
        } else {
            if((result>a) || (result==a && (str[i] - '0')>(b+1))) return 0x80000000;
        }
        result = result*10 + (str[i] - '0');
        i++;
    }
    return flag==0?result:-result;
}

int main() {
    printf("%d\n",myAtoi(""));
    printf("%d\n",myAtoi("1234"));
    printf("%d\n",myAtoi("-1234"));

    printf("%d\n",myAtoi("+123476"));
    printf("%d\n",myAtoi("-1234abc"));
    printf("%d\n",myAtoi("ab-1234abc"));
    printf("%d\n",myAtoi("  2147483648"));
    printf("%d\n",myAtoi("  2147483690"));
    printf("%d\n",myAtoi("-2147483648"));
    printf("%d\n",myAtoi("-2147483677"));
    return 0;
}
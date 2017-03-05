#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* intToRoman(int num) {
    int i = 0, j, k;
    char* d[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };
    char* s = 0;
    s = (char*)malloc(40);
    memcpy(s+i, d[3][num/1000%10], k=strlen(d[3][num/1000%10])), i += k;
    memcpy(s+i, d[2][num/100%10], k=strlen(d[2][num/100%10])), i += k;
    memcpy(s+i, d[1][num/10%10], k=strlen(d[1][num/10%10])), i += k;
    memcpy(s+i, d[0][num%10], k=strlen(d[0][num%10])), i += k;
    s[i] = '\0';
    return s;
}

int main() {
    printf("%s\n", intToRoman(233));
    printf("%s\n", intToRoman(1980));
    printf("%s\n", intToRoman(1666));
    printf("%s\n", intToRoman(3999));
    return 0;
}
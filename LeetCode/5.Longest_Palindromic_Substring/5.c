/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int i, j;
    int mr = 0, c = 0, ml = 0, len = 0;
    int rl[2001] = {0};
    len = 2 * strlen(s) + 1;
    for(i = 0; i < len; i++) {
        rl[i] = i < mr ? (rl[2*c - i] > (mr - i) ? (mr - i) : rl[2*c - i]) : 1;
        while((i - rl[i] >= 0) && (i + rl[i] < len)) {
            if((((i + rl[i]) % 2 == 1) && (s[(i-1)/2 - rl[(i-1)/2]] == s[(i-1)/2 + rl[(i-1)/2]])) || ((i + rl[i]) % 2 == 0)) rl[i] += 1;
            else break;
        }
        if(rl[i] + i - 1 > mr) {
            mr = rl[i] + i - 1;
            c = i;
        }
        ml = ml > rl[i] ? ml : rl[i];
    }
    printf("%d,%d\n", c, ml);
    j = c % 2 == 1 ? ((c-1)/2 - (rl[c]-1)/2) : (c/2 + 1 - (rl[c]-1)/2);
    s[j + rl[j] - 1] = '\0';
    return s+j;
}

int main() {
    char s[] = "efabcbadefg";
    printf("%s\n", longestPalindrome(s));
    return 0;
}

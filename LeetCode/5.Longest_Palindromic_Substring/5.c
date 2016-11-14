/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// http://www.tkorays.com/2016/10/31/Longest-Palindromic-Substring/
char* longestPalindrome(char* s) {
    int i,j, n;
    int c = 0, r = 0;
    int ml = 0, cur = 0;
    int P[2001] = {0};
    n = strlen(s);
    for(i=1; i<2*n; i++) {
        j = 2*c - i;
        P[i] = i < r ? (P[j] < (r-i) ? P[j] : (r-i)) : 0;
        while((i+1+P[i] < (2*n+1) && (i-1-P[i]>=0))) {
            if((i+1+P[i])%2==1 && (s[(i+1+P[i])/2] != s[(i-1-P[i])/2])) {
                break;
            }
            P[i]++;
        }
        if((i+P[i]) > r) {
            c = i;
            r = i + P[i];
        }
    }

    for(i=0; i<=2*n; i++) {
        // > 则取第一个次遇到的最长串
        if(P[i] >= ml) {
            cur = i;
            ml = P[i];
        }
    }
    s[(cur-ml)/2 + ml] = '\0';
    return s + (cur-ml)/2;
}

int main() {
    char s[] = "efabcbadefg";
    printf("%s\n", longestPalindrome(s));
    return 0;
}

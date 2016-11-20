/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


bool isMatch(char* s, char* p) {
    int i = 0, j = 0, r;
    while(*(p+j) != '\0') {
        if(*(p+j) == '.' && *(s+i)!='\0') {i++; j++; continue;}
        else if(*(p+j) == '*') {
            if(*(p+j+1)==*(p+j-1) && *(p+j+2)=='*') {j+=2; continue;}
            r = isMatch(s+i, p+j+1) || isMatch(s+i-1, p+j+1) ;
            if((*(s+i-1)==*(s+i) || *(p+j-1) == '.') && *(s+i)!='\0') {
                r = r || isMatch(s+i+1, p+j) || isMatch(s+i+1, p+j+1);
            } 
            return r;
        } else if(*(s+i) == *(p+j)) {i++; j++; continue;}
        else if(*(s+i) != *(p+j) && *(p+j+1) == '*') {j+=2; continue;}
        else return false;
    }
    if(*(s+i)=='\0' && *(p+j)=='\0') return true;
    else return false;
}

// abcabcef
// .*bcef

int main() {
    int i = 0;
    printf("[%d]%d==%d\n",i++,1, isMatch("", ""));
    printf("[%d]%d==%d\n",i++,0, isMatch("", "."));
    printf("[%d]%d==%d\n",i++,1, isMatch("abc", "abc"));
    printf("[%d]%d==%d\n",i++,0, isMatch("aa", "a"));
    printf("[%d]%d==%d\n",i++,1, isMatch("aaa", "aaa"));
    printf("[%d]%d==%d\n",i++,1, isMatch("aa", ".a"));
    printf("[%d]%d==%d\n",i++,1, isMatch("aaa", "a*a"));
    printf("[%d]%d==%d\n",i++,1, isMatch("aa", ".*"));
    printf("[%d]%d==%d\n",i++,1, isMatch("ab", ".*")); // *
    printf("[%d]%d==%d\n",i++,1, isMatch("aab", "c*a*b*"));
    printf("[%d]%d==%d\n",i++,0, isMatch("ab", ".*c")); 
    printf("[%d]%d==%d\n",i++,0, isMatch("aaba", "ab*a*c*a")); 
    printf("[%d]%d==%d\n",i++,0, isMatch("aba", "a*c*a")); 
    printf("[%d]%d==%d\n",i++,1, isMatch("a", "a*a")); 
    printf("[%d]%d==%d\n",i++,0, isMatch("a", ".*..a*")); 
    printf("[%d]%d==%d\n",i++,0, isMatch("aaaaaaaaaaaaa", "a*a*a*a*a*a*a*a*a*c")); 
    return 0;
}
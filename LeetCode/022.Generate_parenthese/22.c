/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_parenthese(char** ret, int* c, char* s, int a, int b, int n) {
    if((a-b)<0 || a>n || b>n) return;
    if(a==n && b==n) {
        ret[*c] = (char*)malloc(2*n+1);
        memcpy(ret[*c], s, 2*n);
        ret[*c][2*n] = '\0';
        (*c)++;
        return ;
    }
    s[a+b] = '(';
    add_parenthese(ret, c, s, a+1, b, n);
    s[a+b] = ')';
    add_parenthese(ret, c, s, a, b+1, n);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char** ret = (char**)malloc(sizeof(char*)*100000);
    char* m = (char*)malloc(2*n);
    int c = 0;
    add_parenthese(ret, &c, m, 0, 0, n);
    *returnSize = c;
    return ret;
}

int main() {
    int c = 0;
    int i;
    char** ret = generateParenthesis(8, &c);
    printf("%d\n", c);
    for(i=0; i<c; i++) {
        printf("%s\n", ret[i]);
    }
}
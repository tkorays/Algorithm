/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include <stdio.h>
#include <stdlib.h>


/*
Your runtime beats 72.09% of c submissions.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    int i = 0, j = 0, k, m, p, n = 1;
    char** ret = 0;
    char li[][5] ={
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    while('\0' != digits[i]) {
        if(digits[i] == '7' || digits[i]=='9') n *= 4;
        else n *= 3;
        i++;
    }
    *returnSize = (i==0?0:n);

    ret = (char**)malloc(sizeof(char*)*n);
    for(j=0; j<n; j++) {
        ret[j] = (char*)malloc(sizeof(char)*(i+1));
        m = j;
        for(k=0; k<i; k++) {
            if(digits[k]=='7' || digits[k]=='9') p = 4;
            else p = 3;
            ret[j][k] = li[digits[k]-'2'][m%p];
            m = m/p;
        }
        ret[j][k] = '\0';
    }
    return ret;
}


int main() {
    printf("%d\n", 1%3);
    return 0;
}
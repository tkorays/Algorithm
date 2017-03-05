/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
Subscribe to see which companies asked this question.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int

bool isValid(char* s) {
    int i = 0, pt = -1;
    int n = strlen(s);
    char* m = (char*)malloc(n);
    for(i=0; i<n; i++) {
        switch(s[i]) {
        case '(': 
        case '[': 
        case '{': 
            m[++pt] = s[i];break;
        case ')': 
            if(pt>=0 && m[pt]=='(') pt--;else return 0;break;
        case ']': 
            if(pt>=0 && m[pt]=='[') pt--;else return 0;break;
        case '}': 
            if(pt>=0 && m[pt]=='{') pt--;else return 0;break;
        default: break;
        }
    }
    if(pt!=-1) return 0;
    return 1;
}

int main() {
    printf("%d\n",isValid("(){}[]"));
    printf("%d\n",isValid("(())"));
    printf("%d\n",isValid("("));
    printf("%d\n",isValid("({}[])"));
    printf("%d\n",isValid("([)]"));
}
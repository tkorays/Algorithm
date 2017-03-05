#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char* s = 0;
    int len = 0, i = 0, j = 0, k = 0;
    if(strsSize != 0 ){
        while(strs[0][i] != '\0') {
            k = 0;
            for(j = 1; j < strsSize; j++) {
                if(strs[j][i] != strs[0][i]) { k = 1; break;}
            }
            if(k == 1) break;
            len++;
            i++;
        }
    } else len = 0;
    s = (char*)malloc(len+1);
    if(len!=0) memcpy(s, strs[0], len);
    s[len] = '\0';
    return s;
}

int main() {
    char* ss[32] = {"abcdsdfadf", "abcdff", "abctg"};
    char* s = 0;
    s = longestCommonPrefix(ss, 3);
    printf("CommonPrefix: %s\n", s);
    return 0;
}
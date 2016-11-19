/*
 *  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *
 *  And then read line by line: "PAHNAPLSIIGYIR"
 *
 *  Write the code that will take a string and make this conversion given a number of rows:
 *
 *  string convert(string text, int nRows);
 *
 *  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
 */

#include <string.h>
#include <stdio.h>

/*
    拓展数组，空白部分填0，建立映射 13.79%
 */
char* convert_v1(char* s, int numRows) {
    int n = strlen(s);
    int m = 2*numRows - 2;
    int i,j,k,p,q,numCols;
    char* ret = 0;
    if(numRows==1) return s;
    numCols = (numRows-1)*(n/m + 1);
    ret = (char*)malloc(numRows*numCols);
    memset(ret, 0, numRows*numCols);
    p = numRows*numCols;
    i = 0;
    for(q=0; q<p; q++) {
        for(j=0; (j<numRows)&&(i<n); j++, i++) {
            ret[j*numCols+q*(numRows-1)] = s[i];
        }
        for(k=1; (k<(numRows-1))&&(i<n); k++, i++) {
            ret[(numRows-1-k)*numCols+q*(numRows-1)+k] = s[i];
        }
        if(i>=n) break;
    }
    for(i=0,j=0; i<numRows*numCols; i++) {
        if(ret[i]=='\0') continue;
        ret[j++] = ret[i];
    }
    ret[n] = '\0';
    return ret;
}

/*
    字符串最后填充$，凑整数倍，直接映射，计算
 */
char* convert_v2(char* s, int numRows) {
    int n = strlen(s);
    int m = 2*numRows - 2;
    int i,j,k,p,t;
    char* ret = 0;
    if(numRows==1) return s;
    ret = (char*)malloc(n+1);
    p = n/m + (n%m==0?0:1);
    i=0;
    for(t=0; t<p; t++) {
        for(j=0; j<numRows; j++,i++) {
            if(j==0) ret[t] = s[i];
            else if(j==(numRows-1)) ret[p+2*p*(numRows-2)+t] = i<n?s[i]:'$';
            else ret[p+(j-1)*2*p+t*(numRows-1)] = i<n?s[i]:'$';
        }
        for(k=1; k<(numRows-1); k++,i++) {
            ret[p+(numRows-2-k)*2*p+t*(numRows-1)+1] = i<n?s[i]:'$';
        }
    }
    for(i=0,j=0; i<p*m; i++){
        if(ret[i]=='$') continue;
        ret[j++] = ret[i];
    }
    ret[n] = '\0';
    return ret;
}



int main() {
    char* ret = convert_v2("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.",
2);
    printf("%s should be ?\n", ret);
    return 0;
}

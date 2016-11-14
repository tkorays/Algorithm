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


char* convert(char* s, int numRows) {
    int R[100] = {0};
    int n = strlen(s);
    int i = 2*numRows - 2;
    int c = n/i;
    int r = n%i;
    int j = 0;
    char* ret = (char*)malloc(n+1);
    for(j=0; j<numRows; j++) {
        R[j] = c + (r>i:1:0) + ((j+r)/2 == numRows ? 1 : 0);
    }
    for(i=0; i<n; i++) {
        ret[i] = 
    }
    ret[n] = '\0';
    return ret;
}

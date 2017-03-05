#include <stdio.h>
#include <stdlib.h>


int romanToInt(char* s) {
    int ret = 0, i = 0;
    int m[26] = {0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10,0,0};
    while(s[i] != '\0') {
        if((s[i+1] != '\0') && (m[s[i]-'A']<m[s[i+1]-'A'])) ret -= m[s[i]-'A'];
        else ret += m[s[i]-'A'];
        i++;
    }
    return ret;
}

int main() {
    printf("%d\n", romanToInt("MDCLXVI"));
    printf("%d\n", romanToInt("MMMCMXCIX"));
    printf("%d\n", romanToInt("MCMXC"));
    printf("%d\n", romanToInt("M"));
    return 0;
}
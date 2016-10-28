/*
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int max = 0, start = 0, cur = 0;
    int i;
    while(s[cur] != '\0') {
        for(i = start; i < cur; i++)
            if(s[cur] == s[i]) start = i + 1;
        cur++;
        max = (cur - start) > max ? (cur - start) : max;
    }
    return max;
}


int main() {
    const char* s1 = "abcabcbb";
    const char* s2 = "bbbbb";
    const char* s3 = "pwwkew";
    printf("%d=%d\n", lengthOfLongestSubstring(s1), 3);
    printf("%d=%d\n", lengthOfLongestSubstring(s2), 1);
    printf("%d=%d\n", lengthOfLongestSubstring(s3), 3);
    return 0;
}

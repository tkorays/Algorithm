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

// leetcode 上面有一种比较神奇的解法
// 它记录了字符每一次出现的地方的下一个位置,index[s[j]] = j + 1
// 如果再出现了，则start从这个地方开始, i = index[s[j]] > i ? index[s[j]] : i;
// 这种查表法，效率很高，O(n) !!!
// int n = s.length(), ans = 0;
//
// int index[128] = { 0 };
// for (int j = 0, i = 0; j < n; ++j)
// {
// 若遇到相同字符，此时的s[j]对应的值一定比i大
// i = index[s[j]]>i ? index[s[j]] : i;
// ans = ans > j - i + 1 ? ans : j - i + 1;
// 刷新表
// index[s[j]] = j + 1;
// }
// return ans;

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

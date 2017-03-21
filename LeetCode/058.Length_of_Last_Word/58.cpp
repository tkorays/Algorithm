class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length(), i = len - 1, cnt = 0;
        while (i >= 0) { if (s[i] == ' ') { i--; continue; } break; }
        while (i >= 0) { if (s[i--] == ' ') break; cnt++; }
        return cnt;
    }
};
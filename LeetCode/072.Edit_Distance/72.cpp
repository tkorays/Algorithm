/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        if(len1 == 0) return len2;
        if(len2 == 0) return len1;
        int m[1000][1000] = {0};
        for(int i = 1; i <= len1; i++) m[i][0] = i;
        for(int i = 1; i <= len2; i++) m[0][i] = i;

        for(int j = 1; j <= len2; j++) {
            for(int i = 1; i <= len1; i++) {
                if(word1[i-1] == word2[j-1]) m[i][j] = m[i-1][j-1];
                else {
                    m[i][j] = (m[i-1][j] < m[i][j-1] ? m[i-1][j] : m[i][j-1]);
                    m[i][j] = (m[i][j] < m[i-1][j-1] ? m[i][j] : m[i-1][j-1]) + 1;
                } 
            }
        }
        return m[len1][len2];
    }
};

int main() {
    Solution s;
    cout<<s.minDistance("acadefgssd","defgasd")<<endl;
    return 0;
}
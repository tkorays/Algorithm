/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if(m == 0) return ;
        int n = matrix[0].size();
        if(n == 0) return ;

        for(int i = 0, isZero = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
            }
        }
    }
};
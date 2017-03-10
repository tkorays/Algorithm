/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Subscribe to see which companies asked this question.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 1;
        
        int left = 1, right = nums[0];
        for(int i=1; (i<size) && (nums[i]>0); i++) {
            if(nums[i] >)
        }
        if(left<right) return left+1;
        else return right+1;
    }
};
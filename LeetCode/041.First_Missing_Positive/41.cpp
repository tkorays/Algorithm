/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Subscribe to see which companies asked this question.
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, size = nums.size();
        for(; i < size; i++) {
            while(1) {
                if((i+1) == nums[i] || nums[i] <= 0 || nums[i] > size) break;
                int t = nums[i];
                nums[i] = nums[t-1];
                nums[t-1] = t;
                if(nums[i] == t) nums[t-1] = -1;
            }
        }
        for(i = 0; i<size && nums[i]==(i+1); i++) ;
        return i+1;
    }
};

int main() {
    vector<int> li;
    li.push_back(1);
    li.push_back(1);


    Solution s;
    cout<<s.firstMissingPositive(li)<<endl;

    return 0;
}
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, secHeight = 0, area = 0;
        while(left < right) {
            #if 1
            /* 代码精简 */
            int t = height[height[left] < height[right] ? left++ : right--];
            secHeight = t > secHeight ? t : secHeight;
            area += secHeight - t;
            #else
            if(height[left] < height[right]) {
                secHeight = secHeight > height[left] ? secHeight : height[left];
                area = area + secHeight - height[left];
                left++;
            } else {
                secHeight = secHeight > height[right] ? secHeight : height[right];
                area = area + secHeight - height[right];
                right--;
            }
            #endif
        }
        return area;
    }
};

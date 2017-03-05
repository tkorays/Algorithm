/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int low = 0, high = numsSize -  1, mid;
    int* ret = (int*)malloc(sizeof(int)*2);
    while(low <= high) {
        if((nums[low] == target) && (nums[high] == target)) break;
        mid = (low+high)/2;
        if(nums[mid]<target) low = mid+1;
        else if(nums[mid]>target) high = mid-1;
        else if(nums[low]==target) high--;
        else low++;
    }
    if(low>high) {
        ret[0] = -1;
        ret[1] = -1;
    } else {
        ret[0] = low;
        ret[1] = high;
    }
    *returnSize = 2;
    return ret;
}

int main() {
    int a[] = {5,7,7,8,8,10};
    int rs;
    int* ret = searchRange(a, 6, 20, &rs);
    printf("%d,%d\n", ret[0], ret[1]);
    return 0;
}
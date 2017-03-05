/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int** ret = 0;
    int i, j, m, n, t;

    *returnSize = 0;
    if(numsSize<4) return 0;

    ret = (int**)malloc(sizeof(int*)*100000);
    /* bubble sort */
    for(i=0; i<numsSize-1; i++) {
        for(j=0; j<numsSize-i-1; j++) {
            if(nums[j] > nums[j+1]) {
                t = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = t;
            }
        }
    }

    for(i=0; i<numsSize-3; i++) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        if(nums[i]+nums[i+1]+nums[2]+nums[3] > target) break;
        if(nums[i]+nums[numsSize-3]+nums[numsSize-2]+nums[numsSize-1] < target) continue;
        for(j=i+1; j<numsSize-2; j++) {
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
            if(nums[i]+nums[j]+nums[numsSize-2]+nums[numsSize-1] < target) continue;
            m = j+1;
            n = numsSize-1;
            while(m<n) {
                t = nums[i]+nums[j]+nums[m]+nums[n];
                if(t>target) n--;
                else if(t<target) m++;
                else {
                    ret[*returnSize] = (int*)malloc(sizeof(int)*4);
                    ret[*returnSize][0] = nums[i];
                    ret[*returnSize][1] = nums[j];
                    ret[*returnSize][2] = nums[m];
                    ret[*returnSize][3] = nums[n];
                    (*returnSize)++;
                    do{m++;}while(m<n && nums[m]==nums[m-1]);
                    do{n--;}while(m<n && nums[n]==nums[n+1]);
                }
            }
        }
    }
    return ret;
}

int main() {
    int a[]={1,0,-1,0,-2,2};
    int retsize;
    fourSum(a, 6, 0, &retsize);
    return 0;
}
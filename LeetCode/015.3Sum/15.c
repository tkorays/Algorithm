/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i=0, j=0, k, m, n, t;

    *returnSize = 0;
    int** ppRet = (int**)malloc(sizeof(int*)*100000);
    /* buble sort */
    for(i=0; i<numsSize-1; i++) {
        for(j=0; j<numsSize-1-i; j++) {
            if(nums[j] > nums[j+1]) {
                k = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = k;
            }
        }
    }

    for(i=0; i<numsSize; i++) {
        k = -nums[i];
        m = i+1;
        n = numsSize-1;
        while(m<n) {
            if(nums[i] + nums[m] + nums[n]>0) n--;
            else if(nums[i] + nums[m] + nums[n]<0) m++;
            else {
                k = nums[m];
                t = nums[n];
                ppRet[*returnSize] = (int*)malloc(sizeof(int)*3);
                ppRet[*returnSize][0] = nums[i];
                ppRet[*returnSize][1] = k;
                ppRet[*returnSize][2] = t;
                (*returnSize)++;
                while(m<n && nums[m]==k) m++;
                while(m<n && nums[n]==t) n--;
            }
        }
        while((i+1)<numsSize && nums[i+1]==nums[i]) i++;
    }
    return ppRet;
}

int main() {
    int in[] = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
    //int in[] ={0,0,0,0,0,0};
    //int in[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //int in[] ={1,-1,-1,0};
    //int in[] = {-1,0,1,2,-1,-4};
    int retSize, **ret, i;
    ret = threeSum(in, sizeof(in)/sizeof(int), &retSize);
    for(i=0; i<retSize; i++) {
        printf("%d+%d+%d=0\n", ret[i][0],ret[i][1], ret[i][2]);
    }
    return 0;
}
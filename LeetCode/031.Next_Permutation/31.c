/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <stdio.h>
#include <stdlib.h>


void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 1, j = numsSize - 1, t;

    while(i > 0) {
        if(nums[i] > nums[i-1]) break;
        i--;
    }
    if(i!=0) {
        while(j>=i) {
            if(nums[j] > nums[i-1]) break;
            j--;
        }
        t = nums[i-1];
        nums[i-1] = nums[j];
        nums[j] = t;
    }
    for(j=numsSize-1; i<j; i++,j--) {
        t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
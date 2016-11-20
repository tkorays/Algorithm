/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */
#include <stdio.h>

// 1) O(n^2)
// 2) O(n) * 2 = O(n), [target - x for x in nums] 
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int* list = 0;
    for(i = 0; i < numsSize; i++)
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                list = (int*)malloc(sizeof(int)*2);
                list[0] = i;
                list[1] = j;
                return list;
            }
        }
    return 0;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9, numsSize = 4;
    int* list = twoSum(nums, numsSize, target);
    if(!list) { printf("FAIL\n"); return 0;}
    if(list[0] == 0 && list[1] == 1) { printf("PASS\n"); return 0;}
    free(list);
    return 0;
}



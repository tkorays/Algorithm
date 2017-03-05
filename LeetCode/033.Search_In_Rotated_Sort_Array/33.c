/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <stdio.h>
#include <stdlib.h>

int search_bad(int* nums, int numsSize, int target) {
    int i = 0;
    while(i<numsSize) {
        if(nums[i]==target) return i;
        i++;
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1, mid;
    while(low<high) {
        mid = (low+high)/2;
        if((nums[0]>target) ^ (nums[0]>nums[mid]) ^ (target>nums[mid]))
            low = mid + 1;
        else high = mid;
    }
    return low==high && nums[low]==target ? low : -1;
}

int main() {
    int arr[] = {4,5,6,7,0,1,2,3};
    printf("%d\n", search(arr, 8, 5));
    printf("%d\n", search(arr, 8, 7));
    printf("%d\n", search(arr, 8, 0));
    printf("%d\n", search(arr, 8, 1));
    return 0;
}
/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1, mid;
    while(low<=high) {
        mid = (low+high)/2;
        if(nums[mid]>target) high = mid - 1;
        else if(nums[mid]<target) low = mid + 1;
        else return mid;
    }
    return low;
}

int main() {
    int ar[] = {1,3,5,6};
    printf("%d\n", searchInsert(ar, 4, 5));
    printf("%d\n", searchInsert(ar, 4, 2));
    printf("%d\n", searchInsert(ar, 4, 7));
    printf("%d\n", searchInsert(ar, 4, 0));
    return 0;
}
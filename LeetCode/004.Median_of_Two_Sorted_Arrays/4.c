/*
 * There are two sorted arrays ns (2 + 3)/2 = 2.5
 * ums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 * Example 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */
#include <stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {      
    int i1 = (nums1Size + nums2Size) / 2 - 1;
    int i2 = (nums1Size + nums2Size) % 2 == 0 ? i1 : (i1 + 1);
    int i = nums1Size, j = nums2Size;
    int a, b;
    int cnt = 1;
    while(1) {
        if(i == 0 || j == 0 || (i + j) == i1 || (i + j) == i2) break;
        a = nums1Size << cnt;
        b = nums2Size << cnt;
        if(nums1[i - a - 1] >= nums2[j - b - 1]) {
            i -= a;
        } else {
            j -= b;
        }
        cnt++;
    }
    if(i == 0) {
        return ((double)nums2[i2] + (double)nums2[i2]) / 2;
    } else if(j == 0){
        return ((double)nums1[i1] + (double)nums1[i1]) / 2;
    } else if(i1 == i2) {
    }
}

int main() {
    int a[] = {1, 3};
    int b[] = {2};
    double r = findMedianSortedArrays(a, 2, b, 1);
    printf("result: %f\n", r);
    return 0;
}

/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/
#include <stdlib.h>

int g_is_sorted = 0;



int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int i, j, t;
    int d[100];
    int** ret = (int**)malloc(sizeof(int*)*100000);
    if(g_is_sorted==0) {
        for(i=0; i<candidatesSize-1; i++) {
            for(j=0; j<candidatesSize-1-i; j++) {
                if(candidates[j] > candidates[j+1]) {
                    t = candidates[j];
                    candidates[j] = candidates[j+1];
                    candidates[j+1] = t;
                }
            }
        }
        g_is_sorted = 1;
    }

    if(candidates[0] > target) return 0;
    for(i=0; i<candidatesSize; i++) {
        if(candidates[i] < target) combinationSum(candidates, candidatesSize, target-candidates[i], columnSizes, returnSize);
        else if(candidates[i] > target) return 0;
        else XXXX;
    }
}
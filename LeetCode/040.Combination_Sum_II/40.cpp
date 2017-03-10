/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> candidate;
        combinationSum21(candidates, target, res, candidate, 0);
        return res;
    }
private: 
    void combinationSum21(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& candidate, int start) {
        if(0==target) {
            res.push_back(candidate);
            return;
        }
        for(int i=start, sz=candidates.size(); (i<sz)&&(candidates[i] <= target); i++) {
            if(i>start) if(candidates[i]==candidates[i-1]) continue;
            candidate.push_back(candidates[i]);
            combinationSum21(candidates, target-candidates[i], res, candidate, i+1);
            candidate.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(6);
    v.push_back(1);
    v.push_back(5);

    vector<vector<int> > r = s.combinationSum2(v, 8);
    return 0;
}
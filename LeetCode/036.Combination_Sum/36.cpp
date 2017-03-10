
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> item;
        combinationSum1(candidates, ret, item, target, 0);
        return ret;
    }
    void combinationSum1(vector<int>& candidates, vector<vector<int> >& ret, vector<int>& item, int target, int start) {
        if(0==target) {
            ret.push_back(item);
            return;
        }
        for(int i=start, sz=candidates.size(); (i<sz) && (candidates[i] <= target); i++) {
            item.push_back(candidates[i]);
            combinationSum1(candidates, ret, item, target-candidates[i],i);
            item.pop_back();
        }
    }
};
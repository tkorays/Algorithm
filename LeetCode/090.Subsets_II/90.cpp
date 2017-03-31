class Solution {
public:
    void cao(vector<vector<int>>& ret, vector<int>& s, vector<int>& r, int b) {
        ret.push_back(s);
        for (int i = b; i < r.size() && b < r.size(); i++) {
            if (i > b && i > 0) if (r[i] == r[i - 1]) continue;
            s.push_back(r[i]);
            cao(ret, s, r, i+1);
            s.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> e;
        cao(ret, e, nums, 0);
        return ret;
    }
};
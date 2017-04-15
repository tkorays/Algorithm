#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& num, int start, int end) {
        TreeNode* r = NULL;
        int mid;
        if(start <= end) {
            mid = (start + end + 1) / 2;
            r = new TreeNode(num[mid]);
            r->left = build(num, start, mid -1);
            r->right = build(num, mid + 1, end);
        }
        return r;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    vector<vector<int> > result;
    bool hasPathSum(TreeNode* root, int sum, vector<int> path) {
        if(!root) return false;
        path.push_back(root->val);
        if(root->val == sum && !root->left && !root->right) {
            result.push_back(path);
        }
        return hasPathSum(root->left, sum - root->val, path) || hasPathSum(root->right, sum - root->val, path);
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        hasPathSum(root, sum, path);
        return result;
    }
};

/* 迭代，先序遍历，或者使用Morris遍历 */
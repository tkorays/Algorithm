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
    vector<int> lr(queue<TreeNode*>& q1, queue<TreeNode*>& q2) {
        vector<int> r;
        while (!q1.empty()) {
            TreeNode* n = q1.front();
            q1.pop();
            if (n->left) q2.push(n->left);
            if (n->right) q2.push(n->right);
            r.push_back(n->val);
        }
        return r;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        vector<vector<int>> r;
        if (!root) return r;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            if (q2.empty()) r.push_back(lr(q1, q2));
            else if (q1.empty()) r.push_back(lr(q2, q1));
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
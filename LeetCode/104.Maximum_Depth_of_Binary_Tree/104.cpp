#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l1 = 0, l2 = 0;
        if(root->left) l1 = maxDepth(root->left);
        if(root->right) l2 = maxDepth(root->right);
        return max(l1, l2) + 1;
    }
};
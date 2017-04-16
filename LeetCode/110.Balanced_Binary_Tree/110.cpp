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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l1 = 0, l2 = 0;
        if(root->left) l1 = maxDepth(root->left);
        if(root->right) l2 = maxDepth(root->right);
        if(abs(l1 - l2) > 1 || l1 == -213 || l2 == -213) return -213;
        return max(l1, l2) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return maxDepth(root) != -213;
    }
};